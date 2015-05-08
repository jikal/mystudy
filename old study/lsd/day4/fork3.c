#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(){
	int fd;
	char *str1="abc";
	char *str2="123456";
	
	fd=open("t.txt",O_APPEND|O_CREAT|O_RDWR|O_EXCL);
	if(fd==-1){
		fd=open("t.txt",O_APPEND|O_RDWR);
	}
	pid_t pid;
	pid=fork();
	if(pid==0){
		sleep(1);
		write(fd,str1,strlen(str1));
		close(fd);
	}else if(pid>0){
		write(fd,str2,strlen(str2));
		close(fd);
	}else
		;	
	
	return 0;
}
