#ifndef _CONTROL_H_
#define _CONTROL_H_
#include "link2.h"
extern Node *my;
extern void mainControl(Node *head,Lotter *lhead,Buy_lott *bhead);
extern void usrControl(Node *head,Lotter *lhead,Buy_lott *bhead);
extern void adminControl(Node *head,Lotter *lhead,Buy_lott *bhead);
extern void usr_infoControl(Node *head,Lotter *lhead,Buy_lott *bhead);
extern void usr_lotterControl(Node *my,Lotter *lhead,Buy_lott *bhead);
extern void admin_showControl(Node *head,Lotter *lhead,Buy_lott *bhead);
#endif
