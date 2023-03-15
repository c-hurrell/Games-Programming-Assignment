#include "Object.h"


GameObject::GameObject(string objectTag)
{
	tag = objectTag;
	transform2D = AddComponent<Transform2D>();
	r2D = AddComponent<Render2D>();
	
}
GameObject::~GameObject()
{
	for (Component* c : components)
	{
		delete c;
	}
	components.clear();
	// Deletes default components from object as well
	delete transform2D;
	delete r2D;
}

void GameObject::AddComponent(Component* component)
{
	Debug::Log("Component Added " + component->tag + " to GameObject " + tag);
	component->gameObject = this;
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
	OnEnable();
}
void GameObject::DisableObject()
{
	IsEnabled = false;
	OnDisable();
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
		if (c->tag != "Render2D" && c->IsActive == true) {
			c->Update();
		}
	}
}
void GameObject::OnEnable()
{
	for (Component* c : components)
	{
		c->OnEnable();
	}
}
void GameObject::OnDisable()
{
	for (Component* c : components)
	{
		c->OnDisable();
	}
}
void GameObject::Render(SDL_Renderer* renderer)
{
	if (r2D == nullptr && IsEnabled) {
		Debug::Error("Render2D Component missing for object " + tag);
	}
	// Added a nullptr check in case
	else if (r2D != nullptr && r2D->IsActive != true) {
		// Impliment function to not render object
	}
	else {
		r2D->RenderShape(renderer);
	}
}