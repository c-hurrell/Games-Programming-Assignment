#ifndef ENGINEMANAGER_H
#define ENGINEMANAGER_H

#include "SDL.h"
#include "Debug.h"
#include "ShapeRendering.h"
#include "SZ_Timer.h"
#include "windows.h"

#define DELAY 5000
class EngineManager
{
public:
	EngineManager();
	void Init();
	void Input();
	void Update();
	void Render();
	void Exit();
	//bool IsRunning();
	//bool Running();
	SDL_Window* window;
	SDL_Renderer* renderer;
};
#endif

