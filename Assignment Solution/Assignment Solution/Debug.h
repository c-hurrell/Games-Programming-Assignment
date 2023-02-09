#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<windows.h>

using namespace std;

class Debug
{
public:
	void Log(string message = "This code runs");
	void Log(string message, double value);
	// void Log(Node capturedNode, string message = "Node Captured") // Will test when a node has been registered as captured
	void Error(string message = "Error details unknown");

private:
	void setColour(int colour = 15);
	
};

