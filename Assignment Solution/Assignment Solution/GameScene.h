#pragma once
#include "Scene.h"

// GameObjects in Scene
#include "Wall.h"
// GAME MANAGER? Handles spawning and counting of meeplings, score tracking, Timer etc.
#include "GameManager.h"
#include "Meepling.h"
#include "Power.h"
#include "PowerUp.h"
#include "MeeplingScript.h"
#include "PowerUpScript.h"
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

    void SceneUpdate() override;

    int numberOfMeeplings = 100;
    bool doubleMeeplings = false;
    GameManager* gm = nullptr;
    vector<Meepling*> meeplings;
    vector<MeeplingScript*> mees;
    PowerUp* pu = nullptr;
    PowerUpScript* pus = nullptr;
};

