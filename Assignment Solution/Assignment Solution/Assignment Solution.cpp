// Assignment Solution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

// SDL2 Library
#include "SDL.h"

// Debug Library for debugging game
#include "Debug.h" 

#include "EngineManager.h"

using namespace std;

// Constants

#define DELAY 5000

int main(int argc, char *argv[])
{
    EngineManager Engine;

    Debug::SetDebugActive();

    Engine.Init();
    //SDL_Window* window;

    //if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    //    Debug::Error("Something went wrong...");
    //}

    //window = SDL_CreateWindow("AliEngine", 250, 250, 800, 600, SDL_WINDOW_SHOWN);
    //SDL_Event event;
    //while (true) { // SDL loop
    //    while (SDL_PollEvent(&event) != 0) {
    //        if (event.type == SDL_QUIT) {
    //            // Ctrl + C in console !
    //        }
    //    } // end of handling event.
    //}



    //Engine.Init();

    //if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
       // return 1;

    //SDL_Window* window = SDL_CreateWindow("Test Window!", 250, 250, 800, 600, SDL_WINDOW_SHOWN);

    // SDL_RenderClear

    Debug::Log("Information");
    Debug::Log("Value", 10);

    Debug::Warning();
    Debug::Error();

    Debug::SetDebugActive(false);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
