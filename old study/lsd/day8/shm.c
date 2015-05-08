//共享内存

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<errno.h>
#include<sys/shm.h>
#include<unistd.h>

int shmid;
char *segptr=NULL;
void shminit(){
	key_t key =ftok(".",'q');
	shmid=shmget(key,1024,IPC_CREAT|IPC_EXCL|0644);
	if(shmid==-1){
		shmid=shmget(key,1024,0644);
	}
	segptr=shmat(shmid,NULL,0);
}
void shmdel(){
	shmctl(shmid,IPC_RMID,NULL);
}


int main(int argc,char **argv){	
	shminit();
	switch(argv[1][0]){
		case 'd':shmdt(segptr);
			shmdel();
			break;
		case 'r':printf("read:%s;%c\n",segptr,*(segptr+4));
			shmdt(segptr);
			break;
		case 'w':strcpy(segptr,argv[2]);
			shmdt(segptr);
			break;
	}
	
	return 0;
}
