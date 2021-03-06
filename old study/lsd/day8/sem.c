//信号量

#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<signal.h>
#include<fcntl.h>
int semid;
int shmid;
char *segptr=NULL;

void shminit(){
	key_t key =ftok(".",'q');
	shmid=shmget(key,1,IPC_CREAT|IPC_EXCL|0644);
	if(shmid==-1){
		shmid=shmget(key,1,0644);
	}
	segptr=shmat(shmid,NULL,0);
}
void shmdel(){
	shmctl(shmid,IPC_RMID,NULL);
}
void seminit(){
	key_t key=ftok(".",'t');
	semid=semget(key,2,IPC_CREAT|IPC_EXCL|0600);
	if(semid==-1){
		semid=semget(key,2,0600);
	}else{
		semctl(semid,0,SETVAL,1);
		semctl(semid,1,SETVAL,0);
	}

}

void semdestroy(){
	semctl(semid,9,IPC_RMID);
}

void semwait(int num){
	struct sembuf qbuf;
	qbuf.sem_num=num;
	qbuf.sem_op=-1;
	qbuf.sem_flg=SEM_UNDO;
	if(semop(semid,&qbuf,1)==-1){
		return;
	}
}

void sempost(int num){
	struct sembuf qbuf;
	qbuf.sem_num=num;
	qbuf.sem_op=1;
	qbuf.sem_flg=SEM_UNDO;
	if(semop(semid,&qbuf,1)==-1){
		return;
	}
}

void fun(int sig){
	if(sig==SIGCHLD){
		wait(NULL);
		semdestroy();
		shmdel();
		exit(0);
	}

}
int main(int argc,char **argv){
	int fd,cnt;
	pid_t pid;
	signal(SIGCHLD,fun);
	fd=open(argv[1],O_RDONLY);
	pid=fork();
	
	if(pid==0){
		seminit();
		shminit();
		while(1){
			semwait(0);
			cnt=read(fd,segptr,1);
			if(cnt==0){
				break;
			}
			sempost(1);
		}
	}else if(pid>0){
		seminit();
		shminit();
		while(1){
			semwait(1);
			printf("%c",*segptr);
			fflush(stdout);
			sempost(0);
		}
	}else
		;
	return 0;
}

