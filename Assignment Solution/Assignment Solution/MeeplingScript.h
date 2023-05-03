#pragma once
#include "Transform2D.h"
#include "TextureManager.h"
#include "DeltaTime.h"


class MeeplingScript :
    public Component
{
public:
    int frameCount = 0;
    int maxVelocity = 4;

    int animateCheck = 0;
    int respawnTimer = 0;

    Vector2 goal;
    SDL_Texture* meepleLeft;
    SDL_Texture* meepleRight;
    SDL_Texture* meepleWalkingLeft;
    SDL_Texture* meepleWalkingRight;
    
    bool walking = true;
    bool isFacingLeft = false;
    bool dead = false;
    bool diedThisFrame = false;

    MeeplingScript();

    void Start() override;
    void Update() override;
    void OnEnable() override;
    void OnDisable() override;

    void Die();
    void EnableSelf(bool enable);
};

