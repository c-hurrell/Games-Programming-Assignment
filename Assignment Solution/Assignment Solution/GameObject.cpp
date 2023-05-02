#include "GameObject.h"


GameObject::GameObject()
{
	tag = "default";
	transform2D = AddComponent<Transform2D>();
	rb = AddComponent<Rigidbody>();
	r2D = AddComponent<Render2D>();
	sprite = AddComponent<Sprite>();
	
}
GameObject::~GameObject()
{
	for (Component* c : components)
	{
		delete c;
	}
	components.clear();
	// Deletes default components from object as well
}
Component* GameObject::GetComponent(string tag)
{
	for (Component* c : components)
	{
		if (c->tag == tag) {
			Debug::Log( tag + " Component found on: " + c->gameObject->tag);
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

}
void GameObject::Update()
{
	for (Component* c : components)
	{
		if ((c->tag != "Render2D" || c->tag != "Sprite" || c-> tag != "Text") && c->IsActive == true) {
			c->Update();
		}
	}
}
void GameObject::OnEnable()
{
	for (Component* c : components)
	{
		if (c->IsActive)
			c->OnEnable();
	}
}
void GameObject::OnDisable()
{
	for (Component* c : components)
	{
		if (c->IsActive)
			c->OnDisable();
	}
}
void GameObject::Render(SDL_Renderer* renderer)
{
	if (IsEnabled)
	{
		if (sprite != nullptr && sprite->IsActive)
		{
			if (r2D != nullptr)
			{
				r2D->IsActive = false;
			}
			sprite->RenderSprite();
		}
		else if (r2D != nullptr && r2D->IsActive)
		{
			r2D->RenderShape(renderer);
		}
		else if (text != nullptr && text->IsActive)
		{
			text->RenderText();
		}
		else
		{
			Debug::Error("No rendering component detected or active");
		}
	}
	
	
}
void GameObject::DisableComponentWithTag(string tag)
{
	for (int i = 0; i < components.size() - 1; i++)
	{
		if (components[i]->tag == tag)
		{
			components[i]->IsActive = false;
		}
	}
}