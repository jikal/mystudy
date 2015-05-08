//实现功能的函数集合
#include "model.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "view.h"
#include<unistd.h>
#include<errno.h>
#include"list.h"
void proc_echoc(int fd)
{
	
	int ch=0;
	while(1){
	printf("1.注册2.登录0.返回上级\n");
	printf("请输入选择:\n");
	scanf("%d",&ch);
	
	switch (ch)
	{
		case 1:
		reg(fd);
		break;
		
		case 2:
		//登录函数
		log_inc(fd);
		printf("1.聊天2.查看在线用户0.注销用户");
		cli_handle(fd);//客户操作函数
		
		break;
		case 0:
		//将推出的信息发给服务器，让服务器记录推出时间。
		close(fd);
		printf("程序已退出\n");
		exit(0);                                        //正确退出
		break;
		default:
		printf("你的输入有误\n");
		break;
		}
		//write(fd,&senmsg,sizeof(Cms));
			
}

}
//客户端注册函数
void reg(int fd)
{	
	int done=-1;	
	Cli senmsg={0};//发送的消息,同时也是返回的消息
	//Cli recmsg={0};//服务器返回的消息
	char name[100];
	char pass[100];
	char password_sure[100];
	senmsg.DATA_TYPE=TYPE_REG;
	printf("输入用户名:");
	scanf("%s",name);
	do
	{
	printf("请输入密码：");
	scanf("%s",pass);
	printf("请重新输入一次密码:");	
	scanf("%s",password_sure);
	
	if(strcmp(pass,password_sure) == 0)
	{
		printf("密码输入正确");
		done = 1;
	}		
	else
	{
		printf("密码输入不正确，请重新输入");
		done = -1;
	}
	}while(done < 0);


	strcpy(senmsg.name,name);
	strcpy(senmsg.pass,pass);
	printf("向服务器发送注册请求...\n");
	write(fd,&senmsg,sizeof(Cli));
	printf("等待服务器应答...\n");
	read(fd,&senmsg,sizeof(Cli));
	//if()
	printf("您注册的用户名为：%s 您注册的密码为：%s\n",senmsg.name,senmsg.pass);
	
}
//客户端登录函数
void log_inc(int fd)
{
		
	Cli senmsg={0};//发送的消息
	char name[100];
	char pass[100];
	
	senmsg.DATA_TYPE=TYPE_LOGIN;
	write(fd,&senmsg,sizeof(Cli));
	printf("输入用户名:");
	scanf("%s",name);
	printf("请输入密码：");
	scanf("%s",pass);
	strcpy(senmsg.name,name);
	strcpy(senmsg.pass,pass);
	//获取客户端地址函数
	//记录登录时间函数
	printf("向服务器发送登录请求...\n");
	write(fd,&senmsg,sizeof(Cli));
	printf("等待服务器应答...\n");
	read(fd,&senmsg,sizeof(Cli));
	printf("%s 登录成功\n",senmsg.name);
}
//客户端登录后可执行的操作函数
void cli_handle(int fd){
int ch=0;
printf("1.聊天2.查看在线3.命令管理0.返回上级");
printf("请输入选择：\n");
scanf("%d",&ch);
switch(ch)
		{
			//case 1:chat(fd);
			//break;
			//case 2:check all online
			//break;
			case 3:cmd(fd);
			
			break;
			case 0:
			return;
			break;
			
			default:
			break;

		}

}
//客户端进行命令操作的函数
void cmd(int fd){
	Cli senmsg={0};//发送的消息
	senmsg.DATA_TYPE=TYPE_CMD;
	char cmd[10];
	printf("输入命令：");
	scanf("%s",cmd);
	strcpy(senmsg.cmd,cmd);
	printf("向服务器发送命令...\n");
	write(fd,&senmsg,sizeof(Cli));
	printf("等待服务器应答...\n");
	read(fd,&senmsg,sizeof(Cli));
	printf("%s",senmsg.CMD_RET);
	
}

//客户端进行聊天函数
void chat(int fd)
{

}
