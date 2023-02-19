#pragma once
#include "nonPassableObject.h"
class Doodads :
    public nonPassableObject
{
private:
    void initTextureAndSprite();
public:
    Doodads(int posx, int posy);
    ~Doodads();
};

