//链表操作
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "model.h"
#include "view.h"
#include<time.h>
#include"list.h"
//新建头节点

Node *CreatHead(void){
	Node *head=(Node *)calloc(1,sizeof(Node));
	if(NULL == head){
		return NULL;
	}else{
		//初始化双向循环链表
		head->next=head;
		head->prev=head;
	}
	return head;
}
//新建节点
Node *CreatNode(Cli* senmsg){
	 Node* newNode = (Node *)calloc(1,sizeof(Node));
	if(newNode == NULL) return NULL;
	strcpy(newNode->name,senmsg->name);
	strcpy(newNode->pass,senmsg->pass);
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;	
}
////管理员添加客户
int reg_cli(Node *head,Cli* add)   
{	
	Node *cur=NULL;
	cur=CreatNode(add);
	InsertTail(head,cur);//尾插
	return 1;
	
}
//新建日志节点
Dai *CreatDaiNode(Cli* senmsg){
	Dai *newNode = (Cli *)calloc(1,sizeof(Cli));
	if(newNode == NULL) return NULL;
	strcpy(newNode->name,senmsg->name);
	strcpy(newNode->IP,senmsg->IP);
	strcpy(newNode->logtime,senmsg->logtime);
	//strcpy(newNode->quitime,senmsg->quitime);
	
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;	
}
//将信息写入日志链表
int add_dai(Dai *head,Cli* add)   
{	
	Node *cur=NULL;
	cur=CreatDaiNode(add);
	InsertTail(head,cur);//尾插
	return 1;
	
}
/*函数功能：链表写入文件
函数参数：head_头节点 pathname_文件名
返回值  ：0_成功 -1_失败*/

int SaveList(Node *head,const char *pathname){
	if(head==NULL || pathname==NULL)
		return -1;
	FILE *fp=fopen(pathname,"wb");//*(pathname+0)='a';二进制写入
	if(fp==NULL) return -1;
	Node *cur=head->next;
	while(cur!=head){
		if(1!=fwrite(cur,sizeof(Node),1,fp)){
			return -1;
		}
		cur=cur->next;
	}
	fclose(fp);
	return 0;
}
//头插
int InsertHead(Node *head,Node *newNode){
	if(head==NULL || newNode==NULL)
		return -1;
	newNode->prev=head;
	newNode->next=head->next;
	head->next->prev=newNode;
	head->next=newNode;
	return 0;
}
//尾插
int InsertTail(Node *head,Node *newNode){
	if(head==NULL || newNode==NULL)
		return -1;
	newNode->prev=head->prev; 
	newNode->next=head;
	head->prev->next=newNode;
	head->prev=newNode;;
	return 0;
}

//容错函数，判断传入的用户名返回1表示找到相同的，0表示没有
int rongCuo(Node *head,Cli *e,int (*f)(Node *,Cli*))		
{
	Node *cur=head->next;
	while(cur!=head)
	{
		if(0==((*f)(cur,e)))
		break;
		cur=cur->next;
			}
	if(cur==head)
	{
		return 0;
			}
	else
	{
		return 1;
			}
}

//按姓名查找
int findByName(Node *p1,Cli *p2){
	return strcmp(p1->name,p2->name);
}
//按用户名和密码查找，回调函数，找到返回0
int comp(Node *p1,Cli *p2)
{
	if(strcmp(p1->name,p2->name)==0&&strcmp(p1->pass,p2->pass)==0)
	return 0;
	else 
	return 1;
}

/*
	函数功能：文件中读取链表
	函数参数：head_头节点 pathname_文件名
	返回值  ：0_成功 -1_失败
*/
int ReadList(Node *head,const char *pathname){
	if(head==NULL || pathname==NULL)
		return -1;
	FILE *fp=fopen(pathname,"rb");//二进制读取
	if(fp==NULL)
		return -1;
	Node *newNode = (Node *)calloc(1,sizeof(Node));
	if(1!=fread(newNode,sizeof(Node),1,fp)){
		free(newNode);			
		return -1;
	}
	newNode->prev=NULL;
	newNode->next=NULL;
	InsertHead(head,newNode);	
	if(newNode==NULL) return -1;
	while(!feof(fp)){
		newNode = (Node *)calloc(1,sizeof(Node));
		if(newNode==NULL) return -1;
		if(1!=fread(newNode,sizeof(Node),1,fp)){
			free(newNode);			
			return -1;
		}
		newNode->prev=NULL;
		newNode->next=NULL;
		InsertHead(head,newNode);	
	}
	fclose(fp);
	return 0;
}

//遍历链表，和传进 的进行对比,就是登录过程，1成功 0失败
int log_in(Node *head,Cli *e,int (*f)(Node *,Cli *)){
	if(head==NULL || e==NULL) return 0;
	Node *cur=head->next;
	while(cur!=head){
		if(((*f)(cur,e))==0){
			printf("%s登录成功！",cur->name);
			return 1;
		}else cur=cur->next;
	}
	return 0;
}

//
