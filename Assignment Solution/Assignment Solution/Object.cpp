#include "Object.h"


GameObject::GameObject()
{
	
}
GameObject::~GameObject()
{

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
			Debug::Log("Component found on: " + c->Object->tag);
			return c;
		}
		else {
			Debug::Warning("Component not found!");
			return 0;
		}
	}
}