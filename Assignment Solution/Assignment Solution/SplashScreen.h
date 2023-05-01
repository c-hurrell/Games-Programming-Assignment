#pragma once
#include "Scene.h"

// Put your GameObjects here
//#include "MyGameObject.h" <- Example
#include "Logo.h"
#include "LogoText.h"
#include "Wall.h"
#include "TextBoxHowToPlay.h"


class SplashScreen :
    public Scene
{
public:
    SplashScreen();
    ~SplashScreen() = default;
};

