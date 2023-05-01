#ifndef SPRITE_H
#define SPRITE_H
#include "SDL.h"
#include "SDL_image.h"
#include "Component.h"
#include "Transform2D.h"
#include "TextureManager.h"

class Transform2D;

class Sprite :
    public Component
{
    Transform2D* transform2D = nullptr;
    
    
public:
    SDL_Texture* texture;
    SDL_Rect* dest;
    string sprite_address = "assets/TexNull.png";

    Sprite();
    ~Sprite() = default;

    void SetSprite(string sprite_loc = "assets/TexNull.png");
    void SetTexture(SDL_Texture* texture);

    void RenderSprite();

    void Start() override;
    void Update() override;

    void OnEnable() override;
    void OnDisable() override;

};

#endif

