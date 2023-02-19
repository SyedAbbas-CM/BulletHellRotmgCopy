#include "Bullet.h"



Bullet::Bullet()
{
}

Bullet::Bullet(sf::Texture * texure, float pos_x, float pos_y, float dirX, float dirY, float movement_speed,float angle, bool playerOwner,int damage,float range,int type)
	:currVelcoity(0.f,0.f)
{
	
	this->playerOwner = playerOwner;
	this->shape.setTexture(*texure);
	this->shape.setPosition(pos_x,pos_y);
	this->shape.setScale(0.75f,0.75f);
	this->shape.setRotation(angle+90);
	this->direction.x = dirX;
	this->direction.y = dirY;
	aimDirNorm = sf::Vector2f(direction.x, direction.y);
	Origin = sf::Vector2f(pos_x,pos_y);
	this->damage = damage;
	this->range = range;
	this->bulletspeed = movement_speed;
	this->type = type;
	this->counter = -360;
	if (playerOwner)piercing = true;
}

Bullet::Bullet(sf::Texture* texure, float pos_x, float pos_y, float dirX, float dirY, float movement_speed, float angle, bool playerOwner, int damage, float range, int type, float scale)
{
	this->playerOwner = playerOwner;
	this->shape.setTexture(*texure);
	this->shape.setPosition(pos_x, pos_y);
	this->shape.setScale(scale, scale);
	this->shape.setRotation(angle + 90);
	this->direction.x = dirX;
	this->direction.y = dirY;
	aimDirNorm = sf::Vector2f(direction.x, direction.y);
	Origin = sf::Vector2f(pos_x, pos_y);
	this->damage = damage;
	this->range = range;
	this->bulletspeed = movement_speed;
	this->type = type;
	this->counter = -360;

}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
	
}

const sf::Vector2f Bullet::getOrigin() const
{
	
	return this->Origin;
}

const sf::Vector2f Bullet::getposition() const
{
	return this->shape.getPosition();
}

const int Bullet::getdamage() const
{
	return this->damage;
}

const float Bullet::getrange() const
{
	return this->range;
}





void Bullet::update()
{
	if (this->type == 1) {
		this->shape.move(random.generateRandom(5, 0), random.generateRandom(5, 0));
	}
	if (this->type == 2) {
		this->shape.scale(1.04f,1.04f);
	}
	currVelcoity = aimDirNorm*bulletspeed;
	this->shape.move(currVelcoity);
}

void Bullet::render(sf::RenderTarget* target)
{
	
	target->draw(this->shape);
}
