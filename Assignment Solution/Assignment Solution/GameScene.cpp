#include "GameScene.h"

GameScene::GameScene() : Scene()
{
	int posValx = 0;
	int posValy = 0;
	AddGameObject<Power>();
	Debug::Log("Generating Walls");
	for (int i = 0; i < 2; i++)
	{
		
		GameObject* wH = AddGameObject<WallHorizontal>();
		wH->transform2D->posX = 400;
		wH->transform2D->posY = posValy;
		wH->transform2D->width = 1920;
		wH->transform2D->height = 50;
		GameObject* wV = AddGameObject<WallVertical>();
		wV->transform2D->posX = posValx;
		wV->transform2D->posY = 300;
		wV->transform2D->width = 50;
		wV->transform2D->height = 1080;

		posValx = 800;
		posValy = 600;
	}
	
	for (int i = 0; i < numberOfMeeplings; i++)
	{
		meeplings.push_back(AddGameObject<Meepling>());
	}
	for (GameObject* meepling : meeplings)
	{
		Component* m = meepling->GetComponent("MeeplingScript");
		mees.push_back(static_cast<MeeplingScript*>(m));
	}
	gm = AddGameObject<GameManager>();
	meeplings.clear();
	pu = AddGameObject<PowerUp>();
	pus = pu->PUS;
}

void GameScene::SceneUpdate()
{
	
	for (MeeplingScript* ms : mees)
	{
		if (ms->diedThisFrame)
		{
			gm->gms->numDiedThisFrame += 1;
		}

	}
	if (gm->gms->bonus == true && doubleMeeplings == false)
	{
		for (int i = 0; i < numberOfMeeplings; i++)
		{
			meeplings.push_back(AddGameObject<Meepling>());
		}
		for (GameObject* meepling : meeplings)
		{
			Component* m = meepling->GetComponent("MeeplingScript");
			mees.push_back(static_cast<MeeplingScript*>(m));
		}
		doubleMeeplings = true;
	}
	if (gm->gms->timer <= 40 && pus->powerUpSpawned == false && gm->gms->powerUpTime <= 0)
	{
		pus->SpawnPowerUp();
	}
	else if (pus->powerUpActive == true)
	{
		gm->gms->multiplier += 1;
		gm->gms->powerUpTime = 5;
		pus->powerUpActive = false;
	}
}
