#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/file.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/* 
 * 福瑞哈哥改編自tinyproxy
 */

#define MAXLISTEN		1024		/* 最大監聽數，listen函數用 */
#define MAXCLIENTS		64			/* 最大服務進程數 */
#define MAXSERVICES		128			/* 每一個進程最大服務用戶數，定期更新進程組，防止錯誤積累 */
#define STARTSERVERS	32			/* 初始啟動服務進程數 */
#define MAXSPARESERVERS	32			/* 最大空閒服務進程數 */
#define MINSPARESERVERS	8			/* 最小空閒服務進程數 */

#define PORT 			8000		/* 監聽端口號 */

/* 全局變量區 */
int listenfd; 				/* 服務socket */
int received_sighup = 0;	/* 收到hug信號標誌 */
int quit = 0;				/* 退出標誌 */

#define SERVER_COUNT_LOCK()   _child_lock_wait()
#define SERVER_COUNT_UNLOCK() _child_lock_release()

/* 共享變量鎖 */
static struct flock lock_it, unlock_it;
static int lock_fd = -1;

enum child_status_t { T_EMPTY, T_WAITING, T_CONNECTED };

struct child_s {
	pid_t tid;
	unsigned int connects;
	enum child_status_t status;
};

/* 
 * 子進程數組－位於共享內存區 
 */
static struct child_s *child_ptr;

/*
 * 正等待用戶連接的服務進程數
 */
static unsigned int* servers_waiting;

/*
 * 分配一塊共享內存。
 */
static void*
malloc_shared_memory( size_t size )
{
	int fd;
	void* ptr;
	char buffer[32];

	static char* shared_file = "/tmp/mps.shared.XXXXXX";

	assert( size > 0 );

	strncpy( buffer, shared_file, sizeof(buffer) );

	if ( (fd = mkstemp(buffer)) == -1 )
		return (void *) MAP_FAILED;
	unlink(buffer);

	if (ftruncate(fd, size) == -1)
		return (void *) MAP_FAILED;
	ptr = mmap( NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0 );

	return ptr;
}

/*
 * 分配一塊共享內存，並清0。
 */
static void*
calloc_shared_memory( size_t nmemb, size_t size )
{
	void* ptr;
	long length;

	assert( nmemb > 0 );
	assert( size > 0 );

	length = nmemb * size;

	ptr = malloc_shared_memory( length );
	if ( ptr == MAP_FAILED )
		return ptr;

	memset( ptr, 0, length );

	return ptr;
}

static void
_child_lock_init(void)
{
	char lock_file[] = "/tmp/mps.servers.lock.XXXXXX";

	lock_fd = mkstemp(lock_file);
	unlink(lock_file);

	lock_it.l_type = F_WRLCK;
	lock_it.l_whence = SEEK_SET;
	lock_it.l_start = 0;
	lock_it.l_len = 0;

	unlock_it.l_type = F_UNLCK;
	unlock_it.l_whence = SEEK_SET;
	unlock_it.l_start = 0;
	unlock_it.l_len = 0;
}

static void
_child_lock_wait(void)
{
	int rc;

	while ( (rc = fcntl( lock_fd, F_SETLKW, &lock_it )) < 0 ) {
		if (errno == EINTR)
			continue;
		else
			return;
	}
}

static void
_child_lock_release(void)
{
	if (fcntl(lock_fd, F_SETLKW, &unlock_it) < 0)
		return;
}

#define SERVER_INC() do { \
    SERVER_COUNT_LOCK(); \
    ++(*servers_waiting); \
    SERVER_COUNT_UNLOCK(); \
} while (0)

#define SERVER_DEC() do { \
    SERVER_COUNT_LOCK(); \
    assert(*servers_waiting > 0); \
    --(*servers_waiting); \
    SERVER_COUNT_UNLOCK(); \
} while (0)

/*
 * 創建監聽socket
 */
