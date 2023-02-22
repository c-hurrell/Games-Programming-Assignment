#ifndef RENDER2D
#define RENDER2D
#include "Component.h"
#include "Transform2D.h"

class Render2D :
    public Component
{
    void Start() override;
    void Update() override;
    void Awake() override;
};
#endif

