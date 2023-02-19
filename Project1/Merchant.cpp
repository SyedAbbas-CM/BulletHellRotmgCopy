#include "Merchant.h"

void Merchant::initTextureAndSprite()
{
	if (!this->texture.loadFromFile("Textures/Merchant.png")) {
		std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
	}
	this->sprite.setTexture(this->texture);
}

Merchant::Merchant(int pos_x, int pos_y)
{
	this->initTextureAndSprite();
	this->sprite.setPosition(pos_x,pos_y);
}

Merchant::~Merchant()
{
}

bool Merchant::interaction(sf::FloatRect entity)
{
	
	if (this->sprite.getGlobalBounds().intersects(entity)) {
		return true;
	}
	else {
		return false;
	}

}

bool Merchant::isInteractable()
{
	return true;
}
