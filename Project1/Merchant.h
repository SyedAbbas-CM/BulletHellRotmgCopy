#pragma once
#include "passableObject.h"
class Merchant :
    public passableObject
{
private:
    void initTextureAndSprite();
public:
    Merchant(int pos_x, int pos_y);
    ~Merchant();
    bool interaction(sf::FloatRect entity);
    bool isInteractable();
};

