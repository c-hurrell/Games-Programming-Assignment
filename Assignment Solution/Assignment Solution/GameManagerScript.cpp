#include "GameManagerScript.h"

GameManagerScript::GameManagerScript()
{
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
}

void GameManagerScript::OnEnable()
{
}

void GameManagerScript::OnDisable()
{
}
