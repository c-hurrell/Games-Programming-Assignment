#ifndef ENGINEMANAGER_H
#define ENGINEMANAGER_H

#include "SDL.h"
#include "SZ_Timer.h"
#include "windows.h"

#include "TextureManager.h"
#include "Debug.h"
#include "ShapeRendering.h"
// Scenes
#include "Scene.h"

// Components

class Scene;

#define DELAY 5000
class EngineManager
{
public:
	EngineManager(const char* name = "AliEngine", int posX = 100, int posY = 100, int width = 800, int height = 600);
	void Init();
	void Input();
	void Update();
	void Render();
	void Exit();
	//bool IsRunning();
	//bool Running();
	SDL_Window* window;
	SDL_Renderer* renderer;

	Scene* current_scene = nullptr;
	vector<Scene*> scenes;
	
};
#endif

