#pragma once
#include "SDL.h"
#include "Debug.h"

#define DELAY 5000
class EngineManager
{
public:
	EngineManager();
	void Init();
	void Update();
	void Render();
	
	bool IsRunning();


private:
	bool Running();
	SDL_Window* window;
	SDL_Renderer* renderer;
};

