#include "PowerUp.h"

PowerUp::PowerUp() : GameObject()
{
	sprite->SetSprite("assets/ScoreMultiplier.png");
	transform2D->width = 25;
	transform2D->height = 25;
}