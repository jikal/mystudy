//服务器控制程序
#include "models.h"
#include "view.h"
#include"list.h"
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<signal.h>
#include<sys/wait.h>
#include<pthread.h>
#define SIZE 1024
#define PORT 3333

//服务器主函数，可以控制多线程
Node *head=NULL;
int main()
{	head=(Node *)calloc(1,sizeof(Node));
	head->next=head;
	head->prev=head;
	int sockfd,nsock;
	struct sockaddr_in serveraddr,clientaddr;
	char ipbuf[64];
	socklen_t len;

	 pthread_t id;
	 pthread_attr_t attr;
	
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);


	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("sockfd failed\n");
		exit(0);
	}	
serveraddr.sin_family = AF_INET;
serveraddr.sin_port=htons((short)PORT);
serveraddr.sin_addr.s_addr = INADDR_ANY;
	if(bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))==-1)
	{
		printf("bind failed!\n");
		exit(0);
	}

	if(listen(sockfd,256)==-1)
	{
		printf("listen failed!\n");
		exit(0);
		
	}
	
	len=sizeof(clientaddr);
	while(1)
	{
		nsock=accept(sockfd,(struct sockaddr*)&clientaddr,&len);	
		if(nsock==-1)
		{
			if(errno==EINTR)
			continue;
			else
			break;
		}
		inet_ntop(AF_INET,&clientaddr.sin_addr.s_addr,ipbuf,sizeof(ipbuf));
		printf("client ip:%s connectde!\n",ipbuf);
		pthread_create(&id,NULL,handleclient,(void*)nsock);
		//HandleSignal();//服务器主线程，储存日志文件
		
	}
	close(sockfd);
	return 0;
}
