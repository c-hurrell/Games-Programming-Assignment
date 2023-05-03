#include "Rigidbody.h"

Rigidbody::Rigidbody()
{
	tag = "Rigidbody";
	
	Rigidbody::collider;
	
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::Start()
{
	transform2D = gameObject->transform2D;
	collider.x = transform2D->posX;
	collider.y = transform2D->posY;
	collider.w = transform2D->width * transform2D->scale;
	collider.h = transform2D->height * transform2D->scale;
}

void Rigidbody::Update()
{
	TransformUpdate();

	if (collisions.empty() == false)
	{
		collisionCheck = true;
	}
}
void Rigidbody::TransformUpdate()
{
	Vector2 windowSize = TextureManager::GetWindowSize();
	collider.w = transform2D->width * transform2D->scale;
	collider.h = transform2D->height * transform2D->scale;
	collider.x = (transform2D->posX) - (collider.w / 2); // -(TextureManager::origin.x * (dest->w / 800 * windowSize.x) / 800);
	collider.y = (transform2D->posY) - (collider.h / 2);
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
