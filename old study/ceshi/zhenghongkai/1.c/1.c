#include <stdio.h>
#include <string.h>
int main(){
	char s1[128] = {};
	char s2[128] = {}; 
	int n = 1;
	int i = 0; 
	int j = 0;
	char c;
	printf("请输入字符串 s1:");
	scanf("%s",s1);
	printf("请输入字符串 s2:");
	scanf("%s",s2);
	
	char *s = s1;
	char *p = s2;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for(i=0;i<len2;i++){
		for(j=0;j<len1;j++){
			if(*(p+i) == *(s+j)){
				c = *(p+i);
								
			}
		}
			
	}
	printf("%s\n",s1);
}
