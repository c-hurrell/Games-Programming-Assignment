#include "SplashScreen.h"

SplashScreen::SplashScreen() : Scene("SplashScreen")
{
	AddGameObject<Logo>();
}