#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "log.h"


//日志记录级别
LOG_LEVEL_E log_level_switch = LOG_LEVEL_INFO;
char *logfile,*log_func;
int log_line;

//数组内容需与LOG_LEVEL_E保持一致

static char *module_names[MODULE_NAME_END] = {"","module_upload","module_press"};

static char *moudle_level[LOG_LEVEL_END] = {"","error","warning","info"};

/*******************************************************************************
Function Name: logGetTime
Description:
Inputs:
Outputs:
Return:
Notes:
*******************************************************************************/

static void logGettime(int *year,int *month,int *day,int *hour,int *min,int *sec){
	struct tm *t;
	time_t tt;
	time(&tt);
	t = localtime(&tt);
	*year = t->tm_year + 1900;
	*mon = t->tm_mon + 1;
	*day = t->tm_mday;
	*hour = t->tm_hour;
	*min = t->tm_min;
	*sec = t->tm_sec;
	return;
}

/*******************************************************************************
Function Name: log_Debug
Description:
Inputs:
Outputs:
Return:
Notes:
*******************************************************************************/

static void logDebug(MOUDLE_NAME_E moudle_name,LOG_LEVEL_E moudle_level,char *fmt,...){
	FILE *fp = NULL;
	char log_name[128] = "";
	int year,mon,day,hour,min,sec;

	/*低于预设置的日志记录级别时，信息不记入日志中数值越大，级别越低 */

	if(log_level>log_level_switch){
		return;
	}
	logGettime(&year,&mon,&day,&hour,&min,&sec);
	if((moudle_name <= MOUDLE_NAME_BEGIN) || moudle_name >= MOUDLE_NAME_END){
		printf("moudle_name error,moudle_name = %d.\n",moudle_name);
		return;
	}
	sprintf(log_name,"./bin/%s_%04d%02d%02d.log",moudle_names[moudle_name],year,mon,day);
	if(fp = fopen(log_name,"a") == NULL){
		printf("open %sfile error.\n",log_name);
		return;
	}
	fprintf(fp, "[%s][%4d-%02d-%02d %02d:%02d:%02d][%s:%s:%d]\n%s:",module_names[module_name], year, mon, day, hour, min, sec, log_file, log_func, log_line, log_level_name[log_level]);

	va_list ap;
	va_start(ap,fmt);
	vfprintf(fp,fmt,ap);

	va_end(ap);
	fclose(fp);



