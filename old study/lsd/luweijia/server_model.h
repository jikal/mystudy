#ifndef _SERVER_MODEL_H_
#define _SERVER_MODEL_H_

#include "server_control.h"

//服务器端判断注册是否成功
extern int check_reg_success(Proc *proc,Msg *msg);

//服务器端判断登录是否成功
extern int check_Log_Success(Proc *proc,Msg *msg);

//创建usr链表头节点
extern Usr *create_usr_head(void);

//创建daily链表头节点
extern Daily *create_daily_head(void);

//头插法插入Usr节点
extern int insert_Usr(Usr *head,Usr *newUsr);

//头插法插入Daily节点
extern int insert_Daily(Daily *head,Daily *newDaily);

//服务器端处理客户端的命令
extern int check_Client_Cmd(Proc *proc,Msg *msg);

//服务器端接收客户端发送的心跳包
extern void check_client_heart(Proc *proc);


#endif
