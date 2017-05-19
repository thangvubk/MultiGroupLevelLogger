#include "logger.h"
#include <stdio.h>
#define LOG_MAX_LEN         1024

pthread_mutex_t Logger::_loggerMutex;

const char* Logger::LogGroupNames[] = {"GROUP_1", "GROUP_2"};


static int loggerConfig[][4] ={
	0,  //LOG_LEVEL_DEBUG
	0,  //LOG_LEVEL_INFO
	0,  //LOG_LEVEL_WARNING
	1,  //LOG_LEVEL_ERROR
	//group 2
	0,  //LOG_LEVEL_DEBUG
	0,  //LOG_LEVEL_INFO
	1,  //LOG_LEVEL_WARNING
	1   //LOG_LEVEL_ERROR
};

void Logger::print(LOG_LEVEL_T type, LOG_GROUP_T group, const char* fmt, ...)
{

	if ((type == LOG_LEVEL_INFO && loggerConfig[group][LOG_LEVEL_INFO] == 0) ||
        (type == LOG_LEVEL_WARNING && loggerConfig[group][LOG_LEVEL_WARNING] == 0) ||
        (type == LOG_LEVEL_ERROR && loggerConfig[group][LOG_LEVEL_ERROR] == 0) ||
        (type == LOG_LEVEL_DEBUG && loggerConfig[group][LOG_LEVEL_DEBUG] == 0))
	{
		return;
	}

	char msg[LOG_MAX_LEN];
    va_list args;
    va_start(args, fmt);
    vsnprintf(msg, LOG_MAX_LEN, fmt, args);
    va_end(args);

    msg[LOG_MAX_LEN-1] = '\0';

	const char* strType;
	switch (type)
	{
	case LOG_LEVEL_INFO:
		strType = "INFO";
		break;
	case LOG_LEVEL_WARNING:
		strType = "WARNING";
		break;
	case LOG_LEVEL_ERROR:
		strType = "ERROR";
		break;
	case LOG_LEVEL_DEBUG:
		strType = "DEBUG";
		break;
	default: strType = "PRINT";
	}

	printf("%-14s|%5s: %s\n", LogGroupNames[group], strType, msg);

}
