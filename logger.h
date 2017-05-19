#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <pthread.h>
#include <stdarg.h>
enum LOG_GROUP_T
{
	LOG_GROUP_1,
	LOG_GROUP_2
};
enum LOG_LEVEL_T
{
	LOG_LEVEL_DEBUG,
	LOG_LEVEL_INFO,
	LOG_LEVEL_WARNING,
	LOG_LEVEL_ERROR
};

class Logger
{
private:
	static pthread_mutex_t _loggerMutex;
	static const char* LogGroupNames[];
public:
	static void print(LOG_LEVEL_T type, LOG_GROUP_T group, const char* fmt, ...);
};



#define LOG_INF(...) \
	Logger::print(LOG_LEVEL_INFO, LOG_CRR_GROUP, __VA_ARGS__)

#define LOG_WRN(...) \
	Logger::print(LOG_LEVEL_WARNING, LOG_CRR_GROUP, __VA_ARGS__)

#define LOG_ERR(...) \
	Logger::print(LOG_LEVEL_ERROR, LOG_CRR_GROUP, __VA_ARGS__)

#define LOG_DBG(...) \
	Logger::print(LOG_LEVEL_DEBUG, LOG_CRR_GROUP, __VA_ARGS__)

#endif

/**
 * Any file include Logger.h, it have to redefine the current logging group
 * LOG_CRR_GROUP
 */
#ifdef LOG_CRR_GROUP
#undef LOG_CRR_GROUP
#endif