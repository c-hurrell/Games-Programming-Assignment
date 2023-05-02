#pragma once
#include "Scene.h"

// GameObjects in Scene
#include "Wall.h"
// GAME MANAGER? Handles spawning and counting of meeplings, score tracking, Timer etc.
// MEEPLING
// POWER - SMITE
// POWER - SHOCKWAVE
// POWER - CLUSTER
// HOUSE OBJECT? -> not needed for gameplay
// TIMER
// SCORE

class GameScene :
    public Scene
{
public:
    GameScene();

    int numberOfMeeplings = 100;
};

