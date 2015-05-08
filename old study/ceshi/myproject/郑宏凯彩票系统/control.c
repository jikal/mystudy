#include "control.h"
#include "view.h"
#include <stdio.h>
#include "model.h"
#include<unistd.h>
#include <string.h>
#include<stdlib.h>
void mainControl(Node *head,Lotter *lhead,Buy_lott *bhead){
	while(1){
		reg_menu();
		int ret=1;
		int ch=0;
		scanf("%d",&ch);
		int a=0;
		switch(ch){
			case 1://注册
				a=regUsr(head);
				if(a==1){
					printf("你所注册的用户名已存在！请输入其他用户名！\n");
					getchar();
					push_continue();
				}
				else if(a==2){
					printf("你输入的密码长度不符合要求！请重新输入！\n");
					getchar();
					push_continue();
				}
			
				else if(a==0){
					printf("注册成功，请登陆！\n");
					getchar();
					push_continue();
				}
				break;
			case 2://登入
				my=logUsr(head);
				if(my!=NULL){
					printf("登入成功！\n");
					getchar();
					push_continue();
					usrControl(my,lhead,bhead);
				}else{
					printf("登入失败!\n");
					getchar();
					push_continue();
				}
				break;
			case 3://管理员登陆
				ret=admin();
				if(ret==1){
					printf("管理员登陆成功！\n");
					getchar();
					push_continue();
					adminControl(head,lhead,bhead);
				}
				else{
					printf("管理员登陆失败!\n");
					getchar();
					push_continue();	
				}
				break;
			case 0:
				return;
			default:
				printf("无此选项!\n");
		}
	}
}
//用户控制函数
void usrControl(Node *head,Lotter *lhead,Buy_lott *bhead){
	while(1){
		log_menu();	
		int ch=0;
		scanf("%d",&ch);
		int charge=0;
		switch(ch){
			case 1://修改个人信息
				usr_infoControl(head,lhead,bhead);
				return;	
				break;
			case 2://充值
				charge=Usrcharge(my);
				if(charge==0){
					printf("充值成功！\n");
					getchar();
					push_continue();
				}
				else if(charge==1){
					printf("验证码输入错误，充值失败！\n");
					getchar();
					push_continue();
				}
				else if(charge==2){
					printf("你的输入不正确！\n");
					getchar();
					push_continue();
				}
				break;
			case 3://彩票信息
				usr_lotterControl(my,lhead,bhead);
				break;
			case 4://查看个人详情
				showMyself(my);
				getchar();
				push_continue();
				break;
			case 0:
				return;
			default:
				printf("无此选项!\n");
		}
	}
}
//管理员控制函数
void adminControl(Node *head,Lotter *lhead,Buy_lott *bhead){
	while(1){
		admin_menu();
		int n=0;
		scanf("%d",&n);
		int ret =0;
		int r=0;
		int deldata=0;
		switch(n){
			case 1://发布彩票
				ret=getlotter(lhead);
				if(ret==0){
					printf("发布成功！\n");
					getchar();
					push_continue();	
				}else if(ret==1){
					printf("发布失败,你所发布的期号已存在！\n");
					getchar();
					push_continue();
				}
				break;
			case 2://开奖
				showcurlotter(lhead);
				r=openlotter(head,lhead,bhead);
				if(r==0){
					printf("开奖成功！\n");
					getchar();
					push_continue();	
				}
				else if(r==1){
					printf("你所开奖的期号不存在！\n");
					getchar();
					push_continue();	
				}
				else if(r==2){
					printf("你当前所选择的期号之前已开奖！\n");
					getchar();
					push_continue();	
				}
				break;
			case 3://查看彩票
				showAllLotter(lhead);
				getchar();
				push_continue();
				break;
			case 4://查看彩票收入
				makinglotter(lhead);
				break;
			case 5://查询信息
				admin_showControl(head,lhead,bhead);
				break;
			case 6://删除已开奖彩票
				deldata=delopenlotter(lhead);
				if(deldata==1){
					printf("你要删除的期号不存在！");
					getchar();
					push_continue();
				}
				else if(deldata==2){
					printf("你要删除的期号尚未开奖，不可以删除！");
					getchar();
					push_continue();
				}
				else if(deldata==0){
					printf("删除成功！");
					getchar();
					push_continue();
				}
				break;
			case 0:
				return;
			default:
				printf("无此选项!\n");
		}
	}
}
//用户个人信息控制函数
void usr_infoControl(Node *head,Lotter *lhead,Buy_lott *bhead){	
	while(1){
		usr_menu();	
		int ch=0;
		scanf("%d",&ch);
		int l=0;
		switch(ch){
			case 1://修改密码
				l=changepass(my);
				if(l==0){
					printf("密码修改成功!请重新登陆\n");
					getchar();
					push_continue();
					return;				
				}
				else if(l==1){
					printf("你两次输入的密码不一样，修改失败！\n");
					getchar();
					push_continue();
				}
				else if(l==2){
					printf("原始密码输入错误，修改失败！\n");
					getchar();
					push_continue();
				}
				break;
			case 2://注销自己
				delMyself(head,my);
				return;
			case 0:
				return;
			default:
				printf("无此选项!\n");
		}
	}
}
//用户购买彩票
void usr_lotterControl(Node *my,Lotter *lhead,Buy_lott *bhead){
	while(1){
		lottery_menu();
		int ch=0;
		scanf("%d",&ch);
		int ret=0;
		switch(ch){
			case 1://查看彩票发布信息
				usrshowAlllotter(lhead);
				getchar();
				push_continue();
				break;
			case 2://购买彩票
				showcurlotter(lhead);
				ret=buylotter(my,lhead,bhead);
				if(ret==1){
					printf("购买成功！\n");
					getchar();
					push_continue();	
				}
				else if(ret==2){
					printf("余额不足请先充值！\n");
					getchar();
					push_continue();	
				}
				else if(ret==3){
					printf("你所购买的期号已开奖！\n");
					getchar();
					push_continue();
				}
				else if(ret==0){
					printf("你所购买的彩票期号不存在：\n");
					getchar();
					push_continue();
				}
				else if (ret==4){
					printf("你选择的彩票号码不符合要求，请重新购买！\n");
					getchar();
					push_continue();
				}
				break;
			case 3://购买记录
				showBuy_lott(my,lhead,bhead);
				break;
			case 4://中奖信息
				showgetlotter(my,lhead,bhead);
				getchar();
				push_continue();
				break;
			case 5://兑奖
				exchangelott(my,lhead,bhead);
				getchar();
				push_continue();
				break;
			case 0:
				return;
			default:
				printf("无此选项!\n");
		}
	}
}

void admin_showControl(Node *head,Lotter *lhead,Buy_lott *bhead){
	while(1){
		checklotter_menu();
		int ch=0;
		scanf("%d",&ch);
		switch(ch){
			case 1://查看彩民信息
				showAll(head);
				getchar();
				push_continue();
				break;
			case 2://按金额排序
				mymoneySort(head);
				getchar();
				push_continue();
				break;
			case 3://查询用户购买记录
				showallusr(head,bhead);
				break;
			case 0:
				return;
			default:
				printf("无此选项!\n");
		}
	}
}	
