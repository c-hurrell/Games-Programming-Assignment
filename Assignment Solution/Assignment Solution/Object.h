#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include <vector>

// Components
#include "Component.h"
#include "Transform2D.h"
#include "Render2D.h"
#include "PlayerMouseInput.h"
#include "MoveShapeTest.h"

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
	void AddComponent(Component *component);
	Component* GetComponent(string tag);
	Transform2D* transform2D = nullptr;
	// Render2D* r2D = nullptr;

	void EnableObject();
	void DisableObject();

	//void DestroySelf();
	
};

#endif

