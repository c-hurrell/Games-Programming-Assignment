#include "Object.h"


GameObject::GameObject(string objectTag)
{
	tag = objectTag;
	r2D = AddComponent<Render2D>();
	transform2D = AddComponent<Transform2D>();
	
}
GameObject::~GameObject()
{
	for (Component* c : components)
	{
		delete c;
	}
	components.clear();
}


Component* GameObject::GetComponent(string tag)
{
	for (Component* c : components)
	{
		if (c->tag == tag) {
			Debug::Log("Component found on: " + c->gameObject->tag);
			return c;
		}
		else {
			Debug::Warning("Component not found!");
		}
	}
	return nullptr;
}
void GameObject::EnableObject()
{
	IsEnabled = true;
	Awake();
}
void GameObject::DisableObject()
{
	IsEnabled = false;
}

void GameObject::Start()
{
	for (Component* c : components)
	{
		c->Start();
	}
}
void GameObject::Update()
{
	for (Component* c : components)
	{
		if (c->tag != "Render2D") {
			c->Update();
		}
	}
}
void GameObject::Awake()
{
	for (Component* c : components)
	{
		c->Awake();
	}
}
void GameObject::Render(SDL_Renderer* renderer)
{
	//Render2D* r2D = nullptr;
	if (components[1]->tag == "Render2D" && r2D == nullptr) {
		//Debug::Log("Found r2D");
		r2D = static_cast<Render2D*>(components[1]);
	}
	else if (r2D == nullptr) {
		for (Component* c : components) {
			if (c->tag == "Render2D") {
				//Debug::Log("Found r2D");
				r2D = static_cast<Render2D*>(c);
			}
		}
	}
	if (r2D == nullptr) {
		Debug::Error("Render2D Component missing for object " + tag);
	}
	else {
		r2D->RenderShape(renderer);
	}
}