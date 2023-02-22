#ifndef ENGINEMANAGER_H
#define ENGINEMANAGER_H

#include "SDL.h"
#include "SZ_Timer.h"
#include "windows.h"

#include "Debug.h"
#include "ShapeRendering.h"
// GameObject
#include "Object.h"

// Components


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

	vector<GameObject*> gameObjects;
	void AddGameObject(GameObject gameObject);

	// GameObject Functions
	void FindObjectWithTag(string tag);
	void DestroyObjectsWithTag(string tag);
	void DestroyObject(GameObject* object);

	void CreateGameObject(string gmObjTag = "default");
};
#endif

