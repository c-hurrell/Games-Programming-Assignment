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
	Vector2 windowSize = TextureManager::GetWindowSize();
	// Implement full screen fix here
	float fx = float(x) / windowSize.x * 800;
	float fy = float(y) / windowSize.y * 600;


	transform2D->posX = fx;
	transform2D->posY = fy;
}

void PlayerMouseInput::OnEnable()
{
}
void PlayerMouseInput::OnDisable()
{
}
