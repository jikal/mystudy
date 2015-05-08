#include "mode.h"
void push_continue(void){
	printf("按回车继续...\n");
	getchar();
}

void regusr(int fd){
	Parket buf = {0};
	char pwd1[32];
	char pwd2[32];
	int cnt=-1;
	while(1){
		printf("请输入你需要注册的用户名:\n");
		scanf("%s",buf.name);
		printf("请输入不小于6位数密码：\n");
		scanf("%s",pwd1);
		if(strlen(pwd1)<6){
			printf("你输入的密码太简单，请重新注册!\n");
			return;
		}
		printf("请再次输入密码：\n");
		scanf("%s",pwd2);
		if(strcmp(pwd1,pwd2)==0){
			strcpy(buf.pwd,pwd1);
		}else{
			printf("你两次输入的密码不一样，请重新注册！\n");
			return;
		}
		buf.data_type=TYPE_REG;
		write(fd,&buf,sizeof(Parket));
	
		cnt=read(fd,&buf,sizeof(buf));
		if(cnt == 0){
			printf("server closed!\n");
			exit(0);
		}
		if(cnt<0){
			perror("login read");
			exit(0);
		}
		if(strcmp(buf.usr_return,"yes")==0){
			printf("注册成功！\n");
			break;
		}else if(strcmp(buf.usr_return,"exist")==0){
			printf("注册失败！此用户已存在！2秒钟后退出！\n");
			sleep(2);
			exit(0);
		}		
	}
}
//检查注册
int check_reg(Cache *cache,Parket *ptr){
	if(ptr == NULL || cache == NULL){
		return -1;
	}
	Daily *newDaily=(Daily *)calloc(1,sizeof(Daily));
	Node *newNode=(Node *)calloc(1,sizeof(Node));
	if(newNode==NULL){
		exit(0);
	}
	Node *cur=head->next;
	while(cur!=head){
		if(strcmp(cur->name,ptr->name)==0){
			strcpy(ptr->usr_return,"exist");
			write(cache->fd,ptr,sizeof(Parket));
			return 1;
		}
		cur=cur->next;	
	}
	strcpy(newNode->name,ptr->name);
	strcpy(newNode->pwd,ptr->pwd);
	newNode->state=0;
	strcpy(newDaily->name,ptr->name);
	strcpy(newDaily->client_ip,cache->clientip);
	strcpy(newDaily->cmd,"注册成功！");
	strcpy(ptr->usr_return,"yes");
	write(cache->fd,ptr,sizeof(Parket));
	InsertdHead(newDaily);
	InsertHead(newNode);	
	return 0;
}
//用户登陆
int logusr(int fd){
	Parket buf = {0};
	int cnt=-1;
	while(1){
		printf("请输入你的用户名:\n");
		scanf("%s",buf.name);
		printf("请输入你的密码：\n");
		scanf("%s",buf.pwd);
		buf.data_type=TYPE_LOGIN;
		write(fd,&buf,sizeof(Parket));

		cnt=read(fd,&buf,sizeof(buf));
		if(cnt<0){
			perror("login read");
			exit(0);
		}
		if(strcmp(buf.usr_return,"yes")==0){
			printf("登陆成功！\n");
			strcpy(my->name,buf.name);
			return 1;
		}else if(strcmp(buf.usr_return,"wrong")==0){
			printf("此用户不存在或已登陆！请重新注册登陆！\n");
			getchar();
			push_continue();
			return 2;		
		}		
	}
	return 0;
}
//检测登陆
int check_log(Cache *cache,Parket *ptr){
	if(ptr == NULL || cache == NULL){
		return -1;
	}
	Daily *newDaily=(Daily *)calloc(1,sizeof(Daily));
	Node *cur=head->next;
	while(cur!=head){
		printf("%d\n",cur->state);
		if(strcmp(cur->name,ptr->name)==0 && strcmp(cur->pwd,ptr->pwd)==0&&cur->state==0 ){
			clientinfo *newinfo=(clientinfo *)calloc(1,sizeof(clientinfo));
			strcpy(ptr->usr_return,"yes");
			strcpy(ptr->name,cur->name);
			time_t t;
			time(&t);
			char *tm = ctime(&t);
			strcpy(newinfo->name,ptr->name);
			newinfo->clientfd=cache->fd;
			strcpy(newinfo->clientip,cache->clientip);
			newinfo->state=1;
			strcpy(newinfo->tm,tm);
			InsertiHead(newinfo);
			cur->state=1;
			strcpy(newDaily->name,ptr->name);
			strcpy(newDaily->client_ip,cache->clientip);
			strcpy(newDaily->cmd,"登陆成功！");
			InsertdHead(newDaily);
			write(cache->fd,ptr,sizeof(Parket));
			free(newDaily);
			return 0;		
		}
		cur=cur->next;
	}
	if(cur==head){
		strcpy(ptr->usr_return,"wrong");
		write(cache->fd,ptr,sizeof(Parket));
		return 1;
	}
	
	return -1;	
}
//用户发送心跳
void client_heart(int fd){
	Parket buf={0};
	buf.data_type = TYPE_HEART;
	while (1){
		write(fd,&buf,sizeof(Parket));
		sleep(3); 
	}
}
//服务器接受心跳
void server_heart(Cache *cache){
	time_t t;
	time(&t);
	char *tm = ctime(&t);
	printf("当前用户ip地址：%s，当前发送信号用户套接字：%d，当前时间：%s",cache->clientip,cache->fd,tm);
}
//用户发出命令
void incmd(int fd){
	Parket buf={0};
	int cnt = 0;
	buf.data_type = TYPE_CMD;
	printf("请输入你想要操作的命令：\n");

	read(0,buf.cmd,sizeof(buf.cmd));
	if(strcmp(buf.cmd,"exit")==0){
		return;
	}


	write(fd,&buf,sizeof(Parket));
	while(1){
		cnt = read(fd,&buf,sizeof(Parket));
		
		if(buf.hasbuf_next == 0){
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
			write(1,buf.cmd_return,sizeof(buf.cmd_return));
		}
	}
}
//服务器返回命令
int execmd(Parket *ptr, Cache *cache){
	if(ptr == NULL || cache == NULL){
		return -1;
	}	
	pid_t pid;
	int fds[2];
	int cnt  = 0;
	Daily *newDaily=(Daily *)calloc(1,sizeof(Daily));
	if(newDaily==NULL){
		return -1;
	}
	strcpy(newDaily->name,ptr->name);
	strcpy(newDaily->client_ip,cache->clientip);
	strcpy(newDaily->cmd,ptr->cmd);
	InsertdHead(newDaily);

	pipe(fds);
	
	pid = fork();
	if (pid ==  0){
		close(fds[0]);
		dup2(fds[1], 1);
		execlp("/bin/sh", "bin/sh", "-c",ptr->cmd, NULL);
		close(fds[1]);
	}else if (pid > 0 ){
		close(fds[1]);
		while(1){
			Parket buf={0};	
			cnt = read(fds[0],buf.cmd_return,sizeof(buf.cmd_return)-1);
			
			if(cnt == 0){
				//buf.cmd_return[cnt]='\0'
				buf.hasbuf_next = 0;
				//write(cache->fd,&buf,sizeof(Parket));
				break;
			
			}else if(cnt == -1){
			
				if(errno == EINTR)
					break;
				else
					continue;
			}else{	
				buf.cmd_return[cnt]='\0';
				buf.hasbuf_next = 1;
				write(cache->fd,&buf,sizeof(Parket));
			}
		}
		close(fds[0]);
		wait(NULL);
	}
	return 0;		
}


