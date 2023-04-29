#ifndef TEXTUREMANAGER
#define TEXTUREMANAGER

#include "SDL.h"
#include "SDL_image.h"
#include "Debug.h"
#include <vector>
#include <iostream>

namespace TextureManager
{
	extern SDL_Renderer* renderer;

	void SetRenderer(SDL_Renderer* ren);
	SDL_Renderer* GetRenderer();

	SDL_Texture* LoadTexture(std::string image);
};

#endif

