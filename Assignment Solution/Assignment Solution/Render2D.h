#ifndef RENDER2D
#define RENDER2D


#include "Transform2D.h"
#include "SDL.h"

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
    Shape shape;
    void RenderShape(SDL_Renderer* renderer);
};
#endif

