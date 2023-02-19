#pragma once
#include "passableObject.h"
class Interactable:public passableObject
{
private:
    bool interacted;
    void initTextureAndSprite();
    void initTextureAndSprite(int dropType);
    sf::RectangleShape rect;
    int itemID;
public:
    bool isInteractable();

    Interactable(int posx, int posy, int dropType);
    ~Interactable();
    bool interaction(sf::FloatRect entity);
    void update();
    int getitemID();
};

