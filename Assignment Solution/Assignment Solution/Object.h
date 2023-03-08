#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include <vector>

#include "Debug.h"
#include "SDL.h"
// Components
//#include "Component.h"
#include "Transform2D.h"
#include "Render2D.h"
#include "PlayerMouseInput.h"

using namespace std;

class Component;

class GameObject
{
public:
	GameObject(string objectTag = "default");
	~GameObject();

	void Start();
	void Update();
	void Awake();
	void Render(SDL_Renderer* renderer);

	// Object Information
	string tag = "default";
	bool IsEnabled = true;
	int layer = 0;

	// Object - Component Relationsip
	vector<Component*> components;
	template <typename C> 
	C* AddComponent();
	//void AddComponent(Component *component);
	Component* GetComponent(string tag);
	Transform2D* transform2D;
	Render2D* r2D;

	void EnableObject();
	void DisableObject();

	//void DestroySelf();
	
};

template <typename C> inline C* GameObject::AddComponent()
{
	C* c = new C(this*);
	Component* component = dynamic_cast<Component*>(c);
	if (component == nullptr) {
		Debug::Error("Invalid component added!");
		delete(component);
		delete(c);
		return nullptr;
	}
	Debug::Log("Component Added " + component->tag + " to GameObject " + tag);
	component->gameObject = this;
	components.push_back(component);
	component->Start();
	return c;
}

#endif

