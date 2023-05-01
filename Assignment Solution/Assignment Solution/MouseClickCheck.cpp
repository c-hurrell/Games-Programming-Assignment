#include "MouseClickCheck.h"

namespace MouseClickCheck {

	bool* mouse_click;
	void MouseClickCheck::SetMouseClick(bool mouse)
	{
		mouse_click = &mouse;
	}
	bool* change_scene;
	void MouseClickCheck::changeScene(bool sceneChange)
	{
		change_scene = &sceneChange;
	}
}