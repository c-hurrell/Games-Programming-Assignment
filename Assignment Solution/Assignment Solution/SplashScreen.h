#pragma once
#include "Scene.h"

// Put your GameObjects here
//#include "MyGameObject.h" <- Example
#include "Logo.h"


class SplashScreen :
    public Scene
{
public:
    SplashScreen();
    ~SplashScreen() = default;
};

