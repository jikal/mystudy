#include "getFilePath.h"

#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>

int main(int argc , char *argv[]){
	const char *fileNamePath = "/media/sdcard/yesterday.mp3";
	char *fileName=getFileName(fileNamePath);
	if(fileName==NULL){
		cout << "error1!"<<endl;
		exit(1);
	}
	char *fileExtesion = getFileExtesion(fileNamePath);
	if(fileExtesion==NULL){
		cout << "error2!" <<endl;
		free(fileName);
		exit(1);
	}
	cout << "fileName is:"<<fileName<<endl;
	cout << "fileExtesion is:" << fileExtesion << endl;
	free(fileExtesion);
	free(fileName);
	return 0;
}
