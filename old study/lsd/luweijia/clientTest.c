#include "client_model.h"
#include "client_control.h"
#include <fcntl.h>

char my[24] = {};//显示在线用户
int sockfd = 0;

int main(int argc,char **argv){

	//int sockfd = 0;
	int fd = 0;
	char buf[SIZE] = {0};
	
	pthread_t id;
	pthread_attr_t attr;
	
	struct sockaddr_in serveraddr;
	
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	
	//pthread_create(&id,&attr,send_heart);
	
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1){
	
		printf("socket failed!\n");
		exit(0);
	} 
	
	fd = open("./serip.txt",O_CREAT | O_EXCL | 0644);
	if(fd == -1){
	
		fd = open("./serip.txt",0644);
	}
	
	
	read(fd,buf,sizeof(buf));
	buf[strlen(buf) - 1] = '\0';
	
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons((short)PORT);
	inet_pton(AF_INET,buf,&serveraddr.sin_addr.s_addr);
	
	if(connect(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr)) == -1){
		
		printf("connect failed!\n");
		exit(0);
	}
	
	pthread_create(&id,&attr,send_heart,NULL);
	proc_echo(sockfd);
	close(sockfd);
	
	return 0;
} 
