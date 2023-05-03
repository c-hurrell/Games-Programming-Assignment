#ifndef GMS_H
#define GMS_H

#include "DeltaTime.h"
#include "Transform2D.h"


class GameManagerScript :
    public Component
{
public:
    GameManagerScript();

    int score = 0;
    int multiplier = 1;
    float timer = 45;

    bool bonus = false;

    int numDiedThisFrame = 0;

    void Start() override;
    void Update() override;
    void OnEnable() override;
    void OnDisable() override;
};
#endif

