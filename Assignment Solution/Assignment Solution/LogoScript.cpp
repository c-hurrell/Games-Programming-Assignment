#include "LogoScript.h"

LogoScript::LogoScript() : Component()
{
	tag = "LogoScript";
	alienNoise = Mix_LoadWAV("assets/BonusLevelSound.wav");
}

void LogoScript::Start()
{
	red_alien_texture = TextureManager::LoadTexture("assets/AliEngineLogoRed.png");
	rb = gameObject->rb;
}

void LogoScript::Update()
{
	if (!rb->collisions.empty())
	{
		for (GameObject* collision : rb->collisions)
		{
			if (collision->tag == "PlayerMouse")
			{
				Mix_PlayChannel(1, alienNoise, 1);
				gameObject->sprite->SetTexture(red_alien_texture);
				if (*MouseClickCheck::mouse_click == true)
				{
					MouseClickCheck::changeScene(true);
				}
			}
		}
	}
	else
	{
		gameObject->sprite->ResetTexture();
	}
}

void LogoScript::OnEnable()
{
}

void LogoScript::OnDisable()
{
}
