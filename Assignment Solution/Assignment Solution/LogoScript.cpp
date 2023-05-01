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
				Debug::Log("Collide");
				gameObject->sprite->SetTexture(red_alien_texture);
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
