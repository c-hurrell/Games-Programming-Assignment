#include "LogoScript.h"

LogoScript::LogoScript() : Component()
{
	tag = "LogoScript";
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
