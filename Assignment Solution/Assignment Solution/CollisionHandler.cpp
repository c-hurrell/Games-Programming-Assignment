#include "CollisionHandler.h"

void CollisionHandler::CheckForCollisions(vector<GameObject*> gameObjects)
{
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->rb->collisions.clear();
	}
	for (int i = 0; i < gameObjects.size() - 1; i++)
	{
		Rigidbody* rb1 = gameObjects[i]->rb;
		if (rb1 != nullptr && rb1->IsActive ) {
			//Debug::Log(gameObjects[i]->tag);
			int left_x_1 = rb1->collider.x;
			int top_y_1 = rb1->collider.y;

			
			for (int j = i + 1; j < gameObjects.size(); j++)
			{
				//Debug::Log(gameObjects[j]->tag);
				Rigidbody* rb2 = gameObjects[j]->rb;
				if (rb2 != nullptr && rb2->IsActive)
				{
					int left_x_2 = rb2->collider.x;
					int top_y_2 = rb2->collider.y;
					if (left_x_1 < left_x_2 + rb2->collider.w && left_x_1 + rb1->collider.w > left_x_2 &&
						top_y_1 < top_y_2 + rb2->collider.h && top_y_1 + rb1->collider.h > top_y_2)
					{
						Debug::Log("collision" + gameObjects[i]->tag + " " + gameObjects[j]->tag);
						gameObjects[i]->rb->collisions.push_back(gameObjects[j]);
						gameObjects[j]->rb->collisions.push_back(gameObjects[i]);

					}
				}
			}
		}
	}
}
