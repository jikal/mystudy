#include "link2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
	函数功能：创建头节点并初化
	函数参数：无
	返回指  ：成功返回堆地址 失败返回NULL

*/
Node *CreatHead(void){
	Node *head=(Node *)calloc(1,sizeof(Node));
	if(NULL == head){
		return NULL;
	}else{
		head->next=head;
		head->prev=head;
	}
	return head;

}
/*
	函数功能：头插法
	函数参数：head_头节点 newNode_新节点 
	返回指  ：成功_0 失败_-1

*/
int InsertHead(Node *head,Node *newNode){
	if(head==NULL || newNode==NULL)
		return -1;
	newNode->prev=head;
	newNode->next=head->next;
	head->next->prev=newNode;
	head->next=newNode;
	return 0;
}
/*
	函数功能：链表长度
	函数参数：head_头节点 
	返回指  ：返回链表节点个数

*/
int SizeList(Node *head){
	Node *cur=head->next;
	int count=0;
	while(cur!=head){
		count++;
		cur=cur->next;
	}
	return count;
}
//回调函数
static void ShowStu(const Node *e){
	printf("name:%10s,pass:%10s,money:%5.2lf\n",\
		e->name,e->pass,e->money);
}
/*
	函数功能：查看链表
	函数参数：head_头节点 
	返回指  ：无

*/
void ShowList(Node *head){
	Node *cur=head->next;
	while(cur!=head){
		ShowStu(cur);
		cur=cur->next;
	}
	printf("\n");
}
/*
	函数功能：创建一个节点
	函数参数：head_头节点 
	返回指  ：无

*/
Node *CreatNode(void){
	Node *newNode = (Node *)calloc(1,sizeof(Node));
	if(newNode == NULL) return NULL;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;	
}
/*
	函数功能：销毁除头节点以外的链表元素 并初始化头节点
	函数参数：head_头节点 
	返回指  ：无

*/
void DestrayList(Node *head){
	Node *cur=head->next;
	Node *del=NULL;
	while(cur!=head){
		del=cur->next;
		free(cur);
		cur=del;
	}
	head->prev=head;
	head->next=head;
}
int DelByName(Node *p1,Node *p2){
	return strcmp(p1->name,p2->name);
}
/*
	函数功能：根据数据删除节点
	函数参数：head_头节点 ,e_要删除的数据,f_回调函数
	返回值  ：0_删除成功 -1_删除失败

*/
int DelList(Node *head,Node *e,int (*f)(Node *,Node *)){
	if(head==NULL || e==NULL)return -1;
	Node *cur=head->next;
	Node *del=NULL;
	while(cur!=head){
		if(((*f)(cur,e))==0){
			del=cur->next;
			cur->prev->next=cur->next;
			cur->next->prev=cur->prev;
			free(cur);
			cur=del;
		}else{
			cur=cur->next;
		}
	}
	return 0;
}

