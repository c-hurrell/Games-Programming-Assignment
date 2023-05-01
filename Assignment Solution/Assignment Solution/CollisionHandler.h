#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "Vector2.h"
#include "GameObject.h"
#include <vector>


class CollisionHandler
{
	vector<GameObject*> gameObjects;

	void CheckForCollisions(); //Checks each gameObject with a rigidbody to see if it collided with another one

};
#endif

