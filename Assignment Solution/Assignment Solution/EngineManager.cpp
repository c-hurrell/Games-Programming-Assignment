#include "EngineManager.h"

using namespace std;
int input_call = 1;
bool debugToggle = false;
bool clearScenes = false;

EngineManager::EngineManager(const char* name, int posX, int posY, int width, int height)
{
    EngineManager::window;
    EngineManager::renderer;

    EngineManager::current_scene;
    //Debug::SetDebugActive();
    
    
    MouseClickCheck::change_scene = &changeScene;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        Debug::Error("Something went wrong...");
    }

    window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
    Debug::Log("AliEngine window launched");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Debug::Log("Renderer active");

    //SDL_RenderSetLogicalSize(renderer, width, height);

    // Make sure all SDL Renderer stuff is set up

    TextureManager::SetRenderer(renderer);
    // Additional Setup
    TextureManager::SetupFont(0, "assets\\fonts\\arial.ttf");
    TextureManager::SetupFont(1, "assets\\fonts\\ATTFSHINGOPROREGULAR.TTF");
    TextureManager::SetWindow(window);
    Vector2 origin(width / 2, height / 2);
    TextureManager::origin = origin;
    

    input = new InputHandler();
    
    // SETUP DONE INITIALISE FIRST SCENE HERE

    SplashScreen* splash = new SplashScreen();
    current_scene = dynamic_cast<Scene*>(splash);
}

void EngineManager::Init()
{

}
void EngineManager::Input()
{

    
    //Input::CheckKeyInput();




    // Checks if Debug has been toggled Q
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
        if (!scenes.empty() && !clearScenes) {
            for (Scene* s : scenes)
            {
                delete s;
            }
            scenes.clear();
            Debug::Warning("Scenes Cleared!");
            Scene* test = new Scene("Test");
        }
        else if (!clearScenes) {
            Debug::Error("No Scene(s) have been initialised!");
        }
        clearScenes = true;
    }
    else {
        clearScenes = false;
    }
}
void EngineManager::Update()
{
    
    input->GetMousePos();
    current_scene->Update();
    if (changeScene == true)
    {
        delete(current_scene);
        GameScene* gameScene = new GameScene();
        current_scene = dynamic_cast<Scene*>(gameScene);
        changeScene = false;
    }
}
void EngineManager::Render()
{
    //merge of render and update, as example.
    SDL_SetRenderDrawColor(renderer, 0, 0, 20, SDL_ALPHA_OPAQUE);
    //clear the screen
    SDL_RenderClear(renderer);
    
    
    current_scene->Render(renderer);
    SDL_RenderCopy(TextureManager::renderer, input->currentMouse, NULL, input->dest);

    SDL_RenderPresent(renderer);
}
void EngineManager::Exit()
{
    //SDL_Delay(DELAY);

    SDL_DestroyWindow(window);

    SDL_Quit();
}