static void 
start_listen_socket( unsigned short port )
{
	int sockfd;
	int on = 1;
	struct sockaddr_in addr;//定义一个socksddr_in结构体
	
	sockfd = socket( AF_INET, SOCK_STREAM, 0 );
	setsockopt( sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on) );
	
	memset( &addr, 0, sizeof(addr) );
	addr.sin_family = AF_INET;//地址族，主机字节序
	addr.sin_port = htons(port);//响应端口号
	/*
	 * 需要指定到實際的地址上
	 */
	addr.sin_addr.s_addr = inet_addr( "0.0.0.0" );//响应
	
	if ( bind( sockfd, (struct sockaddr *) &addr, sizeof (addr) ) < 0 ) {
		fprintf( stderr, "Unable to bind listening socket because of %s\n", 
				 strerror(errno) );
		exit(-1);
	}//
	
	if ( listen( sockfd, MAXLISTEN ) < 0 ) {
		fprintf( stderr, "Unable to start listening socket because of %s\n",
			     strerror(errno) );
		exit(-1);
	}
	
	listenfd = sockfd;
}

void
close_listen_socket(void)
{
	close( listenfd );
}

/*
 * 在這個函數中，寫下對客戶請求的處理邏輯。
 * 處理完成後在退出這個函數時，關閉connfd。
 */
void 
handle_connection( int connfd );

/*
 * 子進程主循環
 */
static void
child_main( struct child_s* ptr )
{
	int connfd;
	struct sockaddr *cliaddr;
	socklen_t clilen;
	
	clilen = sizeof( struct sockaddr );
	cliaddr = (struct sockaddr*) malloc( clilen );
	if ( !cliaddr ) {
		fprintf( stderr,
			     "Could not allocate memory for child address." );
		exit(0);
	}

	ptr->connects = 0;

	while ( !quit ) {
		ptr->status = T_WAITING;

		connfd = accept( listenfd, cliaddr, &clilen );

		/*
		 * 保沒有錯誤發生
		 */
		if ( connfd < 0 ) {
			fprintf( stderr, 
					 "Accept returned an error (%s) ... retrying.", 
					 strerror(errno) );
			continue;
		}

		ptr->status = T_CONNECTED;

		SERVER_DEC();

		handle_connection( connfd );
		ptr->connects++;

		if ( ptr->connects == MAXSERVICES ) {
			fprintf( stderr,
					 "Child has reached MaxRequestsPerChild (%u). Killing child.\n",
					 ptr->connects );
			break;
		}

		SERVER_COUNT_LOCK();
		if ( *servers_waiting > MAXSPARESERVERS ) {
			/*
			 * 有太多空閒服務進程，退出自己
			 */
			fprintf( stderr,
					 "Waiting servers (%d) exceeds MaxSpareServers (%d). Killing child.\n",
					 *servers_waiting, MAXSPARESERVERS );
			SERVER_COUNT_UNLOCK();

			break;
		} else {
			SERVER_COUNT_UNLOCK();
		}

		SERVER_INC();
	}

	ptr->status = T_EMPTY;

	free( cliaddr );
	exit(0);
}

/*
 * Fork一個子進程並啟動child_main()函數（子進程主循環）
 */
static int
child_make( struct child_s* ptr )
{
	pid_t pid;

	if ((pid = fork()) != 0)
		return pid;	/* 父進程 */

	/*
	 * 重設子進程的信號處理函數
	 */
	signal( SIGCHLD, SIG_DFL );
	signal( SIGTERM, SIG_DFL );
	signal( SIGHUP, SIG_DFL );

	child_main(ptr); /* 不會返回 */

	return -1;
}

int child_pool_create(void)
{
	/* sleep(10); */
	child_ptr = (struct child_s*) 
		calloc_shared_memory( MAXCLIENTS, 
							  sizeof(struct child_s) );
	if ( child_ptr == MAP_FAILED ) {
		fprintf( stderr, "Could not allocate shared memory for children.\n" );
		return -1;
	}

	servers_waiting = (unsigned int*) 
		malloc_shared_memory( sizeof(unsigned int) );
	if ( servers_waiting == MAP_FAILED ) {
		fprintf( stderr, "Could not allocate shared memory for child counting.\n" );
		return -1;
	}
	*servers_waiting = 0;
	
	/* 在操作servers_waiting變量之前， 創建加鎖文件 */
	_child_lock_init();
	
	int i;
	/* 初始化子進程共享數組 */
	for ( i = 0; i < MAXCLIENTS; i++ ) {
		child_ptr[i].status = T_EMPTY;
		child_ptr[i].connects = 0;
	}

	/* fork子進程 */
	for ( i = 0; i < STARTSERVERS; i++ ) {
		child_ptr[i].status = T_WAITING;
		child_ptr[i].tid = child_make( &child_ptr[i] );

		if ( child_ptr[i].tid < 0 ) {
			fprintf( stderr, 
				     "Could not create child number %d of %d\n",
				     i, STARTSERVERS );
			return -1;
		} else {
			fprintf( stderr, 
				    "Creating child number %d of %d ...\n",
				    i + 1, STARTSERVERS );

			SERVER_INC();
		}
	}
	
	return 0;
}

