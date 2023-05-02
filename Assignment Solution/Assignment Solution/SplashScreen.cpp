#include "SplashScreen.h"

SplashScreen::SplashScreen() : Scene("SplashScreen")
{
	int posValx = 0;
	int posValy = 0;
	Debug::Log("Generating Walls");
	for (int i = 0; i < 2; i++)
	{
		
		GameObject* wH = AddGameObject<WallHorizontal>();
		wH->transform2D->posX = 400;
		wH->transform2D->posY = posValy;
		wH->transform2D->width = 1920;
		wH->transform2D->height = 75;
		GameObject* wV = AddGameObject<WallVertical>();
		wV->transform2D->posX = posValx;
		wV->transform2D->posY = 300;
		wV->transform2D->width = 75;
		wV->transform2D->height = 1024;

		posValx = 800;
		posValy = 600;
	}
	Debug::Log("Loading splash screen text and logos...");
	AddGameObject<Logo>();
	AddGameObject<LogoText>()->rb->IsActive = false;
	AddGameObject<TextBoxHowToPlay>()->rb->IsActive = false;
}