#include "model.h"
#include <stdio.h>
#include "link2.h"
#include <string.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
//用户注册
int regUsr(Node *head){
	if(head==NULL){
		return -1;
	}
	Node *newNode = CreatNode();
	if(newNode==NULL){
		return -1;
	}
	char name[30]={};
	char pass[30]={};
	printf("请输入你需要注册的用户名:");
	scanf("%s",name);
	Node *cur=head->next;
	while(cur!=head){
		if(strcmp(cur->name,name)==0){
			return 1;
		}
		cur=cur->next;
	}
	printf("请输入6位数密码：");
	scanf("%s",pass);
	if(strlen(pass)==6){
		strcpy(newNode->pass,pass);	
	}else{
		return 2;
	}
	strcpy(newNode->name,name);
	InsertHead(head,newNode);
	return 0;
}
//用户登陆
Node *logUsr(Node *head){
	if(head==NULL){
		return NULL;
	}
	char name[24]={"\0"};
	printf("请输入用户名:");
	scanf("%s",name);
	char *pass=getpass("请输入用户密码：");
	Node *cur=head->next;
	while(cur != head){
		if((strcmp(cur->name,name)==0)\
			&&(strcmp(cur->pass,pass)==0)){
			return cur;
		}	
		cur=cur->next;
	}	
	return NULL;
}
//管理员登陆
int admin(void){
	char name[24]="admin";
	char pass[24]="123456";
	char name1[24]={"\0"};
	printf("请输入管理员名：");
	scanf("%s",name1);
	char *pass1=getpass("请输入密码：");
	if(strcmp(name,name1)==0&&strcmp(pass,pass1)==0){
		return 1;	
	}else{
		return -1;	
	}	
}
//清空缓存
void myfflush(void){
	int ch=0;
	while(((ch=getchar()))!='\n' && (ch != EOF));
}
//回车继续
void push_continue(void){
	printf("按回车继续...\n");
	getchar();
}
//用户充值
int Usrcharge(Node *my){
	double money=0;
	printf("请输入充值金额：");
	scanf("%lf",&money);
	if(money<0){
		return 2;	
	}
	char *p1="ABCDEFGHIJKLMNOPQRST1234567890";
	char code[7]={};
	int i;
	srand((unsigned long)time(NULL));
	for(i=0;i<6;i++){
		code[i]=p1[rand()%30];
	}
	code[i]='\0';
	printf("%s\n",code);
	printf("请输入验证码:");
	char mycode[7]={};
	scanf("%s",mycode);
	if(strcmp(mycode,code)!=0){
		return 1;
	}
	my->money=my->money+money;
	return 0;	
}
//查看用户信息
void showMyself(Node *my){
	printf("\n----------\n");
	printf("name:%s\n",my->name);
	printf("pass:%s\n",my->pass);
	printf("money:%lf\n",my->money);
	printf("----------\n");
}
//修改密码
int changepass(Node *my){
	char pass[24]={"\0"};
	char pass1[24]={};
	char pass2[24]={};
	printf("请输入当前密码：");
	scanf("%s",pass);
	if(strcmp(my->pass,pass)==0){
		printf("请输入新的密码：");
		scanf("%s",pass1);
		printf("请再次输入你的新密码：");
		scanf("%s",pass2);
		if(strcmp(pass2,pass1)==0){
			strcpy(my->pass,pass2);
			printf("%s",my->pass);
			return 0;
		}else{
			return 1;		
		}
	}else{
		return 2;	
	}
	return 0;
}
//注销自己
int delMyself(Node *head,Node *my){
	return DelList(head,my,DelByName);
}

//发布彩票
int getlotter(Lotter *lhead){
	if(lhead==NULL){
		return -1;
	}
	Lotter *newLotter=CreatLotter();
		if(newLotter==NULL){
			return -1;
		}
	unsigned int data=0;
	printf("彩票期号：");
	scanf("%d",&data);
	Lotter *cur=lhead->next;
	while(cur!=lhead){
		if(cur->data==data){
			return 1;
		}
		cur=cur->next;
	}
	newLotter->data=data;
	printf("彩票单价：");
	scanf("%lf",&(newLotter->lott_money));
	newLotter->open='n';
	newLotter->sum=0;
	newLotter->sum1=0;
	InsertlotterHead(lhead,newLotter);
	return 0;
}
//管理员查看彩票信息
void showAllLotter(Lotter *lhead){
	ShowLotterList(lhead);
}
//用户查看彩票信息
void usrshowAlllotter(Lotter *lhead){
	ShowLottList(lhead);
}
//用户查看当前正在发售的彩票
void showcurlotter(Lotter *lhead){
	Lotter *cur=lhead->next;
	while(cur!=lhead){
		if(cur->open=='n'){
			printf("当前正在发售的彩票为：%d\n",cur->data);
			printf("----------------------------------\n");
		}
		cur=cur->next;
	}
}		
//购买彩票
int buylotter(Node *my,Lotter *lhead,Buy_lott *bhead){
	int i=0;
	char s[16]={"\0"};
	if(bhead==NULL){
		return -1;
	}
	if(lhead==NULL){
		return -1;	
	}
	if(my==NULL){
		return -1;
	}
	Buy_lott *newBuy_lott=CreatBuy_lott();
		if(newBuy_lott==NULL){
			return -1;
		}
	InsertlottHead(bhead,newBuy_lott);
	Lotter *cur=lhead->next;
	printf("请输入需要购买的彩票期号：");
	scanf("%d",&(newBuy_lott->data));
	while(cur!=lhead){
		if(cur->data==newBuy_lott->data){
			break;
		}
		cur=cur->next;
	}
	if(cur->data!=newBuy_lott->data){
		newBuy_lott->prev->next=newBuy_lott->next;
		newBuy_lott->next->prev=newBuy_lott->prev;
		free(newBuy_lott);
		return 0;
	}
	if(cur->open=='y'){
		newBuy_lott->prev->next=newBuy_lott->next;
		newBuy_lott->next->prev=newBuy_lott->prev;
		free(newBuy_lott);
		return 3;
	}
	if(cur->data==newBuy_lott->data){
		strcpy(newBuy_lott->name,my->name);
		int ch=0;
		char lotternum[16]={};
		printf("请输入你想要购买彩票的方式1.自选彩票 2.机选彩票:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("请输入你需要买的彩票号码(1位)：");
				scanf("%s",lotternum);
				if(strlen(lotternum)==1){
					strcpy(newBuy_lott->num,lotternum);
				}else{
					newBuy_lott->prev->next=newBuy_lott->next;
					newBuy_lott->next->prev=newBuy_lott->prev;
					free(newBuy_lott);
					return 4;
				}
				break;
			case 2:
				srand((unsigned)time(NULL));
				i = rand()%10;
				sprintf(s,"%d",i);
				printf("随机产生的彩票号码为:%s",strcpy(newBuy_lott->num,s));
				break;
			default:
				printf("无此选项!\n");
			}
		time_t timer=time(NULL);
		strcpy(newBuy_lott->date,ctime(&timer));
		printf("请输入你需要买的注数：");
		scanf("%d",&(newBuy_lott->n));
		int k=0;
		srand((unsigned)time(NULL));
		k=rand()%1000;
		newBuy_lott->mark=k;
	}
	if(((my->money)-(cur->lott_money)*(newBuy_lott->n))<0){
		newBuy_lott->prev->next=newBuy_lott->next;
		newBuy_lott->next->prev=newBuy_lott->prev;
		free(newBuy_lott);
		return 2;
	}
	strcpy(newBuy_lott->name,my->name);
	my->money=(my->money)-(cur->lott_money)*(newBuy_lott->n);
	return 1;
}
//查看购买记录
int showBuy_lott(Node *my,Lotter *lhead,Buy_lott *bhead){
	if(bhead==NULL){
		return -1;
	}
	if(lhead==NULL){
		return -1;	
	}
	if(my==NULL){
		return -1;
	}
	Buy_lott *cur=bhead->next;
	while(cur!=bhead){
		if(strcmp(my->name,cur->name)==0){
			printf("你购买的彩票期号为：%d\n",cur->data);
			printf("你购买的彩票号码为：%s\n",cur->num);
			printf("你购买的注数为：%d\n",cur->n);
			printf("购买时间为：%s\n",cur->date);
			printf("本期彩票识别码为：%d\n",cur->mark);
			printf("================================\n");
		}
	cur=cur->next;
	}
	getchar();
	push_continue();
	return 0;
}
//开奖
int openlotter(Node *head,Lotter *lhead,Buy_lott *bhead){
	if(bhead==NULL){
		return -1;
	}
	if(lhead==NULL){
		return -1;	
	}
	if(head==NULL){
		return -1;
	}
	int ch=0;
	printf("请输入开奖期号：");
	scanf("%d",&ch);
	Lotter *cur=lhead->next;
	Buy_lott *cur1=bhead->next;
	while(cur!=lhead){
		if(cur->data==ch){
			break;
		}
		cur=cur->next;
	}
	if(cur->data!=ch){
		return 1;
	}
	if(cur->data==ch){
		if(cur->open=='y'){
			return 2;	
		}
		int i=0;
		char s[16]={};
		srand((unsigned)time(NULL));
		i = rand()%10;
		sprintf(s,"%d",i);
		printf("本期开奖号码为:%s",strcpy(cur->num,s));
	}
	while(cur1!=bhead){
		if(cur1->data==ch){
			cur->sum=cur->sum+cur1->n;
		}
		cur1=cur1->next;		
	}
	cur->money=(cur->lott_money)*(cur->sum);//奖池金额
	while(cur1!=bhead){
		if(strcmp(cur1->num,cur->num)==0){
			cur->sum1=(cur->sum1)+(cur1->n);
		}
			cur1=cur1->next;
	}
	cur->making=(cur->lott_money)*(cur->sum)-(cur->lott_money)*(cur->sum)*0.2*(cur->sum1);
	cur->money=(cur->money)-(cur->lott_money)*(cur->sum1);
	cur->open='y';
	return 0;
}
//查看彩票收入
int makinglotter(Lotter *lhead){
	if(lhead==NULL){
		return -1;	
	}
	Lotter *cur=lhead->next;	
	while(cur!=lhead){
		if(cur->open=='y'){
			printf("已开奖第%d期彩票收入为：%0.2lf\n",cur->data,cur->making);
		}
	cur=cur->next;	
	}
	getchar();
	push_continue();
	return 0;
}
//查看彩民信息
void showallusr(Node *head,Buy_lott *bhead){
	Node *cur=head->next;
	Buy_lott *cur2=bhead->next;
	while(cur!=head){
		while(cur2!=bhead){
			if(strcmp(head->name,bhead->name)==0){
			printf("=========================================================================\n");
			printf("用户名为：%s  的用户账户余额为：%0.2lf 购买的彩票期号为： %d 购买注数为： %d 彩票识别码：%d  \n",cur->name,cur->money,cur2->data,cur2->n,cur2->mark);
			printf("=========================================================================\n");
			}
			cur2=cur2->next;
		}
		cur=cur->next;		
	}
	getchar();
	push_continue();
}
//管理员查看所有用户信息
void showAll(Node *head){
	ShowList(head);
}
//管理员按照金额给用户排序
void mymoneySort(Node *head){
	Node *my;
	MySort(head,compar);
	Node *cur=head->next;
	while(cur != head){
		if((strcmp(cur->name,my->name)==0)&&(strcmp(cur->pass,my->pass)==0)){
			my=cur;
			break;
		}	
		cur=cur->next;
	}	
}

