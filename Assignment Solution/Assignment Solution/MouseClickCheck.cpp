#include "MouseClickCheck.h"

namespace MouseClickCheck {

	bool* mouse_click;
	void MouseClickCheck::SetMouseClick(bool mouse)
	{
		mouse_click = &mouse;
	}
}