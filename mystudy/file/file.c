#include <stdio.h>

int main(){
	int n = 1;
	char filename[128] = {0};
	FILE *fp;
	char *str  = "abcdefghijklmn";
	char msg[20] = {0};
	while(1){
		sprintf(filename,"./1/%d.txt",n++);
		printf("this is %s\n",filename);
		fp = fopen(filename,"w");
		fputs(str,fp);
		fclose(fp);
		sleep(10);
	}
	return 0;
}

