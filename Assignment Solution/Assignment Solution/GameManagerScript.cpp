#include "GameManagerScript.h"

GameManagerScript::GameManagerScript()
{
	bonusLevelSound = Mix_LoadWAV("assets/BonusLevelSound.wav");
}

void GameManagerScript::Start()
{
}

void GameManagerScript::Update()
{
	if (timer <= 0)
	{
		if (score >= 250 && !bonus)
		{
			timer = 15;
			bonus = true;
			gameObject->text->lines[0] = "BONUS ROUND!";
			Mix_PlayChannel(-1, bonusLevelSound, 0);
		}
		else
		{
			timer = 0;
			gameObject->text->lines[0] = "!!! GAME OVER !!!";
			gameObject->text->lines[1] = "TIME LEFT: " + to_string(int(timer));
			gameObject->text->lines[2] = "SCORE: " + to_string(score);
		}
	}
	else
	{
		score += numDiedThisFrame * multiplier;
		timer -= DeltaTime::getDeltaTime();
		gameObject->text->lines[1] = "TIME LEFT: " + to_string(int(timer));
		gameObject->text->lines[2] = "SCORE: " + to_string(score);
	}
	numDiedThisFrame = 0;
	if (powerUpTime <= 0)
	{
		multiplier = 1;
	}
	else
	{
		powerUpTime -= DeltaTime::getDeltaTime();
	}
}

void GameManagerScript::OnEnable()
{
}

void GameManagerScript::OnDisable()
{
}
