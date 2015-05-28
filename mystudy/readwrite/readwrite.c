#include<stdio.h>
#include <stdlib.h>

int main()
{
FILE *fp;
char ch,st[20];
if((fp=fopen("string","at+"))==NULL)
{
printf("Cannot open file strike any key exit!");
getchar();
exit(1);
}
printf("input a string:\n");
scanf("%s",st);
fputs(st,fp);
rewind(fp);
ch=fgetc(fp);
while(ch!=EOF)
{
putchar(ch);
ch=fgetc(fp);
}
printf("\n");
fclose(fp);
return 0;
}
