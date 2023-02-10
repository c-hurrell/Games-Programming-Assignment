#pragma once
#include "SDL.h"
#include "Debug.h"
class EngineManager
{
public:
	EngineManager();
	void Init();
	void Update();
	void Render();
	
	bool IsRunning();

	Debug debug;

private:
	bool Running();
	SDL_Window* window;
	SDL_Renderer* renderer;
};

