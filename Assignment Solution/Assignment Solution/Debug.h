#ifndef DEBUG_H
#define DEBUG_H
#include<string>
#include<vector>
#include<iostream>
#include<windows.h>
#include<sstream>


namespace Debug
{
	extern bool active;

	void SetDebugActive(bool active = true);
	void Log(std::string message = "Test");
	void Log(std::string message, double value);
	void Error(std::string message = "Error");
	void Warning(std::string message = "Warning");

	void SetColour(int colour = 15);
	std::string GetTime();
	void OutputTime(int colour = 6);
	
};
#endif

