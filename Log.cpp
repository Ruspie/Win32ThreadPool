#include "Log.h"

FILE *Log::file = fopen("log.dat", "a+");


void Log::LogPrint(char *message)
{
	time_t now = time(0);
	char *date = ctime(&now);
	date[strlen(date) - 1] = '\0';
	
	printf("[%s] %s", date, message);
	fprintf(file, "[%s] %s", date, message);
}

Log::Log()
{
}


Log::~Log()
{
}
