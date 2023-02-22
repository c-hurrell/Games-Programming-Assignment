#include "Render2D.h"

Render2D::Render2D() : Component()
{
	tag = "Render2D";
	shape = Rectangle;
	
}

void Render2D::Start()
{
	transform2D = static_cast<Transform2D*>(gameObject->GetComponent("Transform2D"));
}

void Render2D::Update()
{
}

void Render2D::Awake()
{
}

void Render2D::RenderShape(SDL_Renderer* renderer)
{
	switch (shape)
	{
	case Rectangle:
		SDL_Rect r = ShapeRendering::Rectangle(transform2D->posX, transform2D->posY, transform2D->width, transform2D->height);
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderDrawRect(renderer, &r);
		break;
	case Triangle:
		break;
	case Circle:
		break;
	default:
		Debug::Error("Shape Render not defined!");
	}
}