//查看当前在线用户
void server_browse(){
	clientinfo *cur=ihead->next;
	while(cur!=ihead){
		if(cur->state==1){
			showlogusr(cur);
			cur=cur->next;
		}
	}		
}
void showlogusr(clientinfo *e){
	printf("===============================================\n");
	printf("用户名：%5s用户ip：%5s用户登陆时间：%5s\n",e->name,e->clientip,e->tm);
	printf("===============================================\n");
}	
//清空缓存
void myfflush(void){
	int ch=0;
	while(((ch=getchar()))!='\n' && (ch != EOF));
}


//用户退出
void usr_exit(int fd){
	int cnt=-1;
	Parket buf={0};
	buf.data_type=TYPE_EXIT;
	strcpy(buf.name,my->name);
	write(fd,&buf,sizeof(Parket));
	while(1){
		cnt=read(fd,&buf,sizeof(Parket));	
		if(cnt==0){
			printf("server closed!\n");
			fflush(stdout);
			exit(0);
		}
		if (cnt < 0){
			if(errno == EINTR){
				continue;
			}else{
				break;
			}
		}else if(strcmp(buf.usr_return,"ok")==0){
			printf("正在退出。。。\n");
			sleep(2);
			free(my);
			exit(0);	
		}	
	}
}
//服务器检测退出

void check_exit(Parket *ptr, Cache *cache){
	Daily *newDaily=(Daily *)calloc(1,sizeof(Daily));
	if(newDaily==NULL){
		return;		
	}
	Node *cur=head->next;
	clientinfo *cur1=ihead->next;
	while(cur!=head){
		if(strcmp(cur->name,ptr->name)==0){
			cur->state=0;
			strcpy(ptr->usr_return,"ok");
		}
		cur=cur->next;
	}
	while(cur1!=ihead){
		if(strcmp(cur1->name,ptr->name)==0){
			cur1->state=0;
		}
		cur1=cur1->next;
	}
	strcpy(newDaily->name,ptr->name);
	strcpy(newDaily->client_ip,cache->clientip);
	strcpy(newDaily->cmd,"已退出！");
	InsertdHead(newDaily);
	write(cache->fd,ptr,sizeof(Parket));
}




