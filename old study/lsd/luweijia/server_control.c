#include "server_control.h"
#include "server_model.h"

void* proc_echo(void  *msg){

	char buf[SIZE];
	int cnt;
	Proc proc = {};
	int fd = ((Msg *)msg)->fd;
	 
	while(1){
	
		cnt = read(fd,&proc,sizeof(proc));
		
		if(cnt == 0){
			printf("client closed!\n");
			break;
		}else if(cnt == -1){
		
			if(errno == EINTR)
				continue;
			else
				break;
		}else{
			switch(proc.type){
			
				case TYPE_REG://注册
					if(check_reg_success(&proc,msg) == 0){
					
						printf("-------------------\n\n");
						strcpy(buf,"注册成功！");
						printf("用户: %s正在注册...\n",proc.name);
						
						strcpy(proc.content,buf);
						write(fd,&proc,sizeof(proc));
						
						printf("注册成功！\n\n");
						
					}else{
						printf("-------------------\n\n");
						strcpy(buf,"注册失败！");
						printf("用户: %s正在注册...\n",proc.name);
						
						strcpy(proc.content,buf);
						write(fd,&proc,sizeof(proc));
						
						printf("注册失败！\n\n");
					}
					
					break;
				case TYPE_LOG://登录
					if(check_Log_Success(&proc,msg) == 0){
					
						printf("-------------------\n\n");
						strcpy(buf,"登录成功！");
						printf("用户: %s正在登录...\n",proc.name);
						
						strcpy(proc.content,buf);
						write(fd,&proc,sizeof(proc));
						
						printf("登录成功！\n\n");
					}else{
					
						printf("-------------------\n\n");
						strcpy(buf,"登录失败！");
						printf("用户: %s正在登录...\n",proc.name);
						
						strcpy(proc.content,buf);
						write(fd,&proc,sizeof(proc));
						
						printf("登录失败！\n\n");
					}
				
					break;
				case TYPE_MSG://
				
					break;
				case TYPE_CMD://处理客户端的命令
					
					if(check_Client_Cmd(&proc,msg) == 0){
						
						printf("-------------------\n\n");
						printf("用户%s正在发送%s命令...\n",proc.name,proc.cmd);
						printf("命令处理成功！\n");
						
					}else{
						printf("-------------------\n\n");
						printf("用户%s正在发送%s命令...\n",proc.name,proc.cmd);
						printf("命令处理失败！\n");
					}
				
					break;
				case TYPE_HEART://接收客户端的心跳包
					 
					check_client_heart(&proc);
					printf("ip: %s heart state...\n",((Msg *)msg)->client_ip);
					printf("%s\n",proc.content);
					  
					break;
				case TYPE_OK://
				
					break;
				case TYPE_ERR://
				
					break;
				default:
					break;
			
			}
		}
	}
	
	close(fd);
	return NULL;
}
