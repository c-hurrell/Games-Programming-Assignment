#include "Object.h"


GameObject::GameObject(string objectTag)
{
	tag = objectTag;
	//Transform2D* transform2D = new Transform2D();
	//transform2D->gameObject = this;
	//Render2D* render2D = new  Render2D();
	//render2D->gameObject = this;
	//AddComponent(transform2D);
	//AddComponent(render2D);
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
	Debug::Log("Component Added " + component->tag);
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
void GameObject::Render()
{

}