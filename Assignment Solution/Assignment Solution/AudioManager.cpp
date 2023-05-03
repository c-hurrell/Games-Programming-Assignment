#include "AudioManager.h"

namespace AudioManager
{
	int* AudioManager::volume;
	int AudioManager::GetVolume()
	{
		return *volume;
	}
	bool* AudioManager::mute;
}