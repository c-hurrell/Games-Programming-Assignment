#include "TextureManager.h"
namespace TextureManager {

	SDL_Renderer* renderer;

	void TextureManager::SetRenderer(SDL_Renderer* ren)
	{
		renderer = ren;
	}
	SDL_Renderer* TextureManager::GetRenderer()
	{
		return renderer;
	}

	SDL_Texture* TextureManager::LoadTexture(std::string image)
	{
		Debug::Log("Texture loading...");
		Debug::Log("Set Texture: " + image);
		SDL_Texture* texture = IMG_LoadTexture(renderer, image.c_str());

		return texture;
	}
}