#include <string>
#include "Log.h"

class Thread
{
private:
	struct in {
		HANDLE hThread;
		DWORD threadId;
		char *methodName;
		BOOL isFree;
	} inThread;
public:
	static unsigned int __stdcall ThreadProc(in*);
	void RunTask(LPTHREAD_START_ROUTINE, char*);
	void CreateWorkerThread(LPTHREAD_START_ROUTINE);
	BOOL IsFree();
	void SetFreeState(BOOL);
	
	Thread(DWORD);
	~Thread();
};

