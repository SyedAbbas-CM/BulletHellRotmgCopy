#include "Doodads.h"

void Doodads::initTextureAndSprite()
{
	this->spriteID = rand.generateRandom(5, 0);
	if (this->spriteID == 0) {
		if (!this->texture.loadFromFile("Textures/Enviroment/Tree1.png")) {
			std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
		}
	}
	else if (this->spriteID == 1) {
		if (!this->texture.loadFromFile("Textures/Enviroment/Tree2.png")) {
			std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
		}
	}
	else if (this->spriteID == 2) {
		if (!this->texture.loadFromFile("Textures/Enviroment/Tree3.png")) {
			std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
		}
	}
	
	else if (this->spriteID == 3) {
		if (!this->texture.loadFromFile("Textures/Enviroment/Tree4.png")) {
			std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
		}
	}
	
	else if (this->spriteID == 4) {
		if (!this->texture.loadFromFile("Textures/Enviroment/Tree5.png")) {
			std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
		}
	}
	else if (this->spriteID == 4) {
		if (!this->texture.loadFromFile("Textures/Enviroment/Tree6.png")) {
			std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
		}
	}
	
	this->sprite.setTexture(this->texture);
	this->sprite.scale(7.0f, 7.0f);
}

Doodads::Doodads(int posx, int posy)
{
	this->initTextureAndSprite();
	this->sprite.setPosition(posx, posy);
}

Doodads::~Doodads()
{
}
