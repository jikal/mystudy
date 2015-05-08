#ifndef _LINK_H_
#define _LINK_H_
#include<stdio.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<errno.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>
#include<fcntl.h>
#include<semaphore.h>
typedef struct parket{
	int data_type;
	char name[32];
	char pwd[32];
	char cmd[32];
	char cmd_return[1024];
	char usr_return[512];
	int hasbuf_next;
	int flag;
}Parket;
typedef struct use_t{
	int state;
	char name[32];//用户名
	char pwd[32];//密码
	struct use_t *next;
	struct use_t *prev;//指针
}Node;

typedef struct client_info                           
{
	char name[32];              //客户的名称
	int clientfd;                   //该客户对应fd
	char tm[32];
	char clientip[64];
	int state;                
	struct client_info *next;
	struct client_info *prev;
}clientinfo;

typedef struct daily_record{
	char name[32];
	char client_ip[24];//客户端的ip地址
	char cmd[512];//发送的命令
	struct daily_record *next;
	struct daily_record *prev;

}Daily;

typedef struct cache{
	char clientip[64];
	int fd;
}Cache;
//typedef struct 
extern Node *head;
extern Daily *dhead;
extern clientinfo *ihead;
extern Node *my;
#define TYPE_LOGIN 2 //登陆数据包
#define TYPE_REG 1 //注册数据包
#define TYPE_HEART 3 //心跳数据包
#define TYPE_CMD 4 //命令数据包
#define TYPE_EXIT 5 //退出
extern Node *CreatNode(void);
extern int InsertHead(Node *newNode);
extern int ReadList(const char *pathname);
extern int SaveList(const char *pathname);
extern int InsertdHead(Daily *newDaily);
extern int InsertiHead(clientinfo *newcilentinfo);
extern int savedaliyList(const char *pathname);
extern void DestrayList(Node *head);
extern void DestraydailyList(Daily *dhead);
extern void DestrayinfoList(clientinfo *head);
#endif

