#ifndef RIGIDBODY
#define RIGIDBODY
#include "Object.h"
#include "Transform2D.h"
#include "Vector2.h"

class GameObject;
class Transform2D;
class Vector2;

class Rigidbody :
    public Component
{
public:
    Transform2D* transform2D = nullptr;
    // Collider Dimensions
    float width;
    float height;
    
    // Collider Checks
    bool collisionCheck;
    // Collision Force application
    float collisionImpulseX = 0;
    float collisionImpulseY = 0;

    // Speed Values - 2D Vector
    Vector2 velocity;

    // Mass of Object
    float mass = 1;

    bool isFixed = false;
    bool isXFixed = false;
    bool isYFixed = false;

    Rigidbody();
    ~Rigidbody();

    void Start() override;
    void Update() override;
    void OnEnable() override;
    void OnDisable() override;

    // Collision Handler
    void OnCollision();
    void OnCollisionEnter();
    void OnCollisionExit();

    // Impulse

    float Velocity();
    // Force requires velocity and 
    float Force();
};

#endif

