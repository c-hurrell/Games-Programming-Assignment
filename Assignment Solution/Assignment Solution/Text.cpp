#include "Text.h"

Text::Text()
{

}

void Text::Start()
{
	transform2D = gameObject->transform2D;
}

void Text::Update()
{
}

void Text::OnEnable()
{
}

void Text::OnDisable()
{
}

void Text::ConvertIntToText(int value)
{
	message = to_string(value);
}
void Text::AddLine(string line)
{
	lines.push_back(line);
}

void Text::RenderText()
{
	Vector2 windowSize = TextureManager::GetWindowSize();
	int i, character, x, y;
	if (transform2D != nullptr)
	{
		x = (transform2D->posX / 800 * windowSize.x) - (transform2D->width/2);
		y = (transform2D->posY / 600 * windowSize.y) - (transform2D->height/2);
	}
	else
	{
		Debug::Error(gameObject->tag + " is missing Transform2D component");
		x = 0;
		y = 0;
	}

	SDL_Rect* glyph = nullptr;
	SDL_Rect glyph_dest;
	for (string line : lines)
	{

		const char* text = line.c_str();
		

		SDL_SetTextureColorMod(TextureManager::font_textures[fontType], r, g, b);
		i = 0;

		character = text[i++];

		while (character)
		{
			glyph = &TextureManager::glyphs[fontType][character];


			glyph_dest.x = x;
			glyph_dest.y = y;
			glyph_dest.w = glyph->w;
			glyph_dest.h = glyph->h;

			SDL_RenderCopy(TextureManager::renderer, TextureManager::font_textures[fontType], glyph, &glyph_dest);

			x += glyph->w;

			character = text[i++];
		}
		// After line is done reset x
		if (transform2D != nullptr)
		{
			x = (transform2D->posX / 800 * windowSize.x) - (transform2D->width / 2);
		}
		else
		{
			Debug::Error("Transform2D missing from " + gameObject->tag);
		}
		y += glyph->h;
	}
	
}
