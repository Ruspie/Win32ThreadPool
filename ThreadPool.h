#include "Thread.h"

class ThreadPool
{
public:
	Thread *threads[15];
	DWORD threadCount;
	DWORD tasksCount;

	ThreadPool(DWORD threadCount);
	~ThreadPool();

	void InitializePool();
	void AssignTask(LPTHREAD_START_ROUTINE, char*);
	int SearchFreeThread();
	void WaitAllThreads();
	DWORD GetTasksCount();
};

