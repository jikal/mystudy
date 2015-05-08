#include "getFilePath.h"

#include <string.h>
#include <stdlib.h>

char *getFileName(const char *fileNamePath){
	if(fileNamePath == NULL){
		return NULL;
	}
	int len = strlen(fileNamePath);
	char *temp = (char *)calloc(len+1,sizeof(char));
	if(temp==NULL){
		return NULL;
	}
	strcpy(temp,fileNamePath);

	char *s=strchr(temp,'.');
	char *e=strrchr(temp,'/');
	int size=s-e-1;

	char *str=(char *)calloc(size+1,sizeof(char));
	if(str==NULL){
		free(temp);
		return NULL;
	}

	strncpy(str,e+1,size);
	str[size]=0;
	free(temp);
	return str;
}
char *getFileExtesion(const char *fileNamePath){
	if(fileNamePath==NULL){
		return NULL;
	}
	int len=strlen(fileNamePath);
	char *temp=(char *)calloc(len+1,sizeof(char));
	if(temp==NULL){
		return NULL;
	}
	strcpy(temp,fileNamePath);

	char *s=strchr(temp,'\0');
	char *e=strrchr(temp,'.');
	int size=s-e-1;

	char *str = (char *)calloc(size+1,sizeof(char));
	if(str==NULL){
		free(temp);
		return NULL;
	}
	strncpy(str,e+1,size);
	str[size]=0;
	free(temp);
	return str;
}
