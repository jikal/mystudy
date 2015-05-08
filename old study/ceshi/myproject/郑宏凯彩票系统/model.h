#ifndef _MODEL_H_
#define _MODEL_H_
#include "link2.h"
extern void myfflush(void);
extern int regUsr(Node *head);
extern Node *logUsr(Node *head);
extern int admin(void);
extern void push_continue(void);
extern void showAll(Node *head);
extern void showMyself(Node *my);
extern int Usrcharge(Node *my);
extern int changepass(Node *my);
extern int delMyself(Node *head,Node *my);
extern int getlotter(Lotter *lhead);
extern void showAllLotter(Lotter *lhead);
extern void usrshowAlllotter(Lotter *lhead);
extern int buylotter(Node *my,Lotter *lhead,Buy_lott *bhead);
extern int showBuy_lott(Node *my,Lotter *lhead,Buy_lott *bhead);
extern int openlotter(Node *head,Lotter *lhead,Buy_lott *bhead);
extern int makinglotter(Lotter *lhead);
extern void showallusr(Node *head,Buy_lott *bhead);
extern void mymoneySort(Node *head);
extern void showcurlotter(Lotter *lhead);
extern void showgetlotter(Node *my,Lotter *lhead,Buy_lott *bhead);
extern int delopenlotter(Lotter *lhead);
extern void exchangelott(Node *my,Lotter *lhead,Buy_lott *bhead);
#endif
