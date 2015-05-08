#include "server_control.h"
#include "server_model.h"

Usr *usr_head = NULL;
Daily *daily_head = NULL;
time_t start = 0;

sem_t sem1;
sem_t sem2;

int main(int argc,char **argv){

	pthread_t id;
	pthread_attr_t attr;
	int sockfd,nsock;
	struct sockaddr_in serveraddr,clientaddr;
	char ipbuf[64];
	socklen_t len;
	
	usr_head = create_usr_head();
	daily_head = create_daily_head();

	
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	
	sem_init(&sem1,0,1);
	sem_init(&sem2,0,1);
	
	
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	
	if(sockfd == -1){
	
		printf("sockfd failed!\n");
		exit(0);
	}
	
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons((short)PORT);
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	
	if(bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr)) == -1){
		
		printf("bind failed!\n");
		exit(0);
	}
	
	if(listen(sockfd,256) == -1){
	
		printf("listen failed!\n");
		exit(0);
	}
	
	len = sizeof(clientaddr);
	while(1){
		
		nsock = accept(sockfd,(struct sockaddr *)&clientaddr,&len);
		
		if(nsock == -1){
			if(errno ==EINTR)
				continue;
			else 
				break;
		}
		Msg *msg = (Msg *)calloc(1,sizeof(Msg));
		msg->usr_head = usr_head;
		msg->daily_head = daily_head;
		msg->fd = nsock;
		
		inet_ntop(AF_INET,&clientaddr.sin_addr.s_addr,ipbuf,sizeof(ipbuf));
		printf("client ip: %s connected!\n",ipbuf);
		
		strcpy(msg->client_ip,ipbuf);
		
		pthread_create(&id,&attr,proc_echo,(void *)msg);

	}
	
	sem_destroy(&sem1);
	sem_destroy(&sem2);
	
	close(sockfd);

	return 0;
}
