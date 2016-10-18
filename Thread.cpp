#include "Thread.h"


Thread::Thread(DWORD threadId)
{
	inThread.isFree = TRUE;
	inThread.threadId = threadId;
}

Thread::~Thread()
{
}

void Thread::RunTask(LPTHREAD_START_ROUTINE)
{

}

void Thread::CreateWorkerThread(LPTHREAD_START_ROUTINE)
{

}

BOOL Thread::IsFree()
{
	return inThread.isFree;
}

void Thread::SetState(BOOL newState)
{
	inThread.isFree = newState;
}
