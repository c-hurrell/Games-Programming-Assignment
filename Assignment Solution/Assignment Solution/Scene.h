#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "Debug.h"
#include "SDL.h"
#include "GameObject.h"
#include "CollisionHandler.h"

using namespace std;

class GameObject;

class Scene
{
public:
	Scene(string scene_name = "default");
	~Scene();

	string tag = "default";

	void Start();
	void Update();
	void Render(SDL_Renderer* renderer);

	virtual void SceneUpdate() = 0;

	CollisionHandler co;

	// All the GameObjects


	vector<GameObject*> gameObjects;
	void AddGameObject(GameObject gameObject);

	// GameObject Functions
	vector<GameObject*> FindObjectsWithTag(string tag);
	void DestroyObjectsWithTag(string tag);
	void DestroyObject(GameObject* object);

	void CreateMouseGameObject();

	template <typename T>
	T* AddGameObject();
};

template <typename T> inline T* Scene::AddGameObject()
{
	T* t = new T();
	// Casts the type in a component pointer
	GameObject* gameObject = dynamic_cast<GameObject*>(t);

	// Checks the component has been casted correctly / can be casted
	if (gameObject == nullptr) {
		Debug::Error("Invalid component added!");
		delete(gameObject);
		delete(t);
		return nullptr;
	}
	// Sets the components gameObject to current one its on
	//gameObject->scene = this;
	// Adds the component to objects array
	gameObjects.push_back(gameObject);
	Debug::Log("GameObject Added " + gameObject->tag + " to GameObject " + tag);
	// Runs the component Start function
	gameObject->Start();
	return t;
}
#endif
