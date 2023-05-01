#include "Input.h"

InputHandler::InputHandler()
{
	InputHandler::currentMouse = nullptr;
	InputHandler:: mouseTexture = nullptr;
	InputHandler:: mouseOnClickTexture = nullptr;
	dest = new SDL_Rect();
	SetupMouseTextures();
	currentMouse = mouseTexture;
}

void InputHandler::SetupMouseTextures(std::string mouseSprite, std::string mouseOnClickSprite)
{
		
	mouseTexture = TextureManager::LoadTexture(mouseSprite);
	mouseOnClickTexture = TextureManager::LoadTexture(mouseOnClickSprite);
	dest->w = 50;
	dest->h = 50;
}

void InputHandler::GetMousePos()
{
	Vector2 windowSize = TextureManager::GetWindowSize();
	// Resets mouse texture
	int x, y;
	SDL_GetMouseState(&x, &y);

	float fx = x / windowSize.x * 800;
	float fy = y / windowSize.y * 600;

	//Debug::Log("MouseX", fx);

	mousePos.x = fx;
	mousePos.y = fy;

	if (mouse_clicked == true && currentMouse != mouseOnClickTexture)
	{
		currentMouse = mouseOnClickTexture;
		frame_counter = 0;
		//mouse_clicked = false;
	}
	else if (frame_counter <= 10 && mouse_clicked == false)
	{
		Debug::Log("Count");
		frame_counter += 1;
	}
	else if(mouse_clicked == false && frame_counter > 10)
	{
		Debug::Log("Check");
		currentMouse = mouseTexture;
	}


	// Render offset so mouse in centre of object
	/*fx -= dest->w / 2;
	fy -= dest->h / 2;*/

	//Debug::Log("WindowX", windowSize.x);

	dest->x = ((fx / 800) * windowSize.x) - (dest->w / 2); // -(TextureManager::origin.x * (dest->w / 800 * windowSize.x) / 800);
	dest->y = ((fy / 600) * windowSize.y) - (dest->h / 2); // -(TextureManager::origin.y * (dest->h / 600 * windowSize.y) / 600);

	//Debug::Log("DestX", dest->x);
}