#include "Entity.h"



Entity::Entity(int posx, int posy)
{
	this->sprite.setPosition(posx,posy);
}

Entity::Entity()
{

}

const sf::Vector2f& Entity::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Entity::getbounds() const
{
	return this->sprite.getGlobalBounds();
}

void Entity::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Entity::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}
