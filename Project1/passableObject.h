#pragma once
#include "EnviromentObject.h"
class passableObject :
    public EnviromentObject
{
private:
    void initTextureAndSprite() = 0;
public:
    virtual bool isInteractable()=0;
    bool passableCollision(sf::FloatRect entity);
    passableObject(int SpriteID,int posX,int posY);
    passableObject();
    ~passableObject();
};

