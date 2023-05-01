// Assignment Solution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

// Rename this to mouse cursor tracker
#include "Input.h"
#include "AliEngine.h"
#include "Debug.h"
#include"MouseClickCheck.h"


SZ_Timer aTimer;
string windowName = "Charles T Hurrell(25296839) || CPG2015 || AliEngine || FPS : ";
const int DELTA_TIME = 20;
bool done = false;

using namespace std;

// Constants

#define DELAY 5000

int main(int argc, char *argv[])
{
    
    Debug::SetDebugActive();

    MouseClickCheck::SetMouseClick(false);

    EngineManager Engine(windowName.c_str());

    //Implement Menu here?
    Engine.Init();

    SDL_ShowCursor(SDL_DISABLE);

    SDL_Rect r = ShapeRendering::Rectangle(0, 0, 50, 50);

    while (!done)
    {
        aTimer.resetTicksTimer(); // resets a frame timer to zero
        Engine.Input();
        Engine.Update();
        Engine.Render();
        
        //r.x++;

        float ticks = aTimer.getTicks();

        if (ticks < DELTA_TIME)
        {
            float fpsDelay = DELTA_TIME - ticks;
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
            else if (event.type == SDL_WINDOWEVENT_RESIZED)
            {
                // Checks before getting the mouse position the current window size
                
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            { 
                Debug::Log("You clicked me!");
                Engine.input->mouse_clicked = true;
                MouseClickCheck::SetMouseClick(true);
                break;
            }
            else if (event.type == SDL_MOUSEBUTTONUP)
            {
                Debug::Log("You let go!");
                Engine.input->mouse_clicked = false;
                MouseClickCheck::SetMouseClick(false);
                break;
            }
        } // end of handling event.

    }
    Engine.Exit();


    return 0;
}

