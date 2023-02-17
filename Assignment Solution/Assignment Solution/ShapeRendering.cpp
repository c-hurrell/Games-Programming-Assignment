#include "ShapeRendering.h"
namespace ShapeRendering
{
	SDL_Rect ShapeRendering::Rectangle(int x, int y, int w, int h)
	{
		// Creates the rectangle
		SDL_Rect r;
		// Sets the rectangle Values
		r.x = x;	r.y = y;	r.w = w;	r.h = h;
		return r;
	}
}