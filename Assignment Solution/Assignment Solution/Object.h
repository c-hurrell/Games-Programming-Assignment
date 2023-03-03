#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include <vector>

// Components
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
	// Render layer of the object -> May change later
	int layer = 0;

	// Object - Component Relationsip
	vector<Component*> components;
	// Used to Add and Get Components 
	void AddComponent(Component *component);
	// Get finds the component using a tag assigned to it
	Component* GetComponent(string tag);
	// Creates a pointer to the Transform2D component assigned on Start()
	Transform2D* transform2D = nullptr;
	Render2D* r2D = nullptr;

	// Will enable a GameObject
	void EnableObject();
	// Will disable a GameObject
	void DisableObject();

	//void DestroySelf();
	
};

#endif

