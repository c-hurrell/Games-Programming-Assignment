#pragma once
#include "GameObject.h"

// Components : 
#include "MeeplingScript.h"

class GameObject;

class Meepling :
    public GameObject
{
public:
    Meepling();
    MeeplingScript* ms;
};

