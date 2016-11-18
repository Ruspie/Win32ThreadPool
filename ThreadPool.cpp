#include "ThreadPool.h"

ThreadPool::ThreadPool(DWORD threadCount)
{
	(*this).threadCount = threadCount;
}

ThreadPool::~ThreadPool()
{
	Log::LogPrint("All threads are destroyed\n\n");
}

void ThreadPool::InitializePool()
{
	for (DWORD i = 0; i < threadCount; i++) {
		threads[i] = new Thread(i);
	}
	char messageBuff[100];
	snprintf(messageBuff, sizeof(messageBuff), "Initialized %d threads\n", threadCount);
	Log::LogPrint(messageBuff);
}

void ThreadPool::AssignTask(LPTHREAD_START_ROUTINE method, char *methodName)
{
	int freeThreadId;
	if ((freeThreadId = SearchFreeThread()) < 0)
		Log::LogPrint("Assign task is failed, all thread are busy\n");
	else {
		(*threads[freeThreadId]).RunTask(method, methodName);
		tasksCount++;
	}
}

int ThreadPool::SearchFreeThread()
{
	for (DWORD i = 0; i < threadCount; i++) {
		if ((*threads[i]).IsFree()) {
			return i;
		}
	}
	return -1;
}

void ThreadPool::WaitAllThreads()
{
	int freeThreadsCount = 0;
	while (freeThreadsCount != threadCount) {
		freeThreadsCount = 0;
		for (int i = 0; i < threadCount; i++) {
			if ((*threads[i]).IsFree()) {
				freeThreadsCount++;
			}
		}
	}
}

DWORD ThreadPool::GetTasksCount()
{
	return tasksCount;
}
