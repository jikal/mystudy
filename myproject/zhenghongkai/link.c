#include "link.h"
//创建链表头节点
Node *head;
Daily *dhead;
clientinfo *ihead;
Node *my;
//用户信息链表头插法
int InsertHead(Node *newNode){
	if(head==NULL || newNode==NULL)
		return -1;
	newNode->prev=head;
	newNode->next=head->next;
	head->next->prev=newNode;
	head->next=newNode;
	return 0;
}
//日志链表头插法
int InsertdHead(Daily *newDaily){
	if(dhead==NULL || newDaily==NULL)
		return -1;
	newDaily->prev=dhead;
	newDaily->next=dhead->next;
	dhead->next->prev=newDaily;
	dhead->next=newDaily;
	return 0;
}
//登陆用户信息头茬法
int InsertiHead(clientinfo *newclientinfo){
	if(ihead==NULL || newclientinfo==NULL)
		return -1;
	newclientinfo->prev=ihead;
	newclientinfo->next=ihead->next;
	ihead->next->prev=newclientinfo;
	ihead->next=newclientinfo;
	return 0;
}
//保存用户信息
int SaveList(const char *pathname){
	if(head==NULL || pathname==NULL)
		return -1;
	FILE *fp=fopen(pathname,"wb");
	if(fp==NULL){
		return -1;
	}
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
//读取用户信息
int ReadList(const char *pathname){
	if(head==NULL || pathname==NULL)
		return -1;
	FILE *fp=fopen(pathname,"rb");
	if(fp==NULL)
		return -1;
	Node* newNode = calloc(1,sizeof(Node));
	while(fread(newNode,sizeof(Node),1,fp)>=1){
		InsertHead(newNode);
		newNode = calloc(1,sizeof(Node));
	}
	free(newNode);
	fclose(fp);
	return 0;
}
//保存日志文件
int savedaliyList(const char *pathname){
	if(dhead==NULL || pathname==NULL)
		return -1;
	FILE *fp=fopen(pathname,"w");
	if(fp==NULL) return -1;
	Daily *cur=dhead->next;
	while(cur!=dhead){
		if(1!=fwrite(cur,sizeof(Daily),1,fp)){
			return -1;
		}
		cur=cur->next;
	}
	fclose(fp);
	return 0;
}
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
void DestraydailyList(Daily *dhead){
	Daily *cur=dhead->next;
	Daily *del=NULL;
	while(cur!=dhead){
		del=cur->next;
		free(cur);
		cur=del;
	}
	dhead->prev=dhead;
	dhead->next=dhead;
}
void DestrayinfoList(clientinfo *head){
	clientinfo *cur=ihead->next;
	clientinfo *del=NULL;
	while(cur!=ihead){
		del=cur->next;
		free(cur);
		cur=del;
	}
	ihead->prev=ihead;
	ihead->next=ihead;
}
