#ifndef TEXTUREMANAGER
#define TEXTUREMANAGER

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Debug.h"
#include <vector>
#include <iostream>
#include "Vector2.h"

// https://www.1001fonts.com/hydrogenwhiskey-font.html

#define NUM_GLYPHS 100
#define FONT_SIZE 12
#define FONT_TEXTURE_SIZE 512

// Scaling works off of max X = 800, max Y = 600
// So origin would be 400, 300

namespace TextureManager
{
	enum {
		MAIN_FONT,
		HYDRO_FONT,
		//... OTHER FONTS HERE
		FONT_MAX
	};
	extern SDL_Window* window;
	extern SDL_Renderer* renderer;
	extern Vector2 windowSize;
	

	// FOR FONTS
	extern TTF_Font* fonts[FONT_MAX];
	extern SDL_Rect glyphs[FONT_MAX][NUM_GLYPHS];
	extern SDL_Texture* font_textures[FONT_MAX];

	extern Vector2 origin;

	void SetupFont(int font_type, std::string filename);
	void SetWindow(SDL_Window* temp);
	Vector2 GetWindowSize();

	void SetRenderer(SDL_Renderer* ren);
	SDL_Renderer* GetRenderer();

	SDL_Texture* LoadTexture(std::string image);

	Vector2 ScaleToWindow(Vector2 pos, Vector2 size);
	
};

#endif

