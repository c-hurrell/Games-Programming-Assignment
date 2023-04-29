#include "Scene.h"

Scene::Scene(string scene_name)
{
	Debug::Log("Loading Scene");
	CreateTestGameObject("Test");
	for (GameObject* gameObject : gameObjects)
	{
		//gameObject->scene = this;
	}
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


void Scene::CreateTestGameObject(string gmObjTag)
{
    GameObject* gameObject = new GameObject(gmObjTag);
    // Add Components
    gameObject->AddComponent<PlayerMouseInput>();
	gameObjects.push_back(gameObject);    
}