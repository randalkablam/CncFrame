// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ThreadTest.h"
#include "ManagerTest.h"
#include "NetworkTest.h"
#include "MessageTest.h"
#include "MotorTest.h"
#ifdef OS_WINDOWS
#pragma comment(lib, "ws2_32.lib")
#endif

int main()
{
#ifdef OS_WINDOWS
	WSADATA wsaData;

	DWORD wsaOk = WSAStartup(0x202, &wsaData);
	if (wsaOk == 0)
	{
#endif


	ThreadTest threadTester;
	//threadTester.runTest();

	ManagerTest mgrTester;
	mgrTester.runTest();

	//NetworkTest nt;
	//nt.runTest();

	MessageTest msgTest;
	msgTest.runTest();


	MotorTest motorTest;
	motorTest.testLoop();

	ThreadManager::getThreadManager()->waitOnThreads();
#ifdef OS_WINDOWS
	
		WSACleanup();
	}
#endif
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
