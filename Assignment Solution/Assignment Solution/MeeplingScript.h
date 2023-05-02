#pragma once
#include "Component.h"
#include "Transform2D.h"
#include "TextureManager.h"
class MeeplingScript :
    public Component
{
public:
    int frameCount = 0;
    int maxVelocity = 4;

    int animateCheck = 0;

    Vector2 goal;
    SDL_Texture* meepleLeft;
    SDL_Texture* meepleRight;
    SDL_Texture* meepleWalkingLeft;
    SDL_Texture* meepleWalkingRight;
    
    bool walking = true;
    bool isFacingLeft = false;

    MeeplingScript();

    void Start() override;
    void Update() override;
    void OnEnable() override;
    void OnDisable() override;

    void Die();
};

