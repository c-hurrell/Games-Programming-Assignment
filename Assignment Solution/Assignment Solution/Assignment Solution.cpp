// Assignment Solution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

#include "AliEngine.h"


SZ_Timer aTimer;
EngineManager Engine("AliEngine");
const int DELTA_TIME = 50;
bool done = false;

using namespace std;

// Constants

#define DELAY 5000

int main(int argc, char *argv[])
{
    
    Debug::SetDebugActive();

    Engine.Init(&done);

    SDL_Rect r = ShapeRendering::Rectangle(0, 0, 50, 50);

    while (!done)
    {
        aTimer.resetTicksTimer(); // resets a frame timer to zero

        Engine.Input();
        Engine.Update();
        Engine.Render();

        if (aTimer.getTicks() < DELTA_TIME)
        {
            //Debug::Log("Ticks are", aTimer.getTicks());
            SDL_Delay(DELTA_TIME - aTimer.getTicks());
            //Debug::Log("Delay", DELTA_TIME - aTimer.getTicks());
            if ((DELTA_TIME - aTimer.getTicks()) < -50) {
                Debug::Warning("Low frame rate");
            }
            
        }
    }
    Engine.Exit();


    return 0;
}

