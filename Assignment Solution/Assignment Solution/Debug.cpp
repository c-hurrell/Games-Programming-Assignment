#define _CRT_SECURE_NO_WARNINGS
#include "Debug.h"


// DEBUG KEY :
// <::> Represents an outputed message 
// <!!> Represents an error or warning
// <==> Represents when a value is being displayed on the screen
// <??> Used for prompts

// COLOUR KEY:
// 6 = Dull Yellow (used for time)
#define DULL_YELLOW 6
// 10 = Green
#define GREEN 10
// 11 = Cyan (Used for outputted numerical values)
#define CYAN 11
// 12 = Red (Used exclusively for Errors)
#define RED 12
// 13 = Magenta
#define MAGENTA 13
// 14 = Yellow (Used for warnings and prompts)
#define YELLOW 14
// 15 = White (Is default for SetColour function)
#define WHITE 15
using namespace std;

namespace Debug {

	bool Debug::active = false;
	// ============== LOG METHODS =================
#pragma region Log_Methods
	void Debug::Log(string message)
	{
		if (active != false)
		{
			// Colour; Text to be outputted in that colour;
			SetColour(DULL_YELLOW); cout << "[" << GetTime() << "]"; // Time is always in yellow
			SetColour(MAGENTA); cout << " <::> " << message << endl; // Set to Magenta
			SetColour();
		}
	}

	void Debug::Log(string message, double value)
	{
		if (active != false)
		{
			SetColour(DULL_YELLOW); cout << "[" << GetTime() << "]";
			SetColour(MAGENTA); cout << " <==> " << message << " : ";
			SetColour(CYAN);  cout << value << endl;
			SetColour();
		}
	}
	//void Debug::Log(node Node, string message)

#pragma endregion

// ===== ERROR, WARNING AND TOGGLE METHODS =====

	void Debug::Error(string message)
	{
		if (active != false)
		{
			SetColour(DULL_YELLOW); cout << "[" << GetTime() << "]";
			SetColour(RED); cout << " <!!> " << message << endl; // Set to a brightish red
			SetColour();
		}
	}

	void Debug::Warning(string message)
	{
		if (active != false)
		{
			SetColour(DULL_YELLOW); cout << "[" << GetTime() << "]";
			SetColour(YELLOW); cout << " <!!> " << message << endl;
			SetColour();
		}
	}
	
	void Debug::SetDebugActive(bool activate)
	{
		active = activate;
		SetColour(DULL_YELLOW); cout << "[" << GetTime() << "]";
		SetColour(YELLOW); cout << " <??> " << "Debug Log: ";

		if (active == true) {
			SetColour(GREEN); cout << "On" << endl; // Set to Green
		}
		else {
			SetColour(RED);  cout << "Off" << endl;
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
}