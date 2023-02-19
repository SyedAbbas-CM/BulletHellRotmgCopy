#pragma once
#include "Entity.h"
#include"EnviromentObject.h"
class nonPassableObject:public EnviromentObject
    
{
protected:
public:
    nonPassableObject(int spriteID,int posx, int posy); //, int height = 40, int width = 40
    ~nonPassableObject();
    nonPassableObject();
    virtual void initTextureAndSprite()=0;

    //Main function for wall
    int nonPassableCollision(sf::FloatRect entity);
};

