#include <stdio.h>
#include "link2.h"
#include "control.h"
#include "stdlib.h"
Node *my=NULL;
int main(){
	Node *head=CreatHead();
	if(head==NULL){
		return -1;
	}
	Lotter *lhead=Creatlotterhead();
	if(lhead==NULL){
		return -1;
	}
	Buy_lott *bhead=Creatlotthead();
	if(bhead==NULL){
		return -1;
	}
	//文件读取	
 	ReadList(head,"./link.txt");
	ReadLotterList(lhead,"./link.txt1");
	ReadBuy_LottList(bhead,"./link.txt2");
	mainControl(head,lhead,bhead);
	//文件保存
	SaveList(head,"./link.txt");
	SaveLotterList(lhead,"./link.txt1");
	SaveBuy_LottList(bhead,"./link.txt2");
	DestrayList(head);
	free(head);
	head=NULL;
	DestrayLotterList(lhead);
	free(lhead);
	lhead=NULL;
	DestrayBuy_lottList(bhead);
	free(bhead);
	bhead=NULL;
	return 0;
}
