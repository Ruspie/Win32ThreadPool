#include "ThreadPool.h"

void TestMethod() {
	Sleep(6000);
}

void TestMethod1() {
	Sleep(4000);
}

void TestMethod2() {
	Sleep(2000);
}

int main() {
	ThreadPool *threadPool = new ThreadPool(3);
	(*threadPool).InitializePool();
	(*threadPool).AssignTask((LPTHREAD_START_ROUTINE)TestMethod, "TestMethod");
	(*threadPool).AssignTask((LPTHREAD_START_ROUTINE)TestMethod1, "TestMethod1");
	(*threadPool).AssignTask((LPTHREAD_START_ROUTINE)TestMethod2, "TestMethod2");
	(*threadPool).AssignTask((LPTHREAD_START_ROUTINE)TestMethod1, "TestMethod1");
	
	Sleep(4000);
	
	(*threadPool).AssignTask((LPTHREAD_START_ROUTINE)TestMethod2, "TestMethod2");

	(*threadPool).WaitAllThreads();
	(*threadPool).~ThreadPool();
	system("pause");
}