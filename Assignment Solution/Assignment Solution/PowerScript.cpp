#include "PowerScript.h"

PowerScript::PowerScript()
{
	snipeTexture = TextureManager::LoadTexture("assets/SnipeTexture.png");
	shockwaveTexture_1 = TextureManager::LoadTexture("assets/Shockwave1.png");
	shockwaveTexture_2 = TextureManager::LoadTexture("assets/Shockwave2.png");
	shockwaveTexture_3 = TextureManager::LoadTexture("assets/Shockwave3.png");
	
}

void PowerScript::Start()
{
	EnableComponents(false);
	current_power = 1; // Snipe Power
	Debug::Log("Snipe Power sected");
	gameObject->transform2D->width = 25;
	gameObject->transform2D->height = 25;
	gameObject->sprite->texture = snipeTexture;
	powerCooldown = 15;
}

void PowerScript::Update()
{

	SetPower();
	powerUse();
	
	
}

void PowerScript::OnEnable()
{
}

void PowerScript::OnDisable()
{
}

void PowerScript::SetPower()
{
	//Check if key has been pressed
	if (MouseClickCheck::GetKeyState(SDLK_1))
	{
		current_power = 1; // Snipe Power
		Debug::Log("Snipe Power sected");
		gameObject->transform2D->width = 25;
		gameObject->transform2D->height = 25;
		gameObject->sprite->texture = snipeTexture;
		powerCooldown = 15;
	}
	if (MouseClickCheck::GetKeyState(SDLK_2))
	{
		current_power = 2; // Smite Power
		Debug::Log("Smite Power Selected");
		powerCooldown = 60;
	}
	if (MouseClickCheck::GetKeyState(SDLK_3))
	{
		current_power = 3; // Shockwave Power
		Debug::Log("Shockwave Power Selected");
		powerCooldown = 120;
	}
}
void PowerScript::SetPos()
{
	int x;
	int y;
	SDL_GetMouseState(&x, &y);
	Vector2 windowSize = TextureManager::GetWindowSize();
	// Implement full screen fix here
	float fx = float(x) / windowSize.x * 800;
	float fy = float(y) / windowSize.y * 600;

	gameObject->transform2D->posX = fx;
	gameObject->transform2D->posY = fy;
}

void PowerScript::ActivatePower()
{

}
void PowerScript::EnableComponents(bool enable)
{
	gameObject->r2D->IsActive = enable;
	gameObject->rb->IsActive = enable;
	gameObject->sprite->IsActive = enable;
}
void PowerScript::powerUse()
{
	if (cooldown <= 0)
	{
		active_power = current_power;
		if (MouseClickCheck::GetMouseClick())
		{
			Debug::Log("Power Active!");
			SetPos();
			EnableComponents(true);
			cooldown = powerCooldown;
			powerActive = true;
		}
	}
	else
	{
		cooldown -= 1;
	}
	if (powerActive)
	{
		switch(active_power)
			case 1:
				// Snipe
				if (cooldown <= 10)
				{
					EnableComponents(false);
					powerActive = false;
					SetPos();
				}
	}
	

}
