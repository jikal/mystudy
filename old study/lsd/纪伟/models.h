#ifndef _MODELS_H_
#define _MODELS_H_
typedef struct daily
{
	char IP[100];
	int data_type;
	char logtime[100];
	char quitime[100];
	//suntime
	
}Dai;//记录客户的信息的日志文件链表
extern void* handleclient(void* p);//处理客户信息的主函数
extern char* sys(const char* cmd);//客户端传来的命令处理函数
#endif
