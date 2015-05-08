#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define  LISTENQ  5
#define  MAXLINE  512
#define  max(x,y) (((x)>(y))?(x):(y))

int main()
{
	int sockfd;
	int nbytes;
	struct sockaddr_in  servaddr;
	char message[MAXLINE];
	char sndbuff[MAXLINE];
	fd_set infds;
	int maxfd;

	/*创建套接字*/
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0){
        	printf("Socket created failed\n");
        	return -1;
    	}

	/*填充socket_in 结构*/
	servaddr.sin_family = AF_INET;
	servaddr.sin_port=htons(6666);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

	while(1){
        	FD_ZERO(&infds);
        	FD_SET(fileno(stdin),&infds);
        	FD_SET(sockfd,&infds);
        	maxfd=max(fileno(stdin),sockfd)+1;

        	if (select(maxfd,&infds,NULL,NULL,NULL)==-1){
             		printf("select io error\n");
             		return -1;
        	}

        /*如果scoket io 准备好了*/
        	if (FD_ISSET(sockfd,&infds)){
            		nbytes = recvfrom(sockfd, message, MAXLINE, 0, NULL, NULL); 
            		if (nbytes < 0){
                		printf("recvfrom(server) failed.\n");
                		return -1;
            		}else{
                		message[nbytes]=0;
                		printf("receive message from server %s", message);
            		}
        	}

        /*如果是输入IO 准备好了*/
		if (FD_ISSET(fileno(stdin),&infds)){
			if (fgets(sndbuff, MAXLINE, stdin) == NULL){
			return -1;
			}
			nbytes = sendto(sockfd, sndbuff, sizeof(sndbuff), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
			if (nbytes < 0){
				printf("sendto(server) failed.\n");
				return -1;
			}
		}
	}

	close(sockfd);

	return 0;
}

