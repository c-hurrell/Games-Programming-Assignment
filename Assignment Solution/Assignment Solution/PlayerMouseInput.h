#pragma once
#include "Object.h"
#include "Transform2D.h"

class PlayerMouseInput :
    public Component
{
    void Start() override;
    void Update() override;
    void Awake() override;
    int x, y;
    Transform2D* transform2D;

    
};

