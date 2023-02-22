#include "EngineManager.h"

using namespace std;
int input_call = 1;
bool debugToggle = false;
bool clearObjects = false;

EngineManager::EngineManager(const char* name = "AliEngine", int posX = 100, int posY = 100, int width = 800, int height = 600)
{
    EngineManager::window;
    EngineManager::renderer;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        Debug::Error("Something went wrong...");
    }

    window = SDL_CreateWindow(name, posX, posY, width, height, SDL_WINDOW_RESIZABLE);
    Debug::Log("AliEngine window launched");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Debug::Log("Renderer active");
}

void EngineManager::Init()
{
    GameObject* test = new GameObject("Test");
}
void EngineManager::Input()
{
    // Checks if Debug has been toggled
    Debug::Error("Input Function not implemented");
    if (GetKeyState(0x51) < 0) {
        if (!Debug::active && !debugToggle) {
            Debug::SetDebugActive();
           
        }
        else if (!debugToggle) {
            Debug::SetDebugActive(false);
            
        }
        debugToggle = true;
    }
    else {
        debugToggle = false;
    }
    if (GetKeyState(0x10) < 0) {
        if (!gameObjects.empty() && !clearObjects) {
            for (GameObject* g : gameObjects)
            {
                delete g;
            }
            gameObjects.clear();
            GameObject* test = new GameObject("Test");
        }
        else if (!clearObjects) {
            Debug::Error("No GameObject(s) have been initialised!");
        }
        clearObjects = true;
    }
    else {
        clearObjects = false;
    }
}
void EngineManager::Update()
{
    for (GameObject *object : gameObjects)
    {
        object->Update();
    }
}
void EngineManager::Render()
{
    Debug::Error("Render Function not implemented!");
}
void EngineManager::Exit()
{
    //SDL_Delay(DELAY);

    SDL_DestroyWindow(window);

    SDL_Quit();
}