//用户查看自己购买彩票是否中奖
void showgetlotter(Node *my,Lotter *lhead,Buy_lott *bhead){
	Lotter *cur=lhead->next;
	Buy_lott *cur1=bhead->next;
	while(cur!=lhead){
		while(cur1!=bhead){
			if(strcmp(cur1->name,my->name)==0){
				if(strcmp(cur1->num,cur->num)==0){
					printf("你中奖的彩票期号位：%d，中奖注数为：%d 中奖金额为：%0.2lf 中奖彩票识别码：%d\n",cur1->data,cur1->n,(cur1->n)*(cur->lott_money),cur1->mark);
				}
			}
			cur1=cur1->next;
		}
		cur=cur->next;
	}
}

//删除已开奖彩票
int delopenlotter(Lotter *lhead){
	if(lhead==NULL){
		return -1;	
	}
	int deldata=0;
	printf("请输入你想要删除的已开奖彩票的期号：");
	scanf("%d",&deldata);
	Lotter *cur=lhead->next;
	while(cur!=lhead){
		if(cur->data==deldata){
			break;
		}
		cur=cur->next;
	}
	if(cur->data!=deldata){
		return 1;	
	}
	if(cur->open=='n'){
		return 2;
	}
	if(cur->data==deldata){
		cur->next->prev=cur->prev;
		cur->prev->next=cur->next;	
	}
	free(cur);
	return 0;	
}
/*
//中奖级别
int lottclass(Lotter *lhead,Buy_lott *bhead){
	Lotter *cur=lhead;
	Buy_lott *cur1=bhead;
	while(cur!=lhead){
		while(cur1!=bhead){
			if(cur1->data==cur->data&&cur->open=='y'){
				if(strcmp(cur1->num[1],cur->num[1]){

					}
			}
		}
	}
}
*/

//兑奖
void exchangelott(Node *my,Lotter *lhead,Buy_lott *bhead){
	if(bhead==NULL){
		return;
	}
	if(lhead==NULL){
		return;	
	}
	unsigned int mark=0;
	printf("请输入兑奖彩票识别码：");
	scanf("%d",&mark);
	Lotter *cur=lhead->next;
	Buy_lott *cur1=bhead->next;
	while(cur1!=bhead){
		if(cur1->mark==mark){
			break;
		}
		cur1=cur1->next;
	}
	while(cur!=lhead){
		if(cur1->data==cur->data){
			while(cur1!=bhead){
				if(strcmp(cur1->name,my->name)==0){
					if(strcmp(cur1->num,cur->num)==0){
						my->money=(my->money)+(cur->lott_money)*(cur->sum)*0.2*(cur1->n);
					}
				}
				cur1=cur1->next;
			}
		}
		cur=cur->next;
	}
}	
