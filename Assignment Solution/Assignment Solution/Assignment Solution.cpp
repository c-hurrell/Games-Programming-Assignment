// Assignment Solution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

#include "AliEngine.h"


SZ_Timer aTimer;
string windowName = "AliEngine || FPS : ";
EngineManager Engine(windowName.c_str());
const float DELTA_TIME = 16.67;
bool done = false;

using namespace std;

// Constants

#define DELAY 5000

int main(int argc, char *argv[])
{
    
    Debug::SetDebugActive();

    //Implement Menu here?
    Engine.Init();

    SDL_Rect r = ShapeRendering::Rectangle(0, 0, 50, 50);

    while (!done)
    {
        aTimer.resetTicksTimer(); // resets a frame timer to zero

        Engine.Input();
        Engine.Update();
        Engine.Render();
        
        //r.x++;

        if (aTimer.getTicks() < DELTA_TIME)
        {
            
            
            
            //Debug::Log("Ticks are", aTimer.getTicks());
            float fpsDelay = DELTA_TIME - aTimer.getTicks();
            int fpsCount = (fpsDelay > 0) ? 1000.0f / fpsDelay : 0.0f;
            string fps = to_string(fpsCount);
            string FPSCount = windowName + fps;
            const char* fpsChar = FPSCount.c_str();
            SDL_SetWindowTitle(Engine.window, fpsChar);
            SDL_Delay(fpsDelay);
            //Debug::Log("Delay", DELTA_TIME - aTimer.getTicks());
            if ((DELTA_TIME - aTimer.getTicks()) < -20) {
                Debug::Warning("Frame rate below 60");
            }
            
        }

        SDL_Event event;

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                Debug::Log("Exit Game...");
                done = true;
                // Ctrl + C in Console
            }
        } // end of handling event.

    }
    Engine.Exit();


    return 0;
}

