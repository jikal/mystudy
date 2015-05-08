#include<stdio.h>
#include<malloc.h>
#include<sys/types.h>
#include<fcntl.h>
#include <unistd.h>
#include<string.h>
#define SIZE 8
typedef struct{
	int fd;
	int flag;
	char* base;

}IOFILE;

IOFILE* IOfopen(const char* name,const char* mode){
	IOFILE* fp = malloc(sizeof(IOFILE));
	fp->flag=0;	
	fp->base=malloc(sizeof(char)*SIZE);
	fp->fd=open(name,O_RDWR|O_CREAT|O_EXCL|O_APPEND,0644);
	if(fp->fd==-1){
		fp->fd=open(name,O_APPEND|O_RDWR);
		if(fp->fd==-1){
			free(fp->base);
			free(fp);
			return NULL;
		}
	}
	return fp;
}
int IOfwrite(const void *ptr,int type,int num,IOFILE *fp){
	int len = type*num;
	int cnt=0;
	while(1){
		if((SIZE-fp->flag)>len){
			memcpy(fp->base+fp->flag,ptr,len);
			fp->flag+=len;
			cnt+=len;
			break;
		}
		else if((SIZE-fp->flag)==len){
			memcpy(fp->base+fp->flag,ptr,len);
			fp->flag=0;
			write(fp->fd,fp->base,SIZE);
			cnt+=len;
			break;
		}
		else{
			memcpy(fp->base+fp->flag,ptr,SIZE-fp->flag);
			write(fp->fd,fp->base,SIZE);
			len -=SIZE-fp->flag;
			ptr +=SIZE-fp->flag;
			//cnt +=SIZE-fp->flag;
			fp->flag=0;
			
		}
	
	}

	return num;
}	

void IOfclose(IOFILE *fp){
	write(fp->fd,fp->base,fp->flag);
	if(fp!=NULL){
		close(fp->fd);
		free(fp->base);
		free(fp);
	}		
}
void IOfflush(IOFILE *fp){
	write(fp->fd,fp->base,fp->flag);
	fp->flag=0;
}
int IOfread(void *ptr,int type,int num, IOFILE *fp){
	read(fp->fd,ptr,type*num);
	return num;
}
int IOfeof(IOFILE *fp){
	int n=lseek(fp->fd,0,SEEK_CUR);
	if(n>=lseek(fp->fd,0,SEEK_END)){
		return -1;
	}
	else{
		lseek(fp->fd,n,SEEK_SET);
		return 0;
	}

}	
int main(int argc,char** argv){
	char buf[128];
	IOFILE *fp=IOfopen(argv[1],"r+");
	while(1){
		scanf("%s",buf);
		if(strcmp(buf,"exit")==0)
			break;
		IOfwrite(buf,sizeof(char),strlen(buf),fp);
	}
	IOfflush(fp);
	lseek(fp->fd,0,SEEK_SET);
	while(!IOfeof(fp)){
		IOfread(&buf[0],sizeof(char),1,fp);
		printf("%c",buf[0]);
		fflush(stdout);
	}
	printf("\n");
	return 0;
}
