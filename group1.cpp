#include "logger.h"

#define LOG_CRR_GROUP LOG_GROUP_1

void showLog1(){
	LOG_WRN("Warning");
	LOG_INF("Info");
	LOG_DBG("Debug");
	LOG_ERR("Error");

}