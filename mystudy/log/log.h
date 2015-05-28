/*******************************************************************************
File Name: log.h
Author: study
Version: v1.0
Date: 2015/05/26
Description:
Notes:
*******************************************************************************/
#ifndef _LOG_H_
#define _LOG_H_

#ifdef _cplusplus
	extern c{
#endif

typedef enum{
	MODULE_NAEM_BEGIN = 0,
	MODULE_UPLOAD = 1,
	MODULE_PRESS,
	MODULE_NAME_END = 50
}MODULE_NAME_E;

typedef enum{
	MODULE_LEVEL_BEGIN = 0,
	MOUDLE_LEVEL_ERROR,
	MOUDLE_LEVEL_WARNING,
	MOUDLE_LEVEL_INFO,
	MOUDLE_LEVEL_END
}LOG_LEVEL_E;

extern char *log_file;
extern char *log_func;
extern int log_line;
//外部模块调用LOG_DEBUG来记录日志
extern void logDebug(MODULE_NAME_E module_name,LOG_LEVEL_E log_level,char *fmt,...);
#define LOG_DEBUG logfile = (char *)__FILE__,log_func = (char*)__FUNCTION__,log_line = __LINE__,logDebug

#ifdef _cplusplus
	}
#endif

#endif
