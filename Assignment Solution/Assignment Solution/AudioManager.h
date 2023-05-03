#pragma once

#include "SDL_mixer.h"

namespace AudioManager
{
	extern int* volume;
	int GetVolume();

	extern bool* mute;

};

