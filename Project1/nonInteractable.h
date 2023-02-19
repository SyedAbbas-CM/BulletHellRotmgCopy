#pragma once
#include "passableObject.h"
class nonInteractable :
    public passableObject
{
private:
    void initTextureAndSprite();
public:
    bool isInteractable();
    nonInteractable(int posx, int posy);
    ~nonInteractable();
    
};

