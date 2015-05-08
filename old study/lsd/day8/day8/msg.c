//消息队列





#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>
#include<errno.h>
struct mymsg{
	long type;
	char text[512];
};


int msgid;
void msginit(){
	key_t key=ftok(".",'y');
	msgid=msgget(key,IPC_CREAT|IPC_EXCL|0600);
	if(msgid==-1){
		msgid=msgget(key,0600);
	}


}
void msgdel(){
	msgctl(msgid,IPC_RMID,NULL);
} 
void msgsend(long type,char *text){
	struct mymsg qbuf;
	qbuf.type=type;
	strcpy(qbuf.text,text);
	msgsnd(msgid,&qbuf,strlen(qbuf.text)+1,0);
}
void msgrecv(long type){
	int cnt;
	struct mymsg qbuf;

RCV:
	cnt=msgrcv(msgid,&qbuf,sizeof(qbuf.text),type,0);
	if(cnt==-1){
		if(errno==EINTR){
			goto RCV;
		}else{
			return;
		}
	}else {
		printf("recevie msg type:%ld,text:%s\n",qbuf.type,qbuf.text);
	}
}

int main(int argc,char **argv){

	msginit();
	switch(argv[1][0]){
		case 'w':msgsend(atol(argv[2]),argv[3]);break;
		case 'r':msgrecv(atol(argv[2]));break;
		case 'd':msgdel();break;
	}

	return 0;
}
