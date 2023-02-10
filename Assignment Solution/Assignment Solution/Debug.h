#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<windows.h>
#include<sstream>

using namespace std;

static class Debug
{
public:
	Debug();
	bool active;
	void SetDebugActive(bool active = true);
	void Log(string message = "Test");
	void Log(string message, double value);
	// void Log(Node capturedNode, string message = "Node Captured") // Will test when a node has been registered as captured
	void Error(string message = "Error");
	void Warning(string message = "Warning");

private:
	void SetColour(int colour = 15);
	string GetTime();
	
};

