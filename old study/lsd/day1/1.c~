#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main(){
	int  fd;
	char buf[1024];
	int cnt;
	fd=open("ABC",O_CREAT | O_EXCL | O_RDWR | O_APPEND,0644);
	if(fd==-1){
		fd=open("ABC",O_RDWR | O_APPEND);
		printf("open file abc !\n");
	}else{
		printf("creat file abc !\n");
	}
	scanf("%s",buf);
	write(fd,buf,strlen(buf));

	
	off_t set = lseek(fd,0,SEEK_SET);
	printf("set = %ld\n",set);

	while(1){
		cnt=read(fd,&buf[0],sizeof(char));	
		if(cnt==0){
			break;
		}else{
			printf("%c",buf[0]);
			fflush(stdout);
			
		}
	}
	printf("\n");

	close(fd);

	return 0;
}
