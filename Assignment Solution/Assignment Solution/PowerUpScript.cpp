#include "PowerUpScript.h"

PowerUpScript::PowerUpScript() : Component()
{
	
}

void PowerUpScript::Start()
{
	EnableSelf(false);
}

void PowerUpScript::Update()
{
	for (GameObject* collision : gameObject->rb->collisions)
	{
		if (collision->tag == "Power")
		{
			powerUpActive = true;
			powerUpSpawned = false;
			EnableSelf(false);
		}
	}
}

void PowerUpScript::OnEnable()
{
}

void PowerUpScript::OnDisable()
{
}

void PowerUpScript::SpawnPowerUp()
{
	EnableSelf(true);
	powerUpSpawned = true;
	int randomX = 50 + (rand() % 700);
	int randomY = 50 + (rand() % 500);
	gameObject->transform2D->posX = randomX;
	gameObject->transform2D->posY = randomY;
}
void PowerUpScript::EnableSelf(bool enable)
{
	gameObject->sprite->IsActive = enable;
	gameObject->rb->IsActive = enable;
}
