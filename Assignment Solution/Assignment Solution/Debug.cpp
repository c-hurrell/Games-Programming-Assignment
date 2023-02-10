#define _CRT_SECURE_NO_WARNINGS
#include "Debug.h"

// DEBUG KEY :
// <::> Represents an outputed message 
// <!!> Represents an error or warning
// <==> Represents when a value is being displayed on the screen
// <??> Used for prompts

// COLOUR KEY:
// 6 = Dull Yellow (used for time)
// 10 = Green
// 11 = Cyan (Used for outputted numerical values)
// 12 = Red (Used exclusively for Errors)
// 13 = Magenta
// 14 = Yellow (Used for warnings and prompts)
// 15 = White (Is default for SetColour function)


// ============== LOG METHODS =================

void Debug::Log(string message)
{
	if (active != false)
	{
		SetColour(6); cout << "[" << GetTime() << "]"; // Time is always in yellow
		SetColour(13); cout << " <::> " << message << endl; // Set to a light cyan
		SetColour();
	}
}

void Debug::Log(string message, double value)
{
	if (active != false)
	{
		SetColour(6); cout << "[" << GetTime() << "]";
		SetColour(13); // Sets colour to magenta
		cout << " <==> " << message << " : ";
		SetColour(11);  cout << value << endl;
		SetColour();
	}
}
//void Debug::Log(node Node, string message)



// ===== ERROR, WARNING AND TOGGLE METHODS =====

void Debug::Error(string message)
{
	if (active != false)
	{
		SetColour(6); cout << "[" << GetTime() << "]";
		SetColour(12); cout << " <!!> " << message << endl; // Set to a brightish red
		SetColour();
	}
}

void Debug::Warning(string message)
{
	if (active != false)
	{
		SetColour(6); cout << "[" << GetTime() << "]";
		SetColour(14); cout << " <!!> " << message << endl;
		SetColour();
	}
}
void Debug::SetDebugActive(bool activate)
{
	active = activate;
	SetColour(6); cout << "[" << GetTime() << "]";
	SetColour(14); cout << " <??> " << "Debug Log: ";

	if (active == true) {
		SetColour(10); cout << "On" << endl; // Set to Green
	}
	else {
		SetColour(12);  cout << "Off" << endl;
	}
	SetColour();
}

// ===== MISC METHODS =====

void Debug::SetColour(int colour)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colour);
}

string Debug::GetTime()
{
	ostringstream outputStream;

	time_t currentTime = time(0);
	struct tm tstruct;
	char LogTime[80];
	tstruct = *localtime(&currentTime);
	strftime(LogTime, sizeof(LogTime), "%Y-%m-%d %X", &tstruct);

	outputStream << LogTime;

	return outputStream.str();
}



Debug::Debug()
{
	active = false;
}