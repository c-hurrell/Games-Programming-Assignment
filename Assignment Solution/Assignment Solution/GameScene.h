#pragma once
#include "Scene.h"

// GameObjects in Scene
#include "Wall.h"
// GAME MANAGER? Handles spawning and counting of meeplings, score tracking, Timer etc.
#include "GameManager.h"
#include "Meepling.h"
#include "Power.h"
// POWER - SMITE / REMOVE?
// SNIPE - ADDED
// POWER - SHOCKWAVE  - ADDED
// 
// HOUSE OBJECT? -> not needed for gameplay possible remove

class GameScene :
    public Scene
{
public:
    GameScene();

    int numberOfMeeplings = 100;
};

