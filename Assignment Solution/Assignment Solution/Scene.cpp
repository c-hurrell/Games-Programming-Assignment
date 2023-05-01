#include "Scene.h"

Scene::Scene(string scene_name)
{
	tag = scene_name;
	Debug::Log("Loading Scene");
	//CreateTestGameObject();
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
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Update();
	}
}
void Scene::Render(SDL_Renderer* renderer)
{
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Render(renderer);
	}
}


void Scene::CreateTestGameObject()
{
    GameObject* gameObject = new GameObject();
    // Add Components
    gameObject->AddComponent<PlayerMouseInput>();
	gameObjects.push_back(gameObject);    
}
