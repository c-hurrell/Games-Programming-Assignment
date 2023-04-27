#ifndef VECTOR2
#define VECTOR2
struct Vector2
{
	float x;
	float y;
	Vector2(float x_val = 0, float y_val = 0); 
	~Vector2() = default;
};
#endif
