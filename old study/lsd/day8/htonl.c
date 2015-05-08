#include<stdio.h>
/*
int main(){
	unsigned int i=1;
	printf("litter endian:%x\n",i);
	i=htonl(i);
	printf("big endian:%x\n",i);
	return 0;
}
*/

unsigned int mhtonl(unsigned int s){
	char tmp;
	unsigned int x=0x01;
	unsigned char *p=(unsigned char*)&x;
	if(*p==0x01){
		p=(unsigned char*)&s;
		tmp=*p;
		*p=*(p+3);
		*(p+3)=tmp;
		tmp=*(p+1);
		*(p+1)=*(p+2);
		*(p+2)=tmp;
		return s;
	}else{
		return s;
	}
}
unsigned int mhtonl2(unsigned int s){
	unsigned int i=0x01;
	if(i<<24>>24==0x01){
		return (s<<24)|(s>>24)|(s>>8<<24>>8)|(s<<8>>24<<8);
	}else{
		return s;
}
}



int main(int argc,char** argv[]){
	printf("mhtonl=%d\n",mhtonl(atol(argv[1])));
	printf("mhtonl2=%d\n",mhtonl2(atol(argv[1])));
	printf("htonl=%d\n",htonl(atol(argv[1])));
	return 0;
}
