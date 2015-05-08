#include "server_model.h"
#include "server_control.h"
#include <time.h>


//服务器端判断注册是否成功
int check_reg_success(Proc *proc,Msg *msg){

	time_t t = time(NULL);
	struct tm *ctime = localtime(&t);

	if(msg == NULL || proc == NULL){
		printf("error!\n");
		return -1;
	}
	
	Proc *pack = proc;
	Usr *usr_head = msg->usr_head;
	Daily * daily_head = msg->daily_head;
	
	Daily *newDaily = (Daily *)calloc(1,sizeof(Daily));
	strcpy(newDaily->client_ip,msg->client_ip);
	newDaily->type = pack->type;
	strcpy(newDaily->cmd,"正在注册...");
	newDaily->time = ctime;
	
	if(insert_Daily(daily_head,newDaily) == -1){
	
		printf("insertDaily error!\n");
		free(newDaily);
		newDaily = NULL;
		return -1;
	}
	
	sem_wait(&sem1);
	Usr *cur = usr_head->next;
	while(cur != NULL){
		 	
		if(strcmp(pack->name,cur->name) == 0){
		
			strcpy(pack->errinfo,"请重新选择用户名！\n");
			return -1;
		}
		cur = cur->next;
	}
	sem_post(&sem1);
	
	Usr *newUsr = (Usr *)calloc(1,sizeof(Usr));
	strcpy(newUsr->name,pack->name);
	strcpy(newUsr->pwd,pack->pwd);
	
	if(insert_Usr(msg->usr_head,newUsr) == -1){
	
		printf("insertUsr error!\n");
		free(newUsr);
		newUsr = NULL;
		return -1;
	}
	sem_wait(&sem2);
	strcpy(newDaily->cmd,"注册成功...");
	sem_post(&sem2);
	
	return 0;
}

//服务器端判断登录是否成功
int check_Log_Success(Proc *proc,Msg *msg){
	
	time_t t = time(NULL);
	struct tm *ctime = localtime(&t);
	
	if(msg == NULL || proc == NULL){
		printf("error!\n");
		return -1;
	}

	Proc *pack = proc;
	Usr *usr_head = msg->usr_head;
	Daily * daily_head = msg->daily_head;
	
	Daily *newDaily = (Daily *)calloc(1,sizeof(Daily));
	strcpy(newDaily->client_ip,msg->client_ip);
	newDaily->type = pack->type;
	strcpy(newDaily->cmd,"正在登录...");
	newDaily->time = ctime;
	
	if(insert_Daily(daily_head,newDaily) == -1){
	
		printf("insertDaily error!\n");
		free(newDaily);
		newDaily = NULL;
		return -1;
	}
	
	sem_wait(&sem1);
	Usr *cur = usr_head->next;
	while(cur != NULL){
	
		if(strcmp(cur->name,pack->name) == 0 && \
			strcmp(cur->pwd,pack->pwd) == 0){
			
			return 0;
		}
		cur = cur->next;
	}
	sem_post(&sem1);
	
	strcpy(pack->errinfo,"用户名或密码错误！\n");
	
	sem_wait(&sem2);
	strcpy(newDaily->cmd,"注册成功...");
	sem_post(&sem2);
	
	return -1;
}

//服务器端处理客户端的命令
int check_Client_Cmd(Proc *proc,Msg *msg){
	
	if(msg == NULL || proc == NULL){
		printf("error!\n");
		return -1;
	}
	Proc *pack = proc;
	
	int fds[2];
	int cnt = 0;
	int count = 1;
	pid_t pid;
	
	pipe(fds);
	pid = fork();
	
	if(pid == 0){
		close(fds[0]);
		 
		dup2(fds[1],1);
		
		execl("/bin/sh","/bin/sh","-c",pack->cmd,NULL);
		close(fds[1]);
	
	}else if(pid > 0){
		close(fds[1]);
		 
		while(1){
			Proc newproc = {};
				
			cnt = read(fds[0],newproc.content,sizeof(newproc.content));
			
			if(cnt == 0){
				newproc.has_next = 0;
				write(msg->fd,&newproc,sizeof(Proc));
				break;
			
			}else if(cnt == -1){
			
				if(errno == EINTR)
					break;
				else
					continue;
			}else{	
				printf("-----------------\n");
				printf("正在发送命令包%d...\n",count++);
				newproc.has_next = 1;
				write(msg->fd,&newproc,sizeof(Proc));
			}
		}
		
		close(fds[0]);
		wait(NULL);
	}
		 
	return 0;
}

//服务器端接收客户端发送的心跳包
void check_client_heart(Proc *proc){
	
	 
}

//创建usr链表头节点
Usr *create_usr_head(void){
	Usr *head = (Usr *)calloc(1,sizeof(Usr));
	if(head == NULL){
		return NULL;
	}else{
		head->next = NULL;
	}
	return head;

}

//创建daily链表头节点
Daily *create_daily_head(void){
	Daily *head = (Daily *)calloc(1,sizeof(Daily));
	if(head == NULL){
		return NULL;
	}else{
		head->next = NULL;
	}
	return head;

}

//头插法插入Usr节点
int insert_Usr(Usr *head,Usr *newUsr){
	if(head == NULL || newUsr == NULL){
		return -1;
	}
	sem_wait(&sem1);
	
	newUsr->next = head->next;
	head->next = newUsr;
	
	sem_post(&sem1);
	return 0;
}

//头插法插入Daily节点
int insert_Daily(Daily *head,Daily *newDaily){

	if(head == NULL || newDaily == NULL){
		return -1;
	}
	sem_wait(&sem2);
	
	newDaily->next = head->next;
	head->next = newDaily;
	
	sem_post(&sem2);
	return 0;
}

