#include "nonPassableObject.h"

nonPassableObject::nonPassableObject(int spriteID,int posx, int posy) //
{
	this->spriteID = spriteID;
	this->initTextureAndSprite();
	this->sprite.setPosition(posx, posy);
	
}

nonPassableObject::~nonPassableObject()
{
}

nonPassableObject::nonPassableObject()
{
}

void nonPassableObject::initTextureAndSprite()
{
	
	
}

int nonPassableObject::nonPassableCollision(sf::FloatRect entity)
{
	//bottom collision
	if (entity.top <this->sprite.getGlobalBounds().top
		&& entity.top + entity.height < this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height
		&& entity.left < this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width
		&& entity.left + entity.width >this->sprite.getGlobalBounds().left) {
		return 1;
	}
	//top collision
	else if (entity.top > this->sprite.getGlobalBounds().top
		&& entity.top + entity.height > this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height
		&& entity.left < this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width
		&& entity.left + entity.width >this->sprite.getGlobalBounds().left) {

		return 2;
	}
	//Right collision
	if (entity.left < this->sprite.getGlobalBounds().left
		&& entity.left + entity.width < this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width
		&& entity.top < this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height
		&& entity.top + entity.height >this->sprite.getGlobalBounds().top) {

		return 3;
	}
	//Left collision
	else if (entity.left > this->sprite.getGlobalBounds().left
		&& entity.left + entity.width > this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width
		&& entity.top < this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height
		&& entity.top + entity.height >this->sprite.getGlobalBounds().top) {

		return 4;
	}
}
