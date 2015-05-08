#ifndef _CLIENT_MODEL_H_
#define _CLIENT_MODEL_H_

#include "client_control.h"

extern void myfflush(void);

extern void push_continue(void);

//注册
extern void client_reg(int fd);

//登录                                         
extern int client_log(int fd);

//发送命令
extern void send_cmd(int fd);

//聊天
extern void chat_each_other(int fd);
 
#endif
