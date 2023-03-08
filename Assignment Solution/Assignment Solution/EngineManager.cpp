#include "EngineManager.h"

using namespace std;
int input_call = 1;
bool debugToggle = false;
bool clearObjects = false;

EngineManager::EngineManager(const char* name, int posX, int posY, int width, int height)
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
// Intialises all the GameObjects
void EngineManager::Init()
{
    CreateGameObject("Test");
}
void EngineManager::Input()
{
    // Checks if Debug has been toggled
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
            Debug::Warning("GameObjects Cleared!");
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
    //merge of render and update, as example.
    SDL_SetRenderDrawColor(renderer, 0, 0, 20, SDL_ALPHA_OPAQUE);
    //clear the screen
    SDL_RenderClear(renderer);
    for (GameObject *object : gameObjects)
    {
        object->Render(renderer);
    }
    SDL_RenderPresent(renderer);
}
void EngineManager::Exit()
{
    //SDL_Delay(DELAY);

    SDL_DestroyWindow(window);

    SDL_Quit();
}

void EngineManager::CreateGameObject(string gmObjTag)
{
    GameObject* gameObject = new GameObject(gmObjTag);
    // Add Components
    //gameObject->AddComponent<Render2D>();
    //gameObject->AddComponent<Transform2D>();
    gameObjects.push_back(gameObject);
    
}
