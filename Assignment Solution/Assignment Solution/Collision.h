#pragma once

#include "GameObject.h"
#include "Vector2.h"
class Collision
{
public:
	Collision(GameObject* _g1 , GameObject* _g2);
	~Collision();
	GameObject* g1;
	GameObject* g2;

	// Maths for collisions here if needed
};

