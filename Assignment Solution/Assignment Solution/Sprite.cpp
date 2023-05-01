#include "Sprite.h"

Sprite::Sprite()
{
	tag = "Sprite";
	dest = new SDL_Rect();

	texture = TextureManager::LoadTexture(sprite_address);
}

void Sprite::Start()
{
	Vector2 windowSize = TextureManager::GetWindowSize();
	transform2D = gameObject->transform2D;

	dest->x = ((transform2D->posX - (transform2D->width * transform2D->scale) / 2) / 800) // Sets position to be the centre of an object
		* windowSize.x - (TextureManager::origin.x * (transform2D->width * transform2D->scale) / 800);
	dest->y = ((transform2D->posY - (transform2D->height * transform2D->scale) / 2) / 600)
		* windowSize.y - (TextureManager::origin.y * (transform2D->height * transform2D->scale) / 600);
	dest->w = transform2D->width * transform2D->scale;
	dest->h = transform2D->height * transform2D->scale;
}

void Sprite::Update()
{
	Vector2 windowSize = TextureManager::GetWindowSize();
	dest->x = (transform2D->posX / 800 * windowSize.x) - (transform2D->width / 2);
	dest->y = (transform2D->posY / 600 * windowSize.y) - (transform2D->height / 2); // -(TextureManager::origin.y * (transform2D->height * transform2D->scale) / 600);
	dest->w = transform2D->width * transform2D->scale; // Removed as none of my objects will change size during gameplay currently
	dest->h = transform2D->height * transform2D->scale;

}

void Sprite::OnEnable()
{

}

void Sprite::OnDisable()
{

}

void Sprite::SetSprite(string sprite_loc)
{
	sprite_address = sprite_loc;
	texture = TextureManager::LoadTexture(sprite_address);
}
void Sprite::SetTexture(SDL_Texture* tex)
{
	texture = tex;
}

void Sprite::RenderSprite()
{
	SDL_RenderCopy(TextureManager::renderer, texture, NULL, dest);
}
