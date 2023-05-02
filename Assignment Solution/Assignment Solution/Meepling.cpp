#include "Meepling.h"

Meepling::Meepling() : GameObject()
{
	tag = "Meepling";
	sprite->SetSprite("assets/MeepleRight.png");
	transform2D->width = 50;
	transform2D->height = 50;
	AddComponent<MeeplingScript>();
}