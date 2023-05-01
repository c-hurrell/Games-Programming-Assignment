#pragma once
#include "Component.h"
#include "TextureManager.h"
#include "Transform2D.h"
#include "Rigidbody.h"
#include "MouseClickCheck.h"

class LogoScript :
    public Component
{
public:
    LogoScript();
    SDL_Texture* red_alien_texture;
    Rigidbody* rb;
    void Start() override;
    void Update() override;
    void OnEnable() override;
    void OnDisable() override;
};

