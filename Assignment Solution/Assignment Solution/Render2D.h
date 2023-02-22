#ifndef RENDER2D
#define RENDER2D

#include "SDL.h"
#include "Object.h"
// ShapeRendering
#include "ShapeRendering.h"

class Render2D :
    public Component
{
public:
    Render2D();

    Transform2D* transform2D;

    void Start() override;
    void Update() override;
    void Awake() override;

    enum Shape {
        Rectangle,
        Circle,
        Triangle
    };
    void RenderShape(SDL_Renderer* renderer);
};
#endif

