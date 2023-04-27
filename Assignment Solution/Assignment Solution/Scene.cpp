
#include "Scene.h"

Scene::Scene(string scene_name)
{
	CreateGameObject("Test");
}
Scene::~Scene()
{

}

void Scene::Start()
{
	//initGameObjects()
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


void Scene::CreateGameObject(string gmObjTag)
{
    GameObject* gameObject = new GameObject(gmObjTag);
    // Add Components
    gameObject->AddComponent<PlayerMouseInput>();
	gameObjects.push_back(gameObject);    
}