#include <fstream>
#include <Windows.h>
#include <ctime>
//#inlcude <>

class LogController
{
private:
	static FILE *file;
public:
	static void LogPrint(char* message);

	LogController();
	~LogController();
};

