#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
	pid_t pid;
	int i=9;

	pid=fork();
	//printf("*******************\n");
	if(pid==0){
		
		printf("%d child : PID %d,PPID %d\n",i,getpid(),getppid());
		exit(60);
	}else if(pid>0){
		i++;
		printf("%d parent:PID %d,child PID %d\n",i,getpid(),pid);
		//pid_t pid1=wait(NULL);

		pid_t pid1;
		int status;
		unsigned int exitcode; 
		do{
			pid1=waitpid(pid,&status,WNOHANG);
		}while(pid1==0);
		if(WIFEXITED(status)){
			//exitcode=WEXITSTATUS(status);
			
		}
		printf("CHILD pid %d EXITED! exitcode %u\n",pid1,exitcode);			
	}else
		;
	return 0;
}
