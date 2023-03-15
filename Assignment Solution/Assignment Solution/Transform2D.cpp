#include "Transform2D.h"

Transform2D::Transform2D(double positionX, double positionY) : Component()
{
	tag = "Transform2D";
	posX = positionX;
	posY = positionY;
}
Transform2D::~Transform2D()
{
}
;
#pragma region Game_Loop
void Transform2D::Start()
{
	// Nothing to be initialised on Start
}
void Transform2D::Update()
{
	// Not Used
}
void Transform2D::OnEnable()
{
	// Not Used
}
void Transform2D::OnDisable()
{

}
#pragma endregion

void Transform2D::Move(double x, double y)
{
	posX += x;
	posY += y;
}
void Transform2D::SetPos(double newPosX, double newPosY)
{
	posX = newPosX;
	posY = newPosY;
}

void Transform2D::RotateSelfToFaceObject(GameObject* object)
{

}
void Transform2D::RotateSelf(double angle)
{

}
void Transform2D::SetRotation(double angle)
{
	while (angle > 360) {
		angle -= 360;
	}
	while (angle < 0) {
		angle += 360;
	}
	rotation = angle;
}