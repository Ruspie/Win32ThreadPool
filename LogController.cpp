#include "LogController.h"

FILE *LogController::file = fopen("log.dat", "a+");


void LogController::LogPrint(char * message)
{
	time_t now = time(0);
	char *dt = ctime(&now);
	tm *gmtm = gmtime(&now);
	dt = asctime(gmtm);
	dt[strlen(dt) - 1] = '\0';
	
	printf("[%s] %s", dt, message);
	fprintf(file, "[%s] %s", dt, message);

}

LogController::LogController()
{
}


LogController::~LogController()
{
}
