#include "Rigidbody.h"

Rigidbody::Rigidbody()
{
	transform2D = static_cast<Transform2D*>(gameObject->GetComponent("Transform2D"));
	Rigidbody::collider;
	collider.x = transform2D->posX;
	collider.y = transform2D->posY;
	collider.w = transform2D->width;
	collider.h = transform2D->height;
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::Start()
{
}

void Rigidbody::Update()
{
}

void Rigidbody::OnEnable()
{
}

void Rigidbody::OnDisable()
{
}

void Rigidbody::CheckCollision()
{
}

void Rigidbody::OnCollision()
{
	// if objects collide
}

void Rigidbody::OnCollisionEnter()
{

}

void Rigidbody::OnCollisionExit()
{
	// Do exit function
}

float Rigidbody::Velocity()
{
	return 0.0f;
}

float Rigidbody::Force()
{
	return 0.0f;
}
