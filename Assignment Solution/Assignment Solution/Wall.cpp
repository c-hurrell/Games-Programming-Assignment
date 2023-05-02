#include "Wall.h"

WallVertical::WallVertical() : GameObject()
{
	sprite->SetSprite("assets/VerticalWall.png");
	tag = "Wall";
}
WallHorizontal::WallHorizontal() : GameObject()
{
	sprite->SetSprite("assets/HorizontalWall.png");
	tag = "Wall";
}