#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char** argv){
	int fd;
	fd=open(argv[1],O_APPEND);
	int cnt;
	char c;
	int n='a'-'A';
	if(fd==-1){
		printf("open file failed!\n");
		return 0;
	}
	while(1){
		cnt=read(fd,&c,sizeof(char));
		if(cnt==0)
			break;
		else if(cnt==-1){
			break;
		}
		else{
			if(c>='a'&&c<='z'){
				c-=n;
				lseek(fd,-1,SEEK_CUR);
				write(fd,&c,sizeof(char));
			}
			else if(c>='A'&&c<='Z'){
				c+=n;
				lseek(fd,-1,SEEK_CUR);
				write(fd,&c,sizeof(char));
			}
			else{
				continue;
			}
		}		
	}
	close(fd);
	
	return 0;
}
