
#include "Tilemap.h"

Tilemap::Tilemap(std::string textureName, float x, float y, bool isPassable, bool isExit,float width, float height)
{
	this->fBounds = sf::FloatRect(0.f, 0.f, width, height);
	this->iBounds = sf::IntRect(fBounds);
	if (!this->setUpSprite(textureName)) {
		return;
	}
	pos = sf::Vector2f(x, y);
	this->sprite.setPosition(pos);
	isPassable = true;
	isExit = false;
	
}

Tilemap::~Tilemap()
{
}

bool Tilemap::setUpSprite(std::string textureName)
{
	
	if (!texture.loadFromFile(textureName)) {
		return 0;
	}
	
	this->texture.setRepeated(true);
	//texture.setSmooth(true);
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(iBounds);
	this->sprite.scale(1.f,1.f);
	
	//this->sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
}

void Tilemap::movesprite(sf::Vector2f vector)
{
	this->sprite.setPosition(vector);
}

const sf::FloatRect Tilemap::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f Tilemap::getPos() const
{
	return this->sprite.getPosition();
}


