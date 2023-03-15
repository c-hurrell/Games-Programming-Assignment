#pragma once
#include "Object.h"
#include "Transform2D.h"

class GameObject; 

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

