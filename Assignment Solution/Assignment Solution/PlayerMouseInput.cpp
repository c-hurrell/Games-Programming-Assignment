#include "PlayerMouseInput.h"
PlayerMouseInput::PlayerMouseInput() : Component()
{
	tag = "PlayerMouseInput"; 
}
void PlayerMouseInput::Start()
{
	transform2D = static_cast<Transform2D*>(gameObject->GetComponent("Transform2D"));
}
void PlayerMouseInput::Update()
{
	SDL_GetMouseState(&x, &y);
	transform2D->posX = x;
	transform2D->posY = y;
}

void PlayerMouseInput::OnEnable()
{
}
void PlayerMouseInput::OnDisable()
{
}
