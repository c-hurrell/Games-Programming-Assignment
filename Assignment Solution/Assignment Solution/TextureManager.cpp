#include "TextureManager.h"
namespace TextureManager {

	SDL_Window* window;
	SDL_Renderer* renderer;
	Vector2 windowSize;

	TTF_Font* fonts[FONT_MAX];
	SDL_Rect glyphs[FONT_MAX][NUM_GLYPHS];
	SDL_Texture* font_textures[FONT_MAX];

	Vector2 origin;

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

	Vector2 ScaleToWindow(Vector2 pos, Vector2 size)
	{
		return pos * windowSize - origin * size;
		
	}

	void TextureManager::SetupFont(int fontType, std::string filename)
	{
		TTF_Init();
		SDL_Surface* surface, * text;
		SDL_Rect dest;
		int i;
		char c[2];
		SDL_Rect* g;

		SDL_Color white;

		white.a = 0xFF; white.r = 0xFF; white.g = 0xFF; white.b = 0xFF;


		memset(&glyphs[fontType], 0, sizeof(SDL_Rect) * NUM_GLYPHS);
		Debug::Log(filename);
		if (TTF_OpenFont(filename.c_str(), 10) == NULL)
		{
			Debug::Error("File Not Found!");
		}
		fonts[fontType] = TTF_OpenFont(filename.c_str(), 10);


		surface = SDL_CreateRGBSurface(0, FONT_TEXTURE_SIZE, FONT_TEXTURE_SIZE, 32, 0, 0, 0, 0xff);


		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGBA(surface->format, 0, 0, 0, 0));

		dest.x = dest.y = 0;

		for (i = ' '; i <= 'z'; i++)
		{
			c[0] = i;
			c[1] = 0;

			text = TTF_RenderUTF8_Blended(fonts[fontType], c, white);
			TTF_SizeText(fonts[fontType], c, &dest.w, &dest.h);

			if (dest.x + dest.w >= FONT_TEXTURE_SIZE)
			{
				dest.x = 0;

				dest.y += dest.h + 1;

				if (dest.y + dest.h >= FONT_TEXTURE_SIZE)
				{
					SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_CRITICAL, "Out of glyph space in %dx%d font atlas texture map.", FONT_TEXTURE_SIZE, FONT_TEXTURE_SIZE);
					exit(1);
				}
			}

			SDL_BlitSurface(text, NULL, surface, &dest);

			g = &glyphs[fontType][i];

			g->x = dest.x;
			g->y = dest.y;
			g->w = dest.w;
			g->h = dest.h;

			SDL_FreeSurface(text);

			dest.x += dest.w;
		}

		SDL_Texture* texture;

		texture = SDL_CreateTextureFromSurface(renderer, surface);

		SDL_FreeSurface(surface);

		font_textures[fontType] = texture;
		Debug::Log("Font at: " + filename + " setup as a glyph map");
		TTF_Quit();
	}
	void SetWindow(SDL_Window* temp)
	{
		window = temp;
	}

	Vector2 TextureManager::GetWindowSize()
	{
		int w, h;
		SDL_GetWindowSize(window, &w, &h);
		Vector2 size;
		size.x = w;
		size.y = h;
		return size;

	}
}