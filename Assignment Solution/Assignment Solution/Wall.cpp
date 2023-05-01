#include "Wall.h"

WallVertical::WallVertical() : GameObject()
{
	sprite->SetSprite("assets/VerticalWall.png");
	tag = "Wall";
	rb->IsActive = false;
}
WallHorizontal::WallHorizontal() : GameObject()
{
	sprite->SetSprite("assets/HorizontalWall.png");
	tag = "Wall";
	rb->IsActive = false;
}