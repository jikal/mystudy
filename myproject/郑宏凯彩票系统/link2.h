#ifndef _LINK2_H_
#define _LINK2_H_

typedef struct use_t{
	char name[30];//用户名
	char pass[30];//密码
	double money;//余额
	struct use_t *prev;
	struct use_t *next;//指针
}Node;

typedef struct lotter{      
	char open;      //开奖与否
	char num[16];   //开奖号码
	unsigned int data; //彩票期号
	double money;  //奖池金额
	double making;  //当期盈利
	double lott_money; //彩票单价
	unsigned int sum;//彩票销售总数
	unsigned int sum1;//当期彩票中奖人数
	struct lotter *prev;
	struct lotter *next;  //后继指针
}Lotter;

typedef struct buy_lott{
	char num[16];    //购彩号码
	char name[30];   //购彩用户
	char date[30]; //彩票日期
	unsigned int data;//需要购买的彩票期号
	unsigned int mark; //当前购彩识别码
	unsigned int n;//购买注数
	struct buy_lott *prev;
	struct buy_lott *next; //后继指针 
}Buy_lott;

extern int DelByName(Node *p1,Node *p2);
extern Node *CreatHead(void);
extern int InsertHead(Node *head,Node *newNode);
extern int SizeList(Node *head);
extern void ShowList(Node *head);
extern Node *CreatNode(void);
extern void DestrayList(Node *head);
extern int DelList(Node *head,Node *e,\
	int (*f)(Node *,Node *));
extern int SaveList(Node *head,const char *pathname);
extern int ReadList(Node *head,const char *pathname);
extern void MySort(Node *head,int (*compar)(const void *,const void *));
extern int compar(const void *p1,const void *p2);
extern Lotter *Creatlotterhead(void);
extern int InsertlotterHead(Lotter *lhead,Lotter *newLotter);
extern int Sizelotterlist(Lotter *lhead);
extern int InsertlotterIndex(Lotter *lhead,Lotter *newLotter,int index);
extern void ShowLotterList(Lotter *lhead);
extern Lotter *CreatLotter(void);
extern Buy_lott *Creatlotthead(void);
extern int InsertlottHead(Buy_lott *bhead,Buy_lott *newBuy_lott);
extern Buy_lott *CreatBuy_lott(void);
extern void ShowLottList(Lotter *lhead);
extern int SaveBuy_LottList(Buy_lott *bhead,const char *pathmark);
extern int ReadBuy_LottList(Buy_lott *bhead,const char *pathmark);
extern int SaveLotterList(Lotter *lhead,const char *pathdata);
extern int ReadLotterList(Lotter *lhead,const char *pathdata);
extern void DestrayLotterList(Lotter *lhead);
extern void DestrayBuy_lottList(Buy_lott *bhead);
#endif




