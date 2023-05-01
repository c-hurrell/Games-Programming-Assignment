#include "Logo.h"

Logo::Logo() : GameObject()
{
	tag = "Logo";
	transform2D->posX = 400;
	transform2D->posY = 300;
	sprite->SetSprite("assets/AliEngineLogo.png");
}
