#include "MouseClickCheck.h"

namespace MouseClickCheck {

	bool* mouse_click;
	bool* change_scene;

	void MouseClickCheck::SetMouseClick(bool mouse)
	{
		*mouse_click = mouse;
	}
	bool MouseClickCheck::GetMouseClick()
	{
		return *mouse_click;
	}
	void MouseClickCheck::changeScene(bool sceneChange)
	{
		if (change_scene != nullptr) {
			std::cout << *change_scene << std::endl;
		}
		*change_scene = sceneChange;
		std::cout << *change_scene << std::endl;
	}
	bool MouseClickCheck::GetChangeScene()
	{
		return *change_scene;
	}
}