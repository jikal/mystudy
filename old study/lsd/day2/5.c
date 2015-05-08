#include<stdio.h>
#include<unistd.h>

int main(){
	int su;
	chomd("1.c",0777);
	su=access("1.c",R_OK|W_OK|x_OK);
	printf("sud= %d\n",su);
	return 0;
}