/*
	函数功能：链表写入文件
	函数参数：head_头节点 pathname_文件名
	返回值  ：0_成功 -1_失败
*/
int SaveList(Node *head,const char *pathname){
	if(head==NULL || pathname==NULL)
		return -1;
	FILE *fp=fopen(pathname,"wb");
	if(fp==NULL) return -1;
	Node *cur=head->next;
	while(cur!=head){
		if(1!=fwrite(cur,sizeof(Node),1,fp)){
			return -1;
		}
		cur=cur->next;
	}
	fclose(fp);
	return 0;
}
/*
	函数功能：文件中读取链表
	函数参数：head_头节点 pathname_文件名
	返回值  ：0_成功 -1_失败
*/
int ReadList(Node *head,const char *pathname){
	if(head==NULL || pathname==NULL)
		return -1;
	FILE *fp=fopen(pathname,"rb");
	if(fp==NULL)
		return -1;
	Node *newNode = (Node *)calloc(1,sizeof(Node));
	if(1!=fread(newNode,sizeof(Node),1,fp)){
		free(newNode);			
		return -1;
	}
	newNode->prev=NULL;
	newNode->next=NULL;
	InsertHead(head,newNode);	
	if(newNode==NULL) return -1;
	while(!feof(fp)){
		newNode = (Node *)calloc(1,sizeof(Node));
		if(newNode==NULL) return -1;
		if(1!=fread(newNode,sizeof(Node),1,fp)){
			free(newNode);			
			return -1;
		}
		newNode->prev=NULL;
		newNode->next=NULL;
		InsertHead(head,newNode);	
	}
	//free(newNode);
	fclose(fp);
	return 0;
}
int compar(const void *p1,const void *p2){
	Node *n1=(Node *)p1;
	Node *n2=(Node *)p2;
	if(n1->money > n2->money)return 1;
	else if(n1->money < n2->money)return -1;
	else return 0;
}
/*int compar1(const void *p1,const void *p2){
	Node *n1=(Node *)p1;
	Node *n2=(Node *)p2;
	return (n2->data)-(n1->data);
}*/
/*
	函数功能：单向链表排序
	函数参数：head_头节点 compar_函数指针
	返回值  ：无
*/
void MySort(Node *head,\
		int (*compar)(const void *,const void *)){
	if(head==NULL || compar==NULL)
		return ;
	//求出链表长度
	int len = SizeList(head);
	//创建数组
	Node *arr = (Node *)calloc(len,sizeof(Node));
	if(arr==NULL) return ;
	//将链表转换为数组
	Node *cur=(head)->next;
	int i=0;
	while(cur != head){
		*(arr+i)=*(cur);
		cur=cur->next;
		i++;
	}
	
	DestrayList(head);
	qsort(arr,len,sizeof(Node),compar);
	for(i=0;i<len;i++){
		Node *newNode=(Node *)calloc(1,sizeof(Node));
		if(newNode==NULL) return;
		*newNode=*(arr+i);
		if(0!=InsertHead(head,newNode)){
			printf("error:%d\n",i);
		}
	}
	free(arr);
}
/*
	函数功能：创建彩票头节点并初化
	函数参数：无
	返回指  ：成功返回堆地址 失败返回NULL

*/
Lotter *Creatlotterhead(void){
	Lotter *lhead=(Lotter *)calloc(1,sizeof(Lotter));
	if(NULL == lhead){
		return NULL;	
	}else{
		lhead->next=lhead;
		lhead->prev=lhead;	
	}
	return lhead;
}
/*
	函数功能：彩票头插法
	函数参数：lhead_头节点 newLotter_新节点 
	返回指  ：成功_0 失败_-1

*/
int InsertlotterHead(Lotter *lhead,Lotter *newLotter){
	if(lhead==NULL|| newLotter==NULL){
		return -1;
	}
	newLotter->prev=lhead;
	newLotter->next=lhead->next;
	lhead->next->prev=newLotter;
	lhead->next=newLotter;
	return 0;
}
/*
	函数功能：彩票链表长度
	函数参数：lhead_头节点 
	返回指  ：返回链表节点个数

*/
int Sizelotterlist(Lotter *lhead){
	Lotter *cur=lhead->next;
	int count=0;
	while(cur!=lhead){
		count++;
		cur=cur->next;	
	}
	return count;
}
/*
	函数功能：根据彩票信息下标插入节点
	函数参数：lhead_头节点 ,newLotter_新节点
		index_下标
	返回指  :0_插入成功 -1_失败

*/
int InsertlotterIndex(Lotter *lhead,Lotter *newLotter,int index){
	if(index>Sizelotterlist(lhead)|| index<0){
		return -1;		
	}
	if(lhead==NULL||newLotter==NULL){
		return -1;	
	}
	Lotter *cur=lhead;
	while(index!=0){
		index--;	
		cur=cur->next;
	}
	newLotter->prev=cur;
	newLotter->next=cur->next;
	cur->next->prev=newLotter;
	cur->next=newLotter;
	return 0;
}
static void ShowLotter(const Lotter *e){
	printf("彩票期号：%5d彩票单价：%5.2lf是否开奖：%5c开奖号码：%5s当期盈利：%5.2lf奖池金额：%5.2lf\n",e->data,e->lott_money,e->open,e->num,e->making,e->money);
}
/*
	函数功能：管理员查看彩票链表
	函数参数：lhead_头节点 
	返回指  ：无

*/
void ShowLotterList(Lotter *lhead){
	Lotter *cur=lhead->next;
	while(cur!=lhead){
		ShowLotter(cur);
		cur=cur->next;
	}
	printf("\n");
}
static void ShowLott(const Lotter *e){
	printf("=========================================\n");
	printf("彩票期号：%5d彩票单价：%5.2lf是否开奖：%5c\n",e->data,e->lott_money,e->open);
	printf("=========================================\n");
}
//用户查看彩票链表
void ShowLottList(Lotter *lhead){
	Lotter *cur=lhead->next;
	while(cur!=lhead){
		ShowLott(cur);
		cur=cur->next;	
	}
	printf("\n");
}
/*
	函数功能：创建彩票一个节点
	函数参数：head_头节点 
	返回指  ：无

*/
Lotter *CreatLotter(void){
	Lotter *newLotter=(Lotter *)calloc(1,sizeof(Lotter));
	if(newLotter==NULL){
		return NULL;
	}
	newLotter->next=NULL;
	newLotter->prev=NULL;
	return newLotter;
}
/*
	函数功能：彩票链表写入文件
	函数参数：head_头节点 pathname_文件名
	返回值  ：0_成功 -1_失败
*/
int SaveLotterList(Lotter *lhead,const char *pathdata){
	if(lhead==NULL || pathdata==NULL)
		return -1;
	FILE *fp=fopen(pathdata,"wb");//*(pathname+0)='a';
	if(fp==NULL){
	return -1;
	}
	Lotter *cur=lhead->next;
	while(cur!=lhead){
		if(1!=fwrite(cur,sizeof(Lotter),1,fp)){
			return -1;
		}
		cur=cur->next;
	}
	fclose(fp);
	return 0;
}
/*
	函数功能：彩票文件中读取链表
	函数参数：head_头节点 pathname_文件名
	返回值  ：0_成功 -1_失败
*/
int ReadLotterList(Lotter *lhead,const char *pathdata){
	if(lhead==NULL || pathdata==NULL)
		return -1;
	FILE *fp=fopen(pathdata,"rb");
	if(fp==NULL)
		return -1;
	Lotter *newLotter = (Lotter *)calloc(1,sizeof(Lotter));
	if(1!=fread(newLotter,sizeof(Lotter),1,fp)){
		free(newLotter);			
		return -1;
	}
	newLotter->prev=NULL;
	newLotter->next=NULL;
	InsertlotterHead(lhead,newLotter);	
	if(newLotter==NULL) return -1;
	while(!feof(fp)){
		newLotter = (Lotter *)calloc(1,sizeof(Lotter));
		if(newLotter==NULL){
			return -1;
		}
		if(1!=fread(newLotter,sizeof(Lotter),1,fp)){
			free(newLotter);			
			return -1;
		}
		newLotter->prev=NULL;
		newLotter->next=NULL;
		InsertlotterHead(lhead,newLotter);	
	}
	//free(newNode);
	fclose(fp);
	return 0;
}
/*
	函数功能：销毁除头节点以外的彩票链表元素 并初始化头节点
	函数参数：head_头节点 
	返回指  ：无

*/
void DestrayLotterList(Lotter *lhead){
	Lotter *cur=lhead->next;
	Lotter *del=NULL;
	//int count = 0;
	while(cur!=lhead){
		//printf("free:%d\n",count++);
		del=cur->next;
		free(cur);
		cur=del;
	}
	lhead->prev=lhead;
	lhead->next=lhead;
}
/*
	函数功能：创建购买彩票头节点并初化
	函数参数：无
	返回指  ：成功返回堆地址 失败返回NULL

*/
Buy_lott *Creatlotthead(void){
	Buy_lott *bhead=(Buy_lott *)calloc(1,sizeof(Buy_lott));
	if(NULL == bhead){
		return NULL;	
	}else{
		//初始化双向循环链表
		bhead->next=bhead;
		bhead->prev=bhead;	
	}
	return bhead;
}
/*
	函数功能：购买头插法
	函数参数：bhead_头节点 newBuy_lott_新节点 
	返回指  ：成功_0 失败_-1

*/
int InsertlottHead(Buy_lott *bhead,Buy_lott *newBuy_lott){
	if(bhead==NULL|| newBuy_lott==NULL){
		return -1;
	}
	newBuy_lott->prev=bhead;
	newBuy_lott->next=bhead->next;
	bhead->next->prev=newBuy_lott;
	bhead->next=newBuy_lott;
	return 0;
}
/*
	函数功能：创建购买一个节点
	函数参数：head_头节点 
	返回指  ：无

*/
Buy_lott *CreatBuy_lott(void){
	Buy_lott *newBuy_lott=(Buy_lott *)calloc(1,sizeof(Buy_lott));
	if(newBuy_lott==NULL){
		return NULL;
	}
	newBuy_lott->next=NULL;
	newBuy_lott->prev=NULL;
	return newBuy_lott;
}

