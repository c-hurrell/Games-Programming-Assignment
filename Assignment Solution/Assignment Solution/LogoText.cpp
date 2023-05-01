#include "LogoText.h"
LogoText::LogoText() : GameObject()
{
	text = AddComponent<Text>();
	r2D->IsActive = false;
	sprite->IsActive = false;
	text->fontType = 1;
	text->lines.push_back("POWERED BY");
	text->lines.push_back("ALI-ENGINE");
	text->r = 100;
	text->g = 255;
	text->b = 200;
	transform2D->posX = 390;
	transform2D->posY = 400;
}