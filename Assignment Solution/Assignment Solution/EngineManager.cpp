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
    cout << "Init" << endl;
    //SDL_Event event;
    //while (true) { // SDL loop
    //    while (SDL_PollEvent(&event) != 0) {
    //        if (event.type == SDL_QUIT) {
    //            // Ctrl + C in console !
    //        }
    //    } // end of handling event.
    //}
}
void EngineManager::Input()
{
    
    Debug::Error("Input Function not implemented");
    // ITS ALIVE
    // 0x51 = Q
    if (GetKeyState(0x51) < 0) {
        if (Debug::active == false && !debugToggle) {
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
