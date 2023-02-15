#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<windows.h>
#include<sstream>



namespace Debug
{
	// extern bool active = false;
	void SetDebugActive(bool active = true);
	void Log(std::string message = "Test");
	void Log(std::string message, double value);
	// void Log(Node capturedNode, string message = "Node Captured") // Will test when a node has been registered as captured
	void Error(std::string message = "Error");
	void Warning(std::string message = "Warning");

	void SetColour(int colour = 15);
	std::string GetTime();
	
};

