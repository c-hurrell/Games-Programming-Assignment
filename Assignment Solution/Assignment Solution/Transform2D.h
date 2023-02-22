#ifndef TRANSFORM
#define TRANSFORM

#include "Component.h"


class Transform2D :
    public Component
{
public:
    Transform2D(double positionX = 0, double positionY = 0);
    ~Transform2D() override;

    double width = 100;
    double height = 100;

    double scaleX = 1;
    double scaleY = 1;

    double posX = 0;
    double posY = 0;

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
    void Awake() override;
    #pragma endregion
};
#endif

