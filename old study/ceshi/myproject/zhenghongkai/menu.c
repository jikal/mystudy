#include "menu.h"
#include "link.h"
static void wellcome_menu(void){
	system("clear");
	printf("*****************************************************************************\n");
	printf(" \n");
	printf("*                              终端管理系统                                  *\n");
	printf(" \n");
	printf("*                                版权： k                                    *\n");
	printf(" \n");
	printf("******************************************************************************\n");
}

void reg_menu(void){
	wellcome_menu();
	printf(" 1.用户注册  \n");
	printf(" 2.用户登陆  \n");
	printf(" ********************************\n");
	printf("请输入选择:");
}
void make_menu(void){
	wellcome_menu();
	printf(" 1.请输入要操作的命令：\n");
	printf(" 2.退出  \n");
	printf(" ********************************\n");
	printf("请输入选择:");
}

void sever_menu(void){
	system("clear");
	printf(" 1.查看当前在线用户\n");
	printf(" 2.关闭服务器\n");
	printf(" ********************************\n");
	printf("请输入选择:");
}
