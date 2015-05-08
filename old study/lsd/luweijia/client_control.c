#include "client_model.h"
#include "client_control.h"
#include <fcntl.h>

void proc_echo(int fd){

	int cnt = 0;
	int chose = 0;
	
	while(1){
		do{	
			system("clear");
			printf("-----------------------------\n\n");
			printf("  欢迎来到远程终端控制系统!\n\n");
			printf("-----------------------------\n\n");
			printf("  0.注册 1.登录 2.退出\n\n");
			printf("请选择：");
			cnt = scanf("%d",&chose);
			myfflush();//清空缓存
		}while(cnt != 1 || chose > 2);
	
		if(chose == 2){
			return;
		}
	
		switch(chose){
	
			case 0:	//注册
				 
				client_reg(fd);
				push_continue();
				
				break;
			case 1://登录
				
				if(client_log(fd) == 0){
				
					client_log_control(fd);
				}else{
					printf("登录失败！\n");
					push_continue();
				}
				break;
			default:
				break;
		}
	}
	 
	close(fd);
}
//客户端登录控制界面
void client_log_control(int fd){
	
	int cnt = 0;
	int chose = 0;
	
	while(1){
		do{	
			system("clear");
			printf("-----------------------------\n\n");
			printf("  欢迎来到远程终端控制系统!\n\n");
			printf("-----------------------------\n");
			printf("         在线用户：%s \n\n",my);
			printf("  0.命令查询 1.聊天 2.退出\n\n");
			printf("请选择：");
			cnt = scanf("%d",&chose);
			myfflush();
		}while(cnt != 1 || chose > 2);
	
		if(chose == 2){
			return;
		}
	
		switch(chose){
	
			case 0:	//命令查询
			 	send_cmd(fd);
				push_continue();
			 
				break;
			case 1://聊天
				chat_each_other(fd);
				push_continue(); 
				
				break;
			default:
				break;
		}
	}
}

//处理信号函数
void sig_handle(int sig){

	if(sig == SIGALRM){
		Proc proc ={};
		
		proc.type = TYPE_HEART;
		strcpy(proc.content,"alive");
		
		write(sockfd,&proc,sizeof(Proc));
		alarm(3);
	}

}

//客户端发送心跳包
void *send_heart(void *sockfd){
	
	signal(SIGALRM,sig_handle);
	
	raise(SIGALRM);
	
	return NULL;
}


