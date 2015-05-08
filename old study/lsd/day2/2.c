#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include <unistd.h>
#include<string.h>
int main(int argc,char** argv){
	int fd1;
	int fd2;
	char buf[1024]={};
	int cnt;
	fd1=open(argv[1],O_RDONLY);
	if(fd1==-1){
		printf("open file failed!\n");
		return 0;
	}
	fd2=open("b.txt",O_APPEND | O_RDWR | O_CREAT | O_EXCL,0644);
	if(fd2==-1){
		fd2=open("b.txt",O_RDWR);
	}
	while(1){
		cnt=read(fd1,buf,sizeof(buf));
		if(cnt==0)
			break;
		else{
			write(fd2,buf,cnt);
		}
	}
	lseek(fd2,5,SEEK_SET);
	cnt=read(fd2,&buf[0],sizeof(char));
	if(cnt==0){
		return 0;
	}else{
		printf("%c\n",buf[0]);
	}
	close(fd1);
	close(fd2);
	
	return 0;
}
