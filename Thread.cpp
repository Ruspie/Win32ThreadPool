#include "Thread.h"

Thread::Thread(DWORD threadId)
{
	inThread.isFree = TRUE;
	inThread.threadId = threadId;
}

Thread::~Thread()
{
}

unsigned int __stdcall Thread::ThreadProc(in *inThreadExt)
{
	DWORD dwWaitReasult;

	do {
		GetExitCodeThread((*inThreadExt).hThread, &dwWaitReasult);
	} while (dwWaitReasult == STILL_ACTIVE);

	char messageBuff[100];
	snprintf(messageBuff, sizeof(messageBuff), "Thread with id %d has been ended execute method \"%s\"\n", (*inThreadExt).threadId, (*inThreadExt).methodName);
	Log::LogPrint(messageBuff);

	snprintf(messageBuff, sizeof(messageBuff), "Thread with id %d was \"free\"\n", (*inThreadExt).threadId);
	Log::LogPrint(messageBuff);

	TerminateThread((*inThreadExt).hThread, 0);
	(*inThreadExt).isFree = TRUE;
	return 0;
}

void Thread::RunTask(LPTHREAD_START_ROUTINE method, char *methodName)
{
	char messageBuff[100];
	snprintf(messageBuff, sizeof(messageBuff), "Thread with id %d was \"Locked\"\n", inThread.threadId);
	Log::LogPrint(messageBuff);
	
	inThread.methodName = methodName;
	CreateWorkerThread(method);
	HANDLE tempThread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ThreadProc, &inThread, NULL, NULL);
}

void Thread::CreateWorkerThread(LPTHREAD_START_ROUTINE Method)
{
	SetFreeState(FALSE);
	char messageBuf[100];
	snprintf(messageBuf, sizeof(messageBuf), "Thread with id %d has been started execute method \"%s\"\n", inThread.threadId, inThread.methodName);
	Log::LogPrint(messageBuf);
	inThread.hThread = CreateThread(NULL, NULL, Method, NULL, NULL, NULL);
}

BOOL Thread::IsFree()
{
	return inThread.isFree;
}

void Thread::SetFreeState(BOOL newState)
{
	inThread.isFree = newState;
}
