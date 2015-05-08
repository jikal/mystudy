#ifndef _SERVER_CONTROL_H_
#define _SERVER_CONTROL_H_

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/sem.h>
#include <semaphore.h>

#define SIZE 1024
#define PORT 3333

#define TYPE_LOG 0
#define TYPE_REG 1
#define TYPE_MSG 2
#define TYPE_HEART 3
#define TYPE_CMD 4
#define TYPE_EXIT 5
#define TYPE_ERR 6

typedef struct usr{
	
	char name[24];
	char pwd[24];
	struct usr *next; 
}Usr;

typedef struct protocal{

	int type;
	char name[24];
	char pwd[24];
	char cmd[24];
	char content[1024];
	char errinfo[32];
	int has_next;//是否有下一个包

}Proc;

typedef struct daily{
	struct tm *time;//通话时间
	char client_ip[24];//客户端的ip地址
	char cmd[24];//发送的命令
	int type;//数据包的类型
	char sendmsg[1024];//发送的消息
	struct daily *next;
	
}Daily;

typedef struct msg{

	Usr *usr_head;
	Daily *daily_head;
	int fd;
	char client_ip[24];//客户端的ip地址
	
}Msg;


extern void* proc_echo(void  *msg);

extern Usr *usr_head;
extern Daily *daily_head;
extern time_t start;

extern sem_t sem1;
extern sem_t sem2;

#endif
