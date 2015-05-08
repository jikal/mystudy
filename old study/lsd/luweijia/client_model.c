#include "client_model.h"
#include "client_control.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void myfflush(void){
	int ch=0;
	while(((ch=getchar()))!='\n' && (ch != EOF));
}

void push_continue(void){
	printf("按回车继续...\n");
	getchar();
}

//注册
void client_reg(int fd){
	int cnt = 0;
	int count = 0;
	
	Proc proc = {};
	
	printf("用户名：");
	scanf("%s",proc.name);
	getchar();
	printf("密码：");
	scanf("%s",proc.pwd);
	getchar();
	
	do{
		if(strlen(proc.pwd) < 6){
			count++;
			printf("密码长度应不小于6！\n");
			printf("密码：");
			scanf("%s",proc.pwd);
			getchar();
		}else{
			break;
		}
		
	}while(count < 2);
	
	if(count == 2){
		printf("密码超过3次输入错误！请重新注册！\n");
		return;
	}
	
	proc.type = TYPE_REG;
	
	 
	write(fd,&proc,sizeof(proc));
	
RCV:	
	cnt = read(fd,&proc,sizeof(proc));
	
	if(cnt == 0){
		printf("server closed!\n");
		exit(0);
	}else if(cnt == -1){
		if(errno == EINTR)
			goto RCV;
		else
			return;
	}else{	
		printf("\n%s",proc.errinfo); 
		printf("%s\n",proc.content);
	}
	
}

//登录
int client_log(int fd){

	Proc proc = {};
	int cnt = 0;
	
	printf("用户名：");
	scanf("%s",proc.name);
	getchar();
	printf("密码：");
	scanf("%s",proc.pwd);
	getchar();
	
	strcpy(my,proc.name);
	
	proc.type = TYPE_LOG;
	
	write(fd,&proc,sizeof(proc));
	
RCV:
	cnt = read(fd,&proc,sizeof(proc));
	
	if(cnt == 0){
		printf("server closed!\n");
		exit(0);
	}else if(cnt == -1){
		if(errno == EINTR)
			goto RCV;
		else
			return -1;
	}else{	
		if(strcmp(proc.content,"登录成功！") != 0){
		
			printf("\n%s",proc.errinfo); 
			return -1;
		}
	}
	return 0;
}

//发送命令
void send_cmd(int fd){
	
	Proc proc = {};
	int cnt = 0;
	
	printf("请输入命令：");
	gets(proc.cmd);
	
	proc.type = TYPE_CMD;
	strcpy(proc.name,my);
	
	write(fd,&proc,sizeof(Proc));
	
	while(1){
	
		cnt = read(fd,&proc,sizeof(Proc));
		
		if(proc.has_next == 0){
			printf("\n");
			break;
		}
		
		if(cnt == 0){
			printf("server closed!\n");
			exit(0);
		}else if(cnt == -1){
			if(errno == EINTR)
				continue;
			else
				break ;
		}else{	
			write(1,proc.content,sizeof(proc.content));
		}
	}
}

//聊天
void chat_each_other(int fd){



}

