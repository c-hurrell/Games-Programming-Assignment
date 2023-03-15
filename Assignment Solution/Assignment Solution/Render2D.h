#ifndef RENDER2D
#define RENDER2D

#include "SDL.h"
#include "Object.h"
#include "Transform2D.h"
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
    void OnEnable() override;
    void OnDisable() override;

    enum Shape {
        Rectangle,
        Circle,
        Triangle
    };
    Shape shape;
    void RenderShape(SDL_Renderer* renderer);
};
#endif

