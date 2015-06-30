#include <stdio.h>
#include "view.h"
#include<stdlib.h>
static void wellcome_menu(void){
	system("clear");
	printf("*****************************************************************************\n");
	printf(" \n");
	printf("*                            欢迎进入彩票福利中心                           *\n");
	printf(" \n");
	printf("*                                版权： k                                   *\n");
	printf(" \n");
	printf("*****************************************************************************\n\n");
}

void reg_menu(void){
	wellcome_menu();
	printf(" 1.用户注册  \n");
	printf(" 2.用户登陆  \n");
	printf(" 3.管理员登陆  \n");
	printf(" 0.退出  \n");
	printf(" ********************************\n");
	printf("请输入选择:");
}

void log_menu(void){
	wellcome_menu();
	printf("  1.修改个人信息  \n");
	printf("  2.充值  \n");
	printf("  3.彩票信息  \n");
	printf("  4.查看个人详情  \n");
	printf("  0.退出  \n");
	printf("  ==================================\n");
	printf("请输入选择:");
}
//管理员菜单
void admin_menu(void){
	wellcome_menu();
	printf("  1.发布彩票  \n");
	printf("  2.开奖  \n");
	printf("  3.查看彩票  \n");
	printf("  4.查看彩票收入  \n");
	printf("  5.查询信息  \n");
	printf("  6.删除已开奖彩票  \n");
	printf("  0.退出  \n");
	printf("  ==================================\n");
	printf("请输入选择:");
}
//管理员查询信息
void checklotter_menu(void){
	wellcome_menu();
	printf("  1.查看彩民信息  \n");
	printf("  2.按金额排序  \n");
	printf("  3.查询用户购买记录  \n");
	printf("  0.退出  \n");
	printf("  ==================================\n");
	printf("请输入选择:");
}
//用户彩票信息
void lottery_menu(void){
	wellcome_menu();
	printf("  1.查看彩票信息  \n");
	printf("  2.购买彩票  \n");
	printf("  3.购买记录  \n");
	printf("  4.查看中奖信息  \n");
	printf("  5.兑奖  \n");
	printf("  0.退出  \n");
	printf("  ==================================\n");
	printf("请输入选择:");
}
//用户个人信息
void usr_menu(void){
	wellcome_menu();
	printf("  1.修改密码  \n");
	printf("  2.注销自己  \n");
	printf("  0.退出  \n");
	printf("  ==================================\n");
	printf("请输入选择:");

}
