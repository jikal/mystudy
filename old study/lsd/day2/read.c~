#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>
void fun1(){
	printf("dasdasd\n");
}


int main(){
	int cnt;
	char buf[1024];
	atexit(fun1);
	cnt=read(fileno(stdin),buf,sizeof(buf)-1);
	if(cnt!=-1){
		buf[cnt-1]='\0';
	}
	write(fileno(stdout),buf,strlen(buf)+1);
	//while(1);
	_exit(9);
	return 0;
}

