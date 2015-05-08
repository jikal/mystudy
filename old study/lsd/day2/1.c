#include<stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

int main(){
	int fd=0;
	char str[1024]={};
	fd=open("a.txt",O_APPEND | O_RDWR | O_CREAT | O_EXCL,0644);
	if(fd==-1)
		fd=open("a.txt",O_APPEND|O_RDWR);
	dup2(fd,fileno(stdout));	
	while (1){
		scanf("%s",str);
		if(strcmp(str,"exit")==0)
			break;
		printf("%s\n",str);
	}
	close(fd);
	return 0;
}
