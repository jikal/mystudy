#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;

static inline bool isnumber(char ch){
	
	return ((ch >= '0') && (ch <= '9'));
}

void qsort(int array[80],int index){
	int i = 0,j = 0;
	int temp = 0;
	for(i=0;i<index-1;i++){
		for(j=0;j<index-1-i;j++){
			if(array[j]<array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}
void qsort(char array[80],int index){
	int i = 0,j = 0;
	char temp = 0;
	for(i=0;i<index-1;i++){
		for(j=0;j<index-1-i;j++){
			if(array[j]<array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}
int main(int argc , char *argv[]){
	char *str = (char *)calloc(80,1);
	cout << "please input str:" << endl;
	cin >> str;
	//char str[80] = {0};
	//cin >> str;
	//scanf("%s",str);
	char char_array[80] = {0};
	int int_array[80] = {0};
	int i = 0;
	int char_array_index = 0;
	int int_array_index = 0;
	bool is_previors_char_number = false;

	char *p = NULL;
	int str_len = strlen(str);
	for(i=0;i < str_len;i++){
		char ch = *(str+i);

		if(isnumber(ch)){
			if(is_previors_char_number){
				int num = int_array[int_array_index];
				num *= 10;
				num +=(ch - '0');
				int_array[int_array_index] = num;
			}else{
				int_array[int_array_index] = ch -'0';
				is_previors_char_number = true;
			}
		}else{
			if(is_previors_char_number){
				int_array_index++;
			}
			char_array[char_array_index] = ch;
			char_array_index++;
			is_previors_char_number = false;
		}
	}
	
	if(is_previors_char_number){
		int_array_index++;
	}
	qsort(char_array,char_array_index);
	qsort(int_array,int_array_index);
	for(i=0;i<int_array_index;i++){
		cout << int_array[i] << " ";
	}
	cout << endl;
	for(i=0;i<char_array_index;i++){
		cout << char_array[i] << " ";
	}
	cout << endl;
	return 0;
}
