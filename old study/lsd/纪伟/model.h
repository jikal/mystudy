//实现功能的函数头文件
#ifndef _MODEL_H_
#define _MODEL_H_
//数据通信协议，客户端发送，服务器接收
typedef struct Cmessage
{
int DATA_TYPE;//消息类型
int size;//数据的长度
char name[100];//实际传输的数据
char pass[100];
char IP[48];
char cmd[100];
char CMD_RET[1024];//返回的命令
}Cli;

#define TYPE_LOGIN 0
#define TYPE_REG 1
#define TYPE_MSG 2
#define TYPE_HEART 3
#define TYPE_CMD 4
#define TYPE_OK 5
#define TYPE_ERR 6


extern void proc_echoc(int fd);
extern void* proc_echos(void* p);
extern void reg(int fd);//客户端注册
void log_inc(int fd);//客户端登陆
#endif
