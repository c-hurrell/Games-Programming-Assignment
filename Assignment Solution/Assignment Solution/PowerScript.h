#pragma once
#include "Power.h"
#include "Component.h"
#include "Transform2D.h"
#include "MouseClickCheck.h"

class Power;

class PowerScript :
    public Component
{
public:
    int current_power = 1;
    int active_power = 1;
    int cooldown = 0;
    int powerCooldown = 15;
    bool powerActive = false;

    SDL_Texture* snipeTexture;
    /*SDL_Texture* smiteTexture_1;
    SDL_Texture* smiteTexture_2;
    SDL_Texture* smiteTexture_3;*/
    SDL_Texture* shockwaveTexture_1;
    SDL_Texture* shockwaveTexture_2;
    SDL_Texture* shockwaveTexture_3;

    PowerScript();

    void Start() override;
    void Update() override;
    void OnEnable() override;
    void OnDisable() override;

    void SetPower();
    void SetPos();
    void ActivatePower();
    void EnableComponents(bool enable);
    void powerUse();
};

