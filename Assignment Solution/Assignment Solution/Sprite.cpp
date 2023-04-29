#include "Sprite.h"

Sprite::Sprite()
{
	tag = "Sprite";
	dest = new SDL_Rect();

	texture = TextureManager::LoadTexture(sprite_address);
}

void Sprite::Start()
{
	transform2D = gameObject->transform2D;

	dest->x = transform2D->posX;
	dest->y = transform2D->posY;
	dest->w = transform2D->width * transform2D->scale;
	dest->h = transform2D->height * transform2D->scale;
}

void Sprite::Update()
{
	dest->x = transform2D->posX;
	dest->y = transform2D->posY;
	dest->w = transform2D->width * transform2D->scale;
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
}
void Sprite::SetTexture(SDL_Texture* tex)
{
	texture = tex;
}