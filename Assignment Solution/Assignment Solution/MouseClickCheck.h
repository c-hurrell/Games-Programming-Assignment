#ifndef MOUSE_CLICK_H
#define MOUSE_CLICK_H

#include <iostream>
#include "Debug.h"
#include<map>
#include<vector>

namespace MouseClickCheck {

	extern std::map<int, bool>* keymap;
	bool GetKeyState(int key);

	extern bool* mouse_click;
	void SetMouseClick(bool mouse);
	bool GetMouseClick();

	extern bool* change_scene;
	void changeScene(bool sceneChange);
	bool GetChangeScene();
}

#endif