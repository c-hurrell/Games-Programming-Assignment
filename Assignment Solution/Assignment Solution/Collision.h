#pragma once
#include "Component.h"
class Collision :
    public Component
{
    void OnCollision();
    void OnCollisionEnter();
    void OnCollisionExit();
};

