#include "Wall.h"

void Wall::initTextureAndSprite()
{
	if (this->spriteID == 0) {
		if (!this->texture.loadFromFile("Textures/walls/Walltop1.png")) {
			std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
		}
	}
	else if (this->spriteID == 1) {
		if (!this->texture.loadFromFile("Textures/walls/Wall1.png")) {
			std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
		}
	}
	this->sprite.setTexture(this->texture);
	this->sprite.scale(2.0f, 2.0f);
}

Wall::Wall(int spriteID, int posx, int posy)
{
	this->spriteID = spriteID;
	this->initTextureAndSprite();
	this->sprite.setPosition(posx, posy);

}

Wall::~Wall()
{
}
