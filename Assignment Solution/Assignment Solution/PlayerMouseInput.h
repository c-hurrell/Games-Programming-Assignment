#pragma once
#include "GameObject.h"
#include "Transform2D.h"
#include "TextureManager.h"
#include "MouseClickCheck.h"

class GameObject; 
class Transform2D;

class PlayerMouseInput :
    public Component
{   
public:
    PlayerMouseInput();
    ~PlayerMouseInput() = default;
    void Start() override;
    void Update() override;
    void OnEnable() override;
    void OnDisable() override;
    int x, y;
    Transform2D* transform2D;

    
};

