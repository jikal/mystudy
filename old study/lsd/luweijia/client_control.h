#ifndef _CLIENT_CONTROL_H_
#define _CLIENT_CONTROL_H_

#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <pthread.h>

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
	
	Usr *usr_head;//用户链表的头节点
	Daily *daily_head;//日志链表的头节点
	int fd;//套接字id
	char client_ip[24];//客户端的ip地址
	
}Msg;

//发送心跳包
extern void *send_heart(void *sockfd);

//处理信号函数
extern void sig_handle(int sig);

//与服务器端进行通信
extern void proc_echo(int fd);

//客户端登录控制界面
extern void client_log_control(int fd);

extern char my[24];
extern int sockfd;

#endif
