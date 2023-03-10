#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <vector>
#include <iostream>
#include <string>

#include "SDL.h"
#include "Debug.h"

using namespace std;

class GameObject;

class Component
{
public:

	// Object the component belongs too
	GameObject* gameObject;

	// Constructor and Deconstructor
	Component();
	virtual ~Component() = default;

	// Component Tag for Identification
	string tag;

	// Game Loop Functions
	#pragma region Game_Loop_Functions
	// Will run when the component is initialized
	virtual void Start() = 0;
	// Will run each frame the game runs
	virtual void Update() = 0;
	// Will run each time the object is enabled after being disabled
	virtual void Awake() = 0;
	#pragma endregion
	
};

#endif