/*
	函数功能：彩票购买链表写入文件
	函数参数：head_头节点 pathname_文件名
	返回值  ：0_成功 -1_失败
*/
int SaveBuy_LottList(Buy_lott *bhead,const char *pathmark){
	if(bhead==NULL || pathmark==NULL)
		return -1;
	FILE *fp=fopen(pathmark,"wb");//*(pathname+0)='a';
	if(fp==NULL){
	return -1;
	}
	Buy_lott *cur=bhead->next;
	while(cur!=bhead){
		if(1!=fwrite(cur,sizeof(Buy_lott),1,fp)){
			return -1;
		}
		cur=cur->next;
	}
	fclose(fp);
	return 0;
}
/*
	函数功能：彩票购买文件中读取链表
	函数参数：head_头节点 pathname_文件名
	返回值  ：0_成功 -1_失败
*/
int ReadBuy_LottList(Buy_lott *bhead,const char *pathmark){
	if(bhead==NULL || pathmark==NULL)
		return -1;
	FILE *fp=fopen(pathmark,"rb");
	if(fp==NULL)
		return -1;
	Buy_lott *newBuy_lott = (Buy_lott *)calloc(1,sizeof(Buy_lott));
	if(1!=fread(newBuy_lott,sizeof(Buy_lott),1,fp)){
		free(newBuy_lott);			
		return -1;
	}
	newBuy_lott->prev=NULL;
	newBuy_lott->next=NULL;
	InsertlottHead(bhead,newBuy_lott);	
	if(newBuy_lott==NULL) return -1;
	while(!feof(fp)){
		newBuy_lott = (Buy_lott *)calloc(1,sizeof(Buy_lott));
		if(newBuy_lott==NULL){
			return -1;
		}
		if(1!=fread(newBuy_lott,sizeof(Buy_lott),1,fp)){
			free(newBuy_lott);			
			return -1;
		}
		newBuy_lott->prev=NULL;
		newBuy_lott->next=NULL;
		InsertlottHead(bhead,newBuy_lott);	
	}
	//free(newNode);
	fclose(fp);
	return 0;
}
/*
	函数功能：销毁除头节点以外的购买彩票链表元素 并初始化头节点
	函数参数：head_头节点 
	返回指  ：无

*/
void DestrayBuy_lottList(Buy_lott *bhead){
	Buy_lott *cur=bhead->next;
	Buy_lott *del=NULL;
	//int count = 0;
	while(cur!=bhead){
		//printf("free:%d\n",count++);
		del=cur->next;
		free(cur);
		cur=del;
	}
	bhead->prev=bhead;
	bhead->next=bhead;
}
