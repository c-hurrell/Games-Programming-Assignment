#ifndef TEXT_H
#define TEXT_H
#include "Component.h"
#include "Transform2D.h"
#include "TextureManager.h"
class Text :
    public Component
{
    Transform2D* transform2D = nullptr;
    SDL_Rect* dest = new SDL_Rect();
   
public:
    Text();
    ~Text() = default;

    string message = "TESTY TEST TEST";
    int r = 255;
    int g = 255;
    int b = 255;
    int fontType = 0;

    void Start() override;
    void Update() override;
    void OnEnable() override;
    void OnDisable() override;


    void ConvertIntToText(int value);
    void RenderText();

};
#endif

