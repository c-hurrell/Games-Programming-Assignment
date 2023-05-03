#pragma once
#include "GameObject.h"
#include "GameManagerScript.h"


class GameManager :
    public GameObject
{
public:
    GameManager();
    GameManagerScript* gms = nullptr;
};

