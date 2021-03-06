#include "models.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "view.h"
#include<unistd.h>
#include<errno.h>
#include"list.h" 
#include <sys/wait.h>
#include <sys/types.h>

extern Node *head;

void* handleclient(void* p)//处理客户端函数
{	
	Cli senmsg;//定义一个Cli类型的结构体，承载与客户端交互的信息
	//Cli msgtocli;//发送给客户端的信息
	int fd;
	int cnt;
	fd=(int)p;
	while(1)
	{
			cnt=read(fd,&senmsg,sizeof(Cli));
			if(cnt==0)
			{	
			printf("client closed\n");
			break;
		}
		else if(cnt==-1)
		{
			if(errno==EINTR)
			continue;
			else 
			break;
		
		}
		else
		{	
			switch(senmsg.DATA_TYPE)
			{
			case TYPE_REG://处理客户端注册
			if(reg_cli(head,&senmsg)>0)
			{
			printf("注册成功！");
			write(fd,&senmsg,sizeof(Cli));
			}
			else
			printf("注册失败！");
			break;

			case TYPE_LOGIN://处理客户端登录
			if(log_in(head,&senmsg,comp)>0)
			{
			printf("可以登录！！");
			
			write(fd,&senmsg,sizeof(Cli));
			
			add_dai(head,&senmsg) ;//将客户端信息记入日志链表当中
			
			}
			else
			printf("登录失败！");			
			break;

			case TYPE_CMD://处理客户端命令
			strcpy(senmsg.CMD_RET,sys(senmsg.cmd));
			write(fd,&senmsg,sizeof(Cli));
			break;
			default:
			break;
			}
		}
	}
	close(fd);
return NULL;
}
//处理客户端命令函数，返回处理结果
char* sys(const char* cmd)
{
	int fds[2];
	pid_t pid;
	static char buf[1024];
	int cnt;

	 pipe(fds);

	 pid=fork();
	 if(pid==0)
	 {		close(fds[0]);
			dup2(fds[1],1);
			dup2(fds[1],2);
			execl("/bin/sh","/bin/sh","-c",cmd,NULL);
	 		close(fds[1]);
	 }

	 else if(pid>0)
	 {
	 close(fds[1]);
 		while(1){
			cnt=read(fds[0],buf,sizeof(buf)-1);

			if(cnt==0)
			{
				break;
			}
			else if(cnt==-1)
			{
				if(errno==EINTR)
					continue;
				else
					break;
			}
			else{
				buf[cnt]='\0';
				fflush(stdout);
			}
		}
	
	printf("\n");
 	close(fds[0]);
	wait(NULL);
	return buf;
	 }
	else;
	return NULL;
}

