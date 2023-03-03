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
	~EngineManager();

	// Initialise Code
	void Init(bool* val);

	// Gameloop functinosn
	void Input();
	void Update();
	void Render();

	// Exits the game
	void Exit();


	SDL_Window* window;
	SDL_Renderer* renderer;


	bool* done = nullptr;

	vector<GameObject*> gameObjects;
	void AddGameObject(GameObject gameObject);

	// GameObject Functions
	void FindObjectWithTag(string tag);
	void DestroyObjectsWithTag(string tag);
	void DestroyObject(GameObject* object);

	void CreateGameObject(string gmObjTag = "default");
};
#endif

