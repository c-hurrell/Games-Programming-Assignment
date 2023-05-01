#ifndef MOUSE_CLICK_H
#define MOUSE_CLICK_H

#include <iostream>
#include "Debug.h"
namespace MouseClickCheck {

	extern bool* mouse_click;
	void SetMouseClick(bool mouse);

	extern bool* change_scene;
	void changeScene(bool sceneChange);
}

#endif