#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include <unistd.h>
#include<string.h>
int main(){
	int  fd;
	char str[1024];
	fd=open("c.txt",O_CREAT | O_EXCL | O_RDWR | O_APPEND,0644);
	if(fd==-1){
		fd=open("c.txt",O_RDWR | O_APPEND);
		printf("open file c.txt !\n");
	}else{
		printf("creat file c.txt !\n");
	}
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
