#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include <vector>

// Components
#include "Component.h"
#include "Transform2D.h"
#include "Render2D.h"
#include "Sprite.h"
#include "PlayerMouseInput.h"

using namespace std;

// Forward implementation
class Component;
class Render2D;
class Sprite;


class GameObject
{
public:
	// Constructors
	GameObject(string objectTag = "default");
	~GameObject();

	// Engine Core Game Loop
	void Start();
	void Update();
	void OnEnable();
	void OnDisable();
	void Render(SDL_Renderer* renderer);

	// Object Information
	string tag = "default";
	bool IsEnabled = true;
	int layer = 0;

	// Object - Component Relationsip
	vector<Component*> components;
	// Template Add Component Method - > Located in header file
	template <typename C>
	C* AddComponent();

	void DisableComponentWithTag(string tag);

	Component* GetComponent(string tag);

	// Default Components - > Should be on every object created.
	Transform2D* transform2D = nullptr;
	Render2D* r2D = nullptr;
	Sprite* sprite = nullptr;

	// Used to enable and disable an object
	void EnableObject();
	void DisableObject();

	//void DestroySelf();
	
};

template <typename C> inline C* GameObject::AddComponent()
{
	C* c = new C();
	// Casts the type in a component pointer
	Component* component = dynamic_cast<Component*>(c);

	// Checks the component has been casted correctly / can be casted
	if (component == nullptr) {
		Debug::Error("Invalid component added!");
		delete(component);
		delete(c);
		return nullptr;
	}
	// Sets the components gameObject to current one its on
	component->gameObject = this;
	// Adds the component to objects array
	components.push_back(component);
	Debug::Log("Component Added " + component->tag + " to GameObject " + tag);
	// Runs the component Start function
	component->Start();
	return c;
}

#endif

