#ifndef TRANSFORM
#define TRANSFORM

#include "GameObject.h"

class GameObject;

class Transform2D :
    public Component
{
public:
    Transform2D(float positionX = 0, float positionY = 0);
    ~Transform2D() override;

    float width = 100;
    float height = 100;
    //Vector2 dimensions;

    float scale = 1;

    float posX = 0;
    float posY = 0;
    //Vector2 pos;

    double rotation = 0;

    // Movement functions
    #pragma region Movement_Functions
    void Move(double x, double y);
    void SetPos(double newPosX, double newPosY);

    #pragma endregion

    // Rotational Functions
    #pragma region Rotation_Functions
    // Will rotate an object to face another given object
    void RotateSelfToFaceObject(GameObject* object);
    // Rotates Object by given angle
    void RotateSelf(double angle);
    // Sets Object to a given angle
    void SetRotation(double angle);
    #pragma endregion

    #pragma region Game_Loop_Overrides
    void Start() override;
    void Update() override;
    void OnEnable() override;
    void OnDisable() override;
    #pragma endregion
};
#endif

