#include "Object.h"


GameObject::GameObject()
{
	
}
GameObject::~GameObject()
{

}

void GameObject::AddComponent(Component* component)
{
	Debug::Log("Component Added");
	components.push_back(component);
	component->Start();
}
void GameObject::GetComponent(string tag)
{
	for (Component* c : components)
	{
		if (c->tag == tag) {
			Debug::Log("Component found on: " + c->Object->tag);
		}
		else {
			Debug::Warning("Component not found!");
		}
	}
}