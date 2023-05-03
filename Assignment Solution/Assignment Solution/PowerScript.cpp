#include "PowerScript.h"

PowerScript::PowerScript()
{
	snipeTexture = TextureManager::LoadTexture("assets/SnipeTexture.png");
	shockwaveTexture_1 = TextureManager::LoadTexture("assets/Shockwave1.png");
	shockwaveTexture_2 = TextureManager::LoadTexture("assets/Shockwave2.png");
	shockwaveTexture_3 = TextureManager::LoadTexture("assets/Shockwave3.png");
	snipe = Mix_LoadWAV("assets/SnipeSound.wav");
	shockwave = Mix_LoadWAV("assets/ShockwaveSound.wav");
	
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
		//UpdateCompNow();
		powerCooldown = 15;
	}
	if (MouseClickCheck::GetKeyState(SDLK_2))
	{
		current_power = 3; // Shockwave Power
		Debug::Log("Shockwave Power Selected");
		gameObject->transform2D->width = 50;
		gameObject->transform2D->height = 50;
		gameObject->sprite->texture = shockwaveTexture_1;
		//UpdateCompNow();
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
	gameObject->rb->IsActive = enable;
	gameObject->sprite->IsActive = enable;
}
void PowerScript::UpdateCompNow()
{
	gameObject->rb->TransformUpdate();
	gameObject->sprite->Update();
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
			frame_count = 1;
		}
	}
	else
	{
		cooldown -= 1;
	}
	if (powerActive && frame_count <= 0)
	{
		switch (active_power) {
		case 1:
			// Snipe
			if (cooldown <= 10)
			{
				EnableComponents(false);
				powerActive = false;
				SetPos();
			}
			else if (cooldown >= 14)
			{
				gameObject->transform2D->width = 25;
				gameObject->transform2D->height = 25;
				gameObject->sprite->texture = snipeTexture;
				//UpdateCompNow();
				if (*AudioManager::mute == false)
				{
					Mix_PlayChannel(-1, snipe, 0);
				}
			}
			break;
		case 2:
			// Smite

			break;
		case 3:
			// Shockwave
			if (cooldown <= 100)
			{
				EnableComponents(false);
				powerActive = false;
			}
			else if (cooldown <= 105)
			{
				gameObject->transform2D->width = 150;
				gameObject->transform2D->height = 150;
				gameObject->sprite->texture = shockwaveTexture_1;
				//UpdateCompNow();
			}
			else if (cooldown <= 110)
			{
				gameObject->transform2D->width = 140;
				gameObject->transform2D->height = 140;
				gameObject->sprite->texture = shockwaveTexture_3;
				//UpdateCompNow();
			}
			else if (cooldown <= 115)
			{
				gameObject->transform2D->width = 125;
				gameObject->transform2D->height = 125;
				gameObject->sprite->texture = shockwaveTexture_2;
				//UpdateCompNow();
			}
			else if (cooldown <= 119)
			{
				gameObject->transform2D->width = 75;
				gameObject->transform2D->height = 75;
				gameObject->sprite->texture = shockwaveTexture_1;
				//UpdateCompNow();
				if (*AudioManager::mute == false)
				{
					Mix_PlayChannel(-1, shockwave, 0);
				}
			}
			
			
			
			break;
		}
		frame_count = 1;
	}
	else
	{
		frame_count -= 1;
	}
	

}
