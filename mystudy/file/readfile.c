#include <stdio.h>
int main(){	
	int n = 1;
	char filename[128] = {0};
	FILE *fp;
	char msg[20] = {0};
	while(1){
		sprintf(filename,"./1/%d.txt",n++);
		fp = fopen(filename,"r");
		while(fgets(msg,20,fp) != NULL){
			printf("filename:%s msg:%s\n",filename,msg);		
		}
		fclose(fp);	
	sleep(10);	
	}
	return 0;
}
