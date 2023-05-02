#pragma once
#include "Scene.h"

// GameObjects in Scene
#include "Wall.h"
// GAME MANAGER? Handles spawning and counting of meeplings, score tracking, Timer etc.
#include "Meepling.h"
#include "Power.h"
// POWER - SMITE
// POWER - SHOCKWAVE
// POWER - CLUSTER
// HOUSE OBJECT? -> not needed for gameplay

class GameScene :
    public Scene
{
public:
    GameScene();

    int numberOfMeeplings = 100;
};

