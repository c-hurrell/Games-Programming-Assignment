#include "GameManager.h"

GameManager::GameManager() : GameObject()
{
	text = AddComponent<Text>();
	text->fontType = 1;
	text->AddLine(" ");
	text->AddLine("TIME LEFT: ");
	text->AddLine("SCORE: ");
	transform2D->posX = 400;
	transform2D->posY = 100;
	sprite->IsActive = false;
	r2D->IsActive = false;
	rb->IsActive = false;

	gms = AddComponent<GameManagerScript>();
}
