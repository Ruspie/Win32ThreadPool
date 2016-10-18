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
	SetState(FALSE);
	char messageBuff[256];
	snprintf(messageBuff, sizeof(messageBuff), "Thread with Id %d has been started execute method \"%s\"\n", inThread.threadId, inThread.methodName);
	LogController::LogPrint(messageBuff);
}

BOOL Thread::IsFree()
{
	return inThread.isFree;
}

void Thread::SetState(BOOL newState)
{
	inThread.isFree = newState;
}
