#ifndef _LIST_H__
#define _LIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/socket.h>  
#include<netinet/in.h>      //struct sockaddr_in...
#include<arpa/inet.h>       //inet_ntoa...
#include<string.h>
#include<pthread.h>
#include<unistd.h>        
#include"model.h"


//服务器储存的客户 信息链表
typedef struct Client
{
int DATA_TYPE;//消息类型
int size;//数据的长度
char name[100];//实际传输的数据
char pass[100];
char CMD[100];
char CMD_RET[1024];//返回的命令
struct Client* prev;
struct Client* next;
}Node;

extern Node *CreatHead(void);
extern Node *CreatNode(Cli* senmsg);
extern int reg_cli(Node *Stu_head,Cli* add) ;
extern int InsertTail(Node *head,Node *newNode);
extern int InsertHead(Node *head,Node *newNode);
extern int comp(Node *p1,Cli *p2);
extern int log_in(Node *head,Cli *e,int (*f)(Node *,Cli *));
extern int ReadList(Node *head,const char *pathname);
extern int SaveList(Node *head,const char *pathname);
extern int rongCuo(Node *head,Cli *e,int (*f)(Node *,Cli *));
extern int findByName(Node *p1,Cli *p2);
#endif





