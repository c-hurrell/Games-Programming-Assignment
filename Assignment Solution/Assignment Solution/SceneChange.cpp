#include "SceneChange.h"

namespace SceneChange {

	bool* scene_change;
	void sceneChange(bool scene)
	{
		scene_change = &scene;
	}
}