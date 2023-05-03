#pragma once
#include "GameObject.h"
#include "PowerUpScript.h"
class PowerUp :
    public GameObject
{
public:
    PowerUp();
    PowerUpScript* PUS = nullptr;
};

