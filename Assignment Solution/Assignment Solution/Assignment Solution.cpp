// Assignment Solution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

// Rename this to mouse cursor tracker
#include "Input.h"
#include "AliEngine.h"
#include "Debug.h"
#include"MouseClickCheck.h"

// Game background audio
// https://tones.wolfram.com/generate/GItzUqjRjPvqDRb0tXu3dhbqsofIb40HrWDWYFGY9JX1g9


SZ_Timer aTimer;
string windowName = "Charles T Hurrell(25296839) || CPG2015 || AliEngine || FPS : ";
const int DELTA_TIME = 20;
bool done = false;

using namespace std;

// Constants

#define DELAY 5000

int main(int argc, char *argv[])
{
    bool debugToggle = false;
    bool ticksToggle = false;
    Debug::SetDebugActive();
    Debug::LogTicks();

    bool mouseClick = false;    
    MouseClickCheck::mouse_click = &mouseClick;

    map<int, bool> keymap;
    MouseClickCheck::keymap = &keymap;

    EngineManager Engine(windowName.c_str());

    //Implement Menu here?
    Engine.Init();

    SDL_ShowCursor(SDL_DISABLE);

    SDL_Rect r = ShapeRendering::Rectangle(0, 0, 50, 50);

    while (!done)
    {
        aTimer.resetTicksTimer(); // resets a frame timer to zero
        
        Engine.Input();
        Debug::Ticks("Input ticks", aTimer.getTicks());
        Engine.Update();
        Debug::Ticks("Update ticks", aTimer.getTicks());
        Engine.Render();
        Debug::Ticks("Render ticks", aTimer.getTicks());
        
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
                //Debug::Log("You clicked me!");
                Engine.input->mouse_clicked = true;
                mouseClick = true;
                break;
            }
            else if (event.type == SDL_MOUSEBUTTONUP)
            {
                //Debug::Log("You let go!");
                Engine.input->mouse_clicked = false;
                mouseClick = false;
                break;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                keymap[event.key.keysym.sym] = true;
            }
            else if (event.type == SDL_KEYUP)
            {
                keymap[event.key.keysym.sym] = false;
            }
        } // end of handling event.

        

        if (keymap[SDLK_F1])
        {
            if (!debugToggle)
            {
                if (Debug::active == true)
                    Debug::SetDebugActive(false);
                else
                    Debug::SetDebugActive();

                debugToggle = true;
            }
        }
        else
        {
            debugToggle = false;
        }
        if (keymap[SDLK_F2])
        {
            if (!ticksToggle)
            {
                if (Debug::logTicks == true)
                    Debug::LogTicks(false);
                else
                    Debug::LogTicks();
            }
            ticksToggle = true;
        }
        else
        {
            ticksToggle = false;
        }


    }
    Engine.Exit();


    return 0;
}

