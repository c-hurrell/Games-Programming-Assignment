#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "Vector2.h"
#include "GameObject.h"
#include <vector>


class CollisionHandler
{
public:
	void CheckForCollisions(vector<GameObject*> gameObjects); //Checks each gameObject with a rigidbody to see if it collided with another one
	//void PresentCollisions();
};
#endif

