#include "Thread.h"

class ThreadPool
{
public:
	Thread *threads[15];
	DWORD ThreadCount;
	DWORD tasksCount;

	ThreadPool(DWORD threadCount);
	~ThreadPool();

	void InitializePool();
	void AssignTask(LPTHREAD_START_ROUTINE, char*);
	DWORD SearchFreeThread();
	void WaitAllThreads();
};

