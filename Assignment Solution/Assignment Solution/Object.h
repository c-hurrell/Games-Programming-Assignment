#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include <vector>
#include "Component.h"
using namespace std;

class Component;

class GameObject
{
public:
	GameObject();
	~GameObject();

	string tag = "default";
	bool IsEnabled = true;

	vector<Component*> components;
	void AddComponent(Component *component);
	void GetComponent(string tag);

	void DestroySelf();
	
};

#endif

