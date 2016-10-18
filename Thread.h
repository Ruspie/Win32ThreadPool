#include <string>
#include "LogController.h"

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
	void RunTask(LPTHREAD_START_ROUTINE);
	void CreateWorkerThread(LPTHREAD_START_ROUTINE);
	BOOL IsFree();
	void SetState(BOOL newState);
	
	Thread(DWORD threadId);
	~Thread();
};

