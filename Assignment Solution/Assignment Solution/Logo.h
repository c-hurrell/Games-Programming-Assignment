#pragma once
#include "GameObject.h"
class Logo :
    public GameObject
{
public:
    Logo();
    ~Logo() = default;

    Text* text;
};

