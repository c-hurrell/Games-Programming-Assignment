#pragma once
#include "Component.h"
#include "GameObject.h"
class PowerUpScript :
    public Component
{
public:
    PowerUpScript();
    
    bool powerUpSpawned = false;
    bool powerUpActive = false;
    int powerUpType = 1;

    void Start() override;
    void Update() override;
    void OnEnable() override;
    void OnDisable() override;
    void SpawnPowerUp();
    void EnableSelf(bool enable);
};

