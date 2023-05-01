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

void Text::RenderText()
{
	int i, character, x, y;
	if (transform2D != nullptr)
	{
		x = transform2D->posX;
		y = transform2D->posY;
	}
	else
	{
		Debug::Error(gameObject->tag + " is missing Transform2D component");
		x = 0;
		y = 0;
	}
	const char* text = message.c_str();
	SDL_Rect* glyph, glyph_dest;

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
}
