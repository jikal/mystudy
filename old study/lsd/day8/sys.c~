#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/wait.h>

void sys(const char* cmd){
	int fds[2];
	pid_t pid;
	char buf[512];
	//pid=fork();
	int cnt;
	pipe(fds);
	pid=fork();
	if(pid==0){
		close(fds[0]);
		dup2(fds[1],1);
		dup2(fds[1],2);
		execl("/bin/sh","/bin/sh","-c",cmd,NULL);
		close(fds[1]);
	}else if(pid>0){
		close(fds[1]);	
		while(1){		
			cnt=read(fds[0],buf,sizeof(buf)-1);

			if(cnt==0){
				break;		
			}else if(cnt==-1){
				if(errno==EINTR){
					continue;
				}else{
					break;
				}
			}else{
				buf[cnt]='\0';
				printf("%s",buf);
				fflush(stdout);
			}
		}
		close(fds[0]);
		wait(NULL);
	}else 
		;
}

int main(int argc,char **argv){
	sys(argv[1]);
	return 0;
}


