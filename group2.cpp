#include "logger.h"

#define LOG_CRR_GROUP LOG_GROUP_2

void showLog2(){
	LOG_WRN("Warning");
	LOG_INF("Info");
	LOG_DBG("Debug");
	LOG_ERR("Error");

}