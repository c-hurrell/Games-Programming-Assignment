#ifndef ENGINEMANAGER_H
#define ENGINEMANAGER_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SZ_Timer.h"
#include "windows.h"

//#include "MouseClickCheck.h"
#include "AudioManager.h"
#include "TextureManager.h"
#include "Debug.h"
#include "ShapeRendering.h"
#include "Input.h"
#include "MouseClickCheck.h"
// Scenes
#include "Scene.h" // <- Base Class for all scenes
#include "SplashScreen.h" // <- Plays at launch
#include "GameScene.h" // <- Plays after button is pressed on the Splashscreen


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
	int recentlyPressed = 0;
	SDL_Window* window;
	SDL_Renderer* renderer;
	InputHandler* input;

	bool changeScene = false;
	bool windowToggle = false;

	Scene* current_scene = nullptr;
	vector<Scene*> scenes;
	
};
#endif

