#ifndef _MODE_H_
#define _MODE_H_

#include "link.h"
extern void regusr(int fd);
extern int check_reg(Cache *cahce,Parket *ptr);
extern int logusr(int fd);
extern int check_log(Cache *cache,Parket *ptr);
extern void push_continue(void);
extern void incmd(int fd);
extern int execmd(Parket *cmd, Cache *cache);
extern void client_heart(int fd);
extern void server_heart(Cache *cache);
extern void function(int sig);
extern void myfflush(void);
extern void server_browse();
extern void showlogusr(clientinfo *e);
extern void check_exit(Parket *ptr, Cache *cache);
extern void usr_exit(int fd);
#endif
