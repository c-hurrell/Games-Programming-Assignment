#ifndef GMS_H
#define GMS_H

#include "DeltaTime.h"
#include "Transform2D.h"
#include "AudioManager.h"


class GameManagerScript :
    public Component
{
public:
    GameManagerScript();

    int score = 0;
    int multiplier = 1;
    float timer = 45;
    float powerUpTime = 0;

    Mix_Chunk* bonusLevelSound = nullptr;
    //Mix_Music* endGameMusic = nullptr; removed

    bool bonus = false;

    int numDiedThisFrame = 0;

    void Start() override;
    void Update() override;
    void OnEnable() override;
    void OnDisable() override;
};
#endif

