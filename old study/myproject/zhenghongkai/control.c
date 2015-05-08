#include "link.h"
#include "menu.h"
#include "mode.h"
#include "control.h"
//
void clientproc_echo(int fd){
	while(1){
		int ch=0;
		reg_menu();
		scanf("%d",&ch);
		myfflush();
		switch(ch){
			case 1:
				regusr(fd);
				getchar();
				push_continue();			
				break;
			case 2:
				if(logusr(fd)==1){
					usr_control(fd);	
				}	
				break;
			default:
				break;
		}		
	}
}

void *proc_echo(void *cache){
	int cnt;
	Parket buf={0};
	int fd=((Cache *)cache)->fd;
	while(1){
		cnt = read(fd,&buf,sizeof(Parket));
		if(cnt == 0){
			printf("client closed!\n");
			break;
		}else if(cnt == -1){
			if(errno==EINTR){
				continue;
			}else{
				break;
		}
		}else{
			switch(buf.data_type){
				case TYPE_REG:
						check_reg(cache,&buf);	
					break;
				case TYPE_LOGIN:
						check_log(cache,&buf);
					break;
				case TYPE_HEART:
						server_heart(cache);
					break;
				case TYPE_CMD:
					execmd(&buf,cache);
				case TYPE_EXIT:
					check_exit(&buf,cache);
					break;
				default :
					break;	
					
			}
		}
	}
	close(fd);
	return NULL;
}
//客户端二级菜单
void usr_control(int fd){
	while(1){
		int ret=-1;
		make_menu();
		scanf("%d",&ret);
		myfflush();
		switch(ret){
			case 1://命令操作 
				incmd(fd);
				push_continue(); 
				break;
			case 2:
				usr_exit(fd);
				push_continue();
				break;
			default:
				break;
		}	
	}
	
}
//保存信息
void function(int sig){
	if(sig == SIGINT){
		printf("正在保存文件！\n");
		SaveList("./server_usr.txt");
		savedaliyList("./daily_usr.txt");
		sleep(2);
		printf("文件保存完毕！\n");
		Node *cur=head->next;
		clientinfo *cur1=ihead->next;
		sever_menu();
		while(1){
			int ch=0;
			scanf("%d",&ch);
			switch(ch){
				case 1:
					server_browse();
					break;
				case 2:
					while(cur!=head){
						cur->state=0;
						//printf("u:%d\n",cur->state);
						cur=cur->next;
					}
					while(cur1!=ihead){
						cur1->state=0;
						cur1=cur1->next;
					}
					DestrayList(head);
					DestraydailyList(dhead);
					DestrayinfoList(ihead);
					free(head);
					free(ihead);
					free(dhead);
					exit(0);
				
			}	
		}
	}	
}
