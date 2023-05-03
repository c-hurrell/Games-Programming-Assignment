#include "MeeplingScript.h"

MeeplingScript::MeeplingScript()
{
	meepleLeft = TextureManager::LoadTexture("assets/MeepleLeft.png");
	meepleRight = TextureManager::LoadTexture("assets/MeepleRight.png");
	meepleWalkingLeft = TextureManager::LoadTexture("assets/MeepleLeftWalking.png");
	meepleWalkingRight = TextureManager::LoadTexture("assets/MeepleRightWalking.png");
}

void MeeplingScript::Start()
{
	
	int randomX = 50 + (rand() % 700);
	int randomY = 50 + (rand() % 500);
	gameObject->transform2D->posX = randomX;
	gameObject->transform2D->posY = randomY;
	gameObject->rb->velocity.x = maxVelocity;
	gameObject->rb->velocity.y = maxVelocity - 2;
	randomX = 50 + (rand() % 700);
	randomY = 50 + (rand() % 500);
	goal.x = randomX;
	goal.y = randomY;
}

void MeeplingScript::Update()
{
	for (GameObject* collision : gameObject->rb->collisions)
	{
		if (collision->tag == "Power" && frameCount >= 1)
		{
			Die(); // Tells meepling to die
			return;
		}
	}
	if ((goal.x + 2 >= gameObject->transform2D->posX && goal.x - 2 <= gameObject->transform2D->posX) 
		&& (goal.y + 2 >= gameObject->transform2D->posY && goal.y - 2 <= gameObject->transform2D->posY))
	{
		int randomX = 50 + (rand() % 700);
		int randomY = 50 + (rand() % 500);
		goal.x = randomX;
		goal.y = randomY;
	}
	else
	{
		if (goal.x >= gameObject->transform2D->posX)
		{
			gameObject->transform2D->posX += gameObject->rb->velocity.x;
			isFacingLeft = false;
		}
		else if (goal.x < gameObject->transform2D->posX)
		{
			gameObject->transform2D->posX += -gameObject->rb->velocity.x;
			isFacingLeft = true;
		}
		
		
		if (goal.y > gameObject->transform2D->posY)
		{
			gameObject->transform2D->posY += gameObject->rb->velocity.y;
		}
		else if (goal.y < gameObject->transform2D->posY)
		{
			gameObject->transform2D->posY += -gameObject->rb->velocity.y;
		}
	}
	if (animateCheck >= 5)
	{
		if (isFacingLeft)
		{
			if (gameObject->sprite->texture != meepleWalkingLeft)
			{
				gameObject->sprite->texture = meepleWalkingLeft;
			}
			else
			{
				gameObject->sprite->texture = meepleLeft;
			}
		}
		else
		{
			if (gameObject->sprite->texture != meepleWalkingRight)
			{
				gameObject->sprite->SetTexture(meepleWalkingRight);
			}
			else
			{
				gameObject->sprite->SetTexture(meepleRight);
			}
		}
		animateCheck = 0;
	}
	else
	{
		animateCheck += 1;
	}
	frameCount += 1;
}

void MeeplingScript::OnEnable()
{
	int randomX = 50 + (rand() % 700);
	int randomY = 50 + (rand() % 500);
	gameObject->transform2D->posX = randomX;
	gameObject->transform2D->posY = randomY;
	frameCount = 0;
}

void MeeplingScript::OnDisable()
{

}

void MeeplingScript::Die()
{
	animateCheck = 0;
	frameCount = 0;
	Debug::Log("Meeple has died");
	
}
void MeeplingScript::EnableSelf(bool enable)
{
	gameObject->rb->IsActive = enable;
	gameObject->rb->IsActive = enable;
}
