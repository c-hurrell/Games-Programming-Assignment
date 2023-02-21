#ifndef ENGINEMANAGER_H
#define ENGINEMANAGER_H

#include "SDL.h"
#include "SZ_Timer.h"
#include "windows.h"

#include "Debug.h"
#include "ShapeRendering.h"
#include "Component.h"
#include "Object.h"
#include "Transform2D.h"

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

	// GameObject Functions
	void DestroyObjectsWithTag(string tag);
	void DestroyObject(GameObject object);
};
#endif

