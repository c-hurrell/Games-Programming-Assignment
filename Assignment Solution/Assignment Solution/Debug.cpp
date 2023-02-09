#include "Debug.h"



void Debug::Log(string message)
{
	setColour(1);
	cout << " >> Debug: " << message << endl;
	setColour();
}
// Change to Check? 10 = Green
void Debug::Error(string message)
{
	setColour(4);
	cout << " !! Error: " << message << endl;
	setColour();
}
void Debug::Log(string message, double value)
{
	setColour(9);
	cout << " >> Value: " << message << value << endl;
	setColour();
}

void Debug::setColour(int colour)
{
	HANDLE hConsole;
	int k;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, colour);
}