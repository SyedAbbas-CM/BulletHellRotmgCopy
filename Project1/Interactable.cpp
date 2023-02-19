#include "Interactable.h"

void Interactable::initTextureAndSprite()
{
}

void Interactable::initTextureAndSprite(int dropType)
{
	if (dropType == 0) {
		this->spriteID = rand.generateRandom(100, 0);
		if (this->spriteID > 0 && this->spriteID < 25) {
			if (!this->texture.loadFromFile("Textures/Enviroment/gold7.png")) {
				std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
			this->itemID = 1;
		}
		else if (this->spriteID >= 25 && this->spriteID < 50) {
			if (!this->texture.loadFromFile("Textures/Enviroment/gold6.png")) {
				std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
			this->itemID = 1;
		}
		else if (this->spriteID >= 50 && this->spriteID < 75) {
			if (!this->texture.loadFromFile("Textures/Enviroment/gold5.png")) {
				std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
			this->itemID = 1;
		}
		else if (this->spriteID >= 75 && this->spriteID <= 100) {
			if (!this->texture.loadFromFile("Textures/Enviroment/gold4.png")) {
				std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
			this->itemID = 1;
		}
		this->sprite.setTexture(this->texture);


	}	
	else if (dropType == 1) {
		this->spriteID = rand.generateRandom(100, 0);
		if (this->spriteID > 0 && this->spriteID < 100) {
			if (!this->texture.loadFromFile("Textures/Enviroment/gold7.png")) {
				std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
			this->itemID = 2;
		}
		this->sprite.setTexture(this->texture);
	}
	

	else if (dropType == 2) {
		this->spriteID = rand.generateRandom(100, 0);
		if (this->spriteID > 70 && this->spriteID < 90) {
			if (!this->texture.loadFromFile("Textures/Items/brownbag.png")) {
				std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
			this->itemID = 100;
		}
		else if (this->spriteID >= 90 && this->spriteID <= 100) {
			if (!this->texture.loadFromFile("Textures/Items/brownbag.png")) {
				std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
			this->itemID = 101;
		}
		else {
			this->interacted = true;
		}
		this->sprite.setTexture(this->texture);

		this->sprite.scale(0.7f, 0.7f);
	}

	else if (dropType == 3) {
		this->spriteID = rand.generateRandom(100, 0);
		if (this->spriteID > 0 && this->spriteID < 25) {
			if (!this->texture.loadFromFile("Textures/Enviroment/gold3.png")) {
				std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
			this->itemID = 2;
		}
		else if (this->spriteID >= 25 && this->spriteID < 50) {
			if (!this->texture.loadFromFile("Textures/Enviroment/gold2.png")) {
				std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
			this->itemID = 2;
		}
		else if (this->spriteID >= 50 && this->spriteID < 90) {
			if (!this->texture.loadFromFile("Textures/Enviroment/gold1.png")) {
				std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
			this->itemID = 2;
		}
		else if (this->spriteID >= 90 && this->spriteID < 99) {
			if (!this->texture.loadFromFile("Textures/Items/brownbag.png")) {
				std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
			this->itemID = 101;
		}
		else if (this->spriteID >= 99 && this->spriteID <= 100) {
			if (!this->texture.loadFromFile("Textures/Items/purplebag.png")) {
				std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
			this->itemID = 102;
		}
	}
	else if (dropType == 4) {
		this->spriteID = rand.generateRandom(100, 0);
		if (this->spriteID > 95 && this->spriteID < 98) {
			if (!this->texture.loadFromFile("Textures/Items/purplebag.png")) {
					std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
				this->itemID = 102;
		}

		else if (this->spriteID >= 98 && this->spriteID <= 100) {
			if (!this->texture.loadFromFile("Textures/Items/cyanbag.png")) {
					std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
			}
				this->itemID = 103;
		}
		else {
			this->interacted = true;
		}
	}
		this->sprite.setTexture(this->texture);
		if (this->itemID == 1 || this->itemID ==2) {
			this->sprite.scale(2.f, 2.f);
		}
		else
		this->sprite.scale(1.f, 1.f);
	
	
}

bool Interactable::isInteractable()
{
	return true;
}


Interactable::Interactable(int posx, int posy, int dropType)
{
	this->itemID = 0;
	this->interacted = false;
	this->initTextureAndSprite(dropType);
	this->sprite.setPosition(posx, posy);
	rect.setPosition(posx, posy);
	rect.setSize(sf::Vector2f(2, 2));
	rect.setScale(1, 1);
}

Interactable::~Interactable()
{
}

bool Interactable::interaction(sf::FloatRect entity)
{
	if (!interacted) {
		if (this->sprite.getGlobalBounds().intersects(entity)) {
			interacted = true;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void Interactable::update()
{
}


int Interactable::getitemID()
{
	return this->itemID;
}
