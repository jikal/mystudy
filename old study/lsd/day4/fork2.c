#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	pid_t pid1,pid2,pid3;
	pid1=fork();
	pid2=fork();
	pid3=fork();

	printf("PID1 %d,PID2 %d,PID3 %d\n",pid1,pid2,pid3);

	while(1);
	return 0;
}
