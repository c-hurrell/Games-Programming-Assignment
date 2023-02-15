#include "EngineManager.h"

EngineManager::EngineManager()
{
    EngineManager::window;
    EngineManager::renderer;
}

void EngineManager::Init()
{
    //Debug::Error("Init Function not implemented!");


    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        Debug::Error("Something went wrong...");
    }

    window = SDL_CreateWindow("AliEngine", 250, 250, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Event event;
    while (true) { // SDL loop
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                // Ctrl + C in console !
            }
        } // end of handling event.
    }


    SDL_Delay(DELAY);

    SDL_DestroyWindow(window);

    SDL_Quit();
}
void EngineManager::Update()
{
    Debug::Error("Update Function not implemented");
}
void EngineManager::Render()
{
    Debug::Error("Render Function not implemented!");
}