/*
 * 刪除所有服務進程
 */
void
kill_children(void)
{
	unsigned int i;
	
	for ( i = 0; i < MAXCLIENTS; i++ ) {
		if ( child_ptr[i].status != T_EMPTY )
			kill( child_ptr[i].tid, SIGTERM );
	}
}

/*
 * 監控進程主循環，它負責把服務進程的數量維持在一個合適的數量上。
 */
void 
child_main_loop(void)
{
	unsigned int i;

	while (1) {
		if ( quit ) 
			return;

		/* 如果空閒服務進程數不足，則創建一些 */
		SERVER_COUNT_LOCK();
		if ( *servers_waiting < MINSPARESERVERS ) {
			fprintf( stderr,
					 "Waiting servers (%d) is less than MinSpareServers (%d). Creating new child.",
					 *servers_waiting, MINSPARESERVERS );

			SERVER_COUNT_UNLOCK();

			for ( i = 0; i < MAXCLIENTS; i++ ) {
				if ( child_ptr[i].status == T_EMPTY ) {
					child_ptr[i].status = T_WAITING;
					child_ptr[i].tid = child_make( &child_ptr[i] );
					if ( child_ptr[i].tid < 0 ) {
						fprintf( stderr, "Could not create child" );

						child_ptr[i].status = T_EMPTY;
						break;
					}

					SERVER_INC();

					break;
				}
			}
		} else {
			SERVER_COUNT_UNLOCK();
		}

		sleep(5);

		if ( received_sighup ) {
			/* 在收到hup信號後，可作一些維護工作，比如更新備份日志文件等 */
			received_sighup = 0;
		}
	}
}

/*
 * 處理信號
 */
void
takesig( int sig )
{
	pid_t pid;
	int status;

	switch (sig) {
	case SIGHUP:
		received_sighup = 1;
		break;

	case SIGTERM:
		quit = 1;
		break;

	case SIGCHLD:
		while ( (pid = waitpid(-1, &status, WNOHANG)) > 0 ) 
			;
		break;
	}

	return;
}

int 
main( int argc, char ** argv )
{
	int godaemon = 1; 					/* 是否轉為deamon模式 */
	unsigned short port = PORT; 		/* 服務端口號 */

	assert( MINSPARESERVERS <= MAXSPARESERVERS );
	assert( STARTSERVERS <= MAXCLIENTS );
	assert( MAXCLIENTS <= MAXLISTEN );
	
	if ( godaemon == 1 ) {
		daemon(1, 1);
	}
	
	/* 啟動服務socket */
	start_listen_socket( port ); 
	
	signal( SIGPIPE, SIG_IGN );
	
	/* 創建服務進程組 */
	child_pool_create();

	/* 
	 * 下面這些信號處理函數只有監控進程才有用
	 */
	signal( SIGCHLD, takesig );
	signal( SIGTERM, takesig );
	signal( SIGHUP, takesig );
	
	/* 開始監控工作 */
	child_main_loop();
	
	/* 退出前，殺掉服務進程組 */
	kill_children();
	
	/* 關閉服務socket */
	close_listen_socket();
	
	exit(0);
	return 0;
}

/*
 * 在這個函數中，寫下對客戶請求的處理邏輯。
 * 處理完成後在退出這個函數時，關閉connfd。
 * 這只是一個示例！
 */
void 
handle_connection( int connfd )
{
	char buf[128] = {};
	sprintf( buf, "%u: ", (unsigned int) getpid() );
	int len = strlen(buf);
	read( connfd, buf + len, sizeof(buf) - len - 1 );
	len = strlen(buf);
	write( connfd, buf, len );
	
	close( connfd );
}
