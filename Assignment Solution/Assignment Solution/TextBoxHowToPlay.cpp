#include "TextBoxHowToPlay.h"

TextBoxHowToPlay::TextBoxHowToPlay() : GameObject()
{
	text = AddComponent<Text>();
	sprite->IsActive = false;
	r2D->IsActive = false;
	transform2D->posX = 100;
	transform2D->posY = 100;
	text->fontType = 1;
	text->AddLine("HOW TO PLAY : ");
	text->AddLine("PRESS NUMBER TO SELECT POWER");
	text->AddLine("1 - SMITE");
	text->AddLine("2 - SHOCKWAVE");
	text->AddLine("3 - CLUSTER");
	text->AddLine("LEFT CLICK WITH THE MOUSE TO ACTIVATE POWER");
	text->AddLine("AIM FOR MEEPLINGS TO SCORE POINTS");
	text->AddLine("CLICK THE ALIEN TO START");

	/*for (string txt : text->lines)
	{
		Debug::Log(txt);
	}*/
}