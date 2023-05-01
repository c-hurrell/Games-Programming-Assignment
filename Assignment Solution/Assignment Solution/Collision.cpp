#include "Collision.h"

Collision::Collision(GameObject* _g1, GameObject* _g2)
{
	g1 = _g1;
	g2 = _g2;
	Debug::Log("Collision");
}

Collision::~Collision()
{
	
};
