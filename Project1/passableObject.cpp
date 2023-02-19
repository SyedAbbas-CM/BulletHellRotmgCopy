#include "passableObject.h"

void passableObject::initTextureAndSprite()
{

}

bool passableObject::passableCollision(sf::FloatRect entity)
{
	if (this->sprite.getGlobalBounds().intersects(entity)) {
		return true;
	}
	else {
		return false;
	}
}

passableObject::passableObject(int SpriteID, int posX, int posY)
{
	this->spriteID = SpriteID;
	initTextureAndSprite();
	this->sprite.setPosition(posX, posY);
}

passableObject::passableObject()
{
}

passableObject::~passableObject()
{
}
