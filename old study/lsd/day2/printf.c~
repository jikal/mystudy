#include<stdio.h>

void mprintf(const char *str,...){
	char *ptr=(char*)&str;
	
	ptr += sizeof(char*);
	printf("arg[1]=%c\n",*ptr);
	
	ptr+=sizeof(int);
	printf("arg[2]=%d\n",*(int*)ptr);

	ptr+=sizeof(int);
	printf("argv[3]=%lf\n",*(double*)ptr);

	ptr +=sizeof(double);
	printf("argv[4]=%d\n",*(int*)ptr); 

}
 
int main(){

	mprintf("sdfsdg",'y',56,45.7,88);
	return 0;
}
