#pragma once
#include "SDL.h"
class EngineManager
{
public:
	void Init();
	void Update();
	void Render();
	
	bool IsRunning();

private:
	bool Running();
	SDL_Window* window;
	SDL_Renderer* renderer;
};

