#include "Vector2.h"

Vector2::Vector2(float x_val, float y_val)
{
	x = x_val;
	y = y_val;
}

Vector2 Vector2::operator*(const Vector2& other) const
{
	Vector2 result;
	result.x = x * other.x;
	result.y = y * other.y;
	return result;
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	Vector2 result;
	result.x = x - other.x;
	result.y = y - other.y;
	return result;
}

Vector2 Vector2::operator+(const Vector2& other) const
{
	Vector2 result;
	result.x = x + other.x;
	result.y = y + other.y;
	return result;
}

Vector2 Vector2::operator/(const Vector2& other) const
{
	Vector2 result;
	result.x = x / other.x;
	result.y = y / other.y;
	return result;
}
