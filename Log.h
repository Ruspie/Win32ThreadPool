#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <Windows.h>
#include <ctime>

class Log
{
private:
	static FILE *file;
public:
	static void LogPrint(char *);

	Log();
	~Log();
};

