//客户端控制程序
#include "model.h"
#include "view.h"
#include<netdb.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<netinet/in.h>
#define PORT 3333
#define SIZE 1024

int main(int argc,char** argv)
{
	int sockfd;
	struct sockaddr_in serveraddr;
	if(argc==1)
	{
		printf("argument wrong\n");
		exit(0);
	}
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("socket failed\n");
		exit(0);
	}
	
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons((short)PORT);
	inet_pton(AF_INET,argv[1],&serveraddr.sin_addr.s_addr);

	if(connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))==-1)
	{	printf("connect failed!\n");
		exit(0);
	}

	proc_echoc(sockfd);
	close(sockfd);
	return 0;
}
