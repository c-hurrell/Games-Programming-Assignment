#include "MouseClickCheck.h"

namespace MouseClickCheck {

	bool* mouse_click;
	bool* change_scene;
	std::map<int, bool>* keymap;

	void MouseClickCheck::SetMouseClick(bool mouse)
	{
		*mouse_click = mouse;
	}
	bool MouseClickCheck::GetMouseClick()
	{
		return *mouse_click;
	}
	bool GetKeyState(int key)
	{
		bool pressed = (*keymap)[key];
		return pressed;
	}
	void MouseClickCheck::changeScene(bool sceneChange)
	{
		*change_scene = sceneChange;
	}
	bool MouseClickCheck::GetChangeScene()
	{
		return *change_scene;
	}
}