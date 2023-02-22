#include "Object.h"


GameObject::GameObject(string objectTag)
{
	tag = objectTag;
	Transform2D* transform2D = new Transform2D();
	transform2D->gameObject = this;
	Render2D* render2D = new  Render2D();
	render2D->gameObject = this;
	AddComponent(transform2D);
	AddComponent(render2D);
}
GameObject::~GameObject()
{
	for (Component* c : components)
	{
		delete c;
	}
	components.clear();
}

void GameObject::AddComponent(Component* component)
{
	Debug::Log("Component Added " + component->tag + " to GameObject " + tag);
	components.push_back(component);
	component->Start();
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
	Render2D* r2D = nullptr;
	if (components[1]->tag == "Render2D") {
		r2D = static_cast<Render2D*>(components[1]);
	}
	else {
		for (Component* c : components) {
			if (c->tag == "Render2D") {
				r2D = static_cast<Render2D*>(c);
			}
		}
	}
	if (r2D == nullptr) {
		Debug::Error("Render2D Component not found for object " + tag);
	}
	else {
		r2D->RenderShape(renderer);
	}
}