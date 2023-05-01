#pragma once
#include "SDL.h"
#include <vector>
#include "Vector2.h"
#include <iostream>
#include "TextureManager.h"
#include "Debug.h"
class InputHandler
{
public:
	Vector2 mousePos;

	Vector2 windowDimensions;
	Vector2 renderBound;
	SDL_Texture* currentMouse;
	SDL_Texture* mouseTexture;
	SDL_Texture* mouseOnClickTexture;
	SDL_Rect* dest;

	int frame_counter = 0;
	bool mouse_clicked = false;

	InputHandler();

	void SetupMouseTextures(std::string mouseSprite = "assets/MouseIcon.png", std::string mouseOnClickSprite = "assets/MouseOnClickIcon.png");

	void GetMousePos();

};

