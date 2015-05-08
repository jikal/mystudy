#include<pthread.h>
#define PORT 3333
#include "control.h"
#include "link.h"
#include "mode.h"
int main(int argc,char **argv){
	my=(Node *)calloc(1,sizeof(Node));
	if(my==NULL){
		return -1;
	}
	int sockfd=-1;
	pthread_t tid;
	struct sockaddr_in serveraddr;
	if(argc == 1){
		printf("argument error!\n");
		exit(0);
	}
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1){
		printf("socket failed!\n");
		exit(0);
	}
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons((short)PORT);
	inet_pton(AF_INET,argv[1],&serveraddr.sin_addr.s_addr);
	
	if(connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr)) == -1){
		printf("connect failed!\n");
		exit(0);
	}
	pthread_create(&tid, NULL, (void *)client_heart,(void *)sockfd);
	clientproc_echo(sockfd);
	free(my);
	close(sockfd);
	return 0;
}
