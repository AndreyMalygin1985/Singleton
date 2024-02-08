#include <iostream>
#include <Windows.h>
#include "Logger.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;


int main()
{
	SetConsoleOutputCP(1251);

	Logger* pLogger = Logger::GetInstance();
	pLogger->PutMessage("This is first");
	pLogger->PutMessage("This is second");
	pLogger->PutMessage("Вася пришёл и всё сломал");

	return 777;
}