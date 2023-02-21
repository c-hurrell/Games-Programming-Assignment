#include "EngineManager.h"

using namespace std;
int input_call = 1;
bool debugToggle = false;

EngineManager::EngineManager()
{
    EngineManager::window;
    EngineManager::renderer;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        Debug::Error("Something went wrong...");
    }

    window = SDL_CreateWindow("AliEngine", 100, 100, 800, 600, SDL_WINDOW_RESIZABLE);
    Debug::Log("AliEngine window launched");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Debug::Log("Renderer active");
}

void EngineManager::Init()
{
    GameObject* test = new GameObject();
    Transform2D* testTransform = new Transform2D();
    testTransform->Object = test;
    test->AddComponent(testTransform);
    test->GetComponent("Transform2D");
}
void EngineManager::Input()
{
    
    Debug::Error("Input Function not implemented");
    // ITS ALIVE
    // 0x51 = Q
    // Change to SDL_KEYBOARD method
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
}
void EngineManager::Update()
{
    Debug::Error("Update Function not implemented");
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
