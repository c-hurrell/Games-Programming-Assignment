#include "Scene.h"

Scene::Scene(string scene_name)
{
	tag = scene_name;
	Debug::Log("Loading Scene");
	//CreateMouseGameObject();
}
Scene::~Scene()
{
	for (GameObject* c : gameObjects)
	{
		delete c;
	}
	gameObjects.clear();
}

void Scene::Start()
{
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Start();
	}
}
void Scene::Update()
{
	co.CheckForCollisions(gameObjects);
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Update();
	}
	SceneUpdate();
}
void Scene::Render(SDL_Renderer* renderer)
{
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Render(renderer);
	}
}


vector<GameObject*> Scene::FindObjectsWithTag(string tag)
{
	vector<GameObject*> foundObjects;
	for (GameObject* gameObject : gameObjects)
	{
		if (gameObject->tag == tag)
		{
			foundObjects.push_back(gameObject);
		}
	}
	return foundObjects;
}

void Scene::CreateMouseGameObject()
{
    GameObject* gameObject = new GameObject();
	gameObject->tag = "PlayerMouse";

	gameObject->transform2D->width = 10;
	gameObject->transform2D->height = 10;

	gameObject->sprite->IsActive = false;
    // Add Components
    gameObject->AddComponent<PlayerMouseInput>();
	gameObjects.push_back(gameObject);    
}
