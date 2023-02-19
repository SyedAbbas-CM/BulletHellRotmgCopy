#pragma once
#include"nonPassableObject.h"
class Wall :
    public nonPassableObject
{
private:
    void initTextureAndSprite();
public:
    Wall(int spriteID, int posx, int posy);
    ~Wall();
};

