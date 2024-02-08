#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;

class Logger {
private:
	Logger() {};
	static Logger* pObj;
public:
	static Logger* GetInstance();
	void PutMessage(string msg);
};
