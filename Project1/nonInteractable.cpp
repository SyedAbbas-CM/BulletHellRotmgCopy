#include "nonInteractable.h"

void nonInteractable::initTextureAndSprite()
{
	this->spriteID = rand.generateRandom(3, 0);
	if (this->spriteID == 0) {
		if (!this->texture.loadFromFile("Textures/Enviroment/FlowersWhite.png")) {
			std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
		}
	}
	else if (this->spriteID == 1) {
		if (!this->texture.loadFromFile("Textures/Enviroment/PinkFlowers.png")) {
			std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
		}
	}
	else if (this->spriteID == 2) {
		if (!this->texture.loadFromFile("Textures/Enviroment/Mushroom-big.png")) {
			std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
		}
	}

	else if (this->spriteID == 3) {
		if (!this->texture.loadFromFile("Textures/Enviroment/Mushroom-small.png")) {
			std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
		}
	}
	this->sprite.setTexture(this->texture);
	this->sprite.scale(1.50f, 1.50f);
}

bool nonInteractable::isInteractable()
{
	return false;
}

nonInteractable::nonInteractable(int posx, int posy)
{
	this->initTextureAndSprite();
	this->sprite.setPosition(posx, posy);
}

nonInteractable::~nonInteractable()
{
}
