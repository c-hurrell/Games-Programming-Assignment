#ifndef RIGIDBODY
#define RIGIDBODY
#include "GameObject.h"
#include "Transform2D.h"
#include "Vector2.h"
#include "SDL.h"
#include "TextureManager.h"

class GameObject;
class Transform2D;

class Rigidbody :
    public Component
{
public:
    Transform2D* transform2D = nullptr;
    // Collider Dimensions
    SDL_Rect collider;
    // Objects it collided with
    vector<GameObject*> collidedWith;
    // Collider Checks
    bool collisionCheck = false;
    // Collision Force application
    Vector2 momentum;

    Vector2 collisionImpluse;

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
    void CheckCollision();
    void OnCollision();
    void OnCollisionEnter();
    void OnCollisionExit();

    // Impulse

    float Velocity();
    // Force requires velocity and 
    float Force();
};

#endif

