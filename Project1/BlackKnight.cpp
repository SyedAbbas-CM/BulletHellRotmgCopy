#include "BlackKnight.h"

void BlackKnight::initTexture()
{
	if (!this->texture.loadFromFile("Textures/Enemies/BlackKnight.png"))
		std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
	this->textures["BULLETBOSS1"] = new sf::Texture();
	this->textures["BULLETBOSS1"]->loadFromFile("Textures/Projectiles/TearShot.png");

}

void BlackKnight::initSprite()
{
	this->sprite = sf::Sprite(texture);
	this->sprite.scale(5.0f, 5.0f);
}

void BlackKnight::initVariables()
{
}


void BlackKnight::initVariables(int type)
{
	this->phaseno = 1;
	this->counterWalking = 1;
	this->type = type;
	this->movementspeed = 1.f;
	this->hpMax = 200;
	this->hp = this->hpMax;
	this->damage = 100;
	this->points = 5;
	this->attackCDMax = 40;
	this->attackCD = 00;
	this->rectSourceSprite = sf::IntRect(0, 0, 16, 16);
	this->range = 250;

	this->counter = 0;
	this->secondCounter = sf::seconds(0.01f);

	this->vision = 600;
}





BlackKnight::BlackKnight(int pos_x, int pos_y, int type)
	:Enemy(pos_x, pos_y)
{
	this->initTexture();
	this->initVariables(type);
	this->initSprite();
	this->sprite.setPosition(pos_x, pos_y);
}

BlackKnight::~BlackKnight()
{
}

void BlackKnight::movement(float offset_x, float offset_y, sf::RenderWindow* window)
{
	this->spawnCounter = this->spawnClock.getElapsedTime();
	if (this->hp < 100) {
		this->attackCDMax = 20;
		this->sprite.move(this->aimDirNorm.x * movementspeed, this->aimDirNorm.y * movementspeed);
	}

	else {
		
		this->sprite.move(this->aimDirNorm.x * movementspeed/3, this->aimDirNorm.y * movementspeed/3);
	}
	sprite.setTextureRect(rectSourceSprite);

	if (this->secondCounter.asSeconds() >= 0.2f)
	{
		counterWalking++;
		this->frameClock.restart();
	}
	if (counterWalking > 2) {
		counterWalking = 1;
	}
	if (rectSourceSprite.left >= 50) {
		counterWalking = 1;

	}
	rectSourceSprite.left = counterWalking * 16;
}

void BlackKnight::attack()
{
	
	if (this->aimDirNorm.x < 0) {
		this->aimDirAngle = this->aimDirAngle - 45 + 180;
	}
	if (this->aimDirNorm.x > 0) {
		this->aimDirAngle = this->aimDirAngle - 45;
	}
		Enemy::enemybullets.add(
			Bullet(this->textures["BULLETBOSS1"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
				, this->sprite.getPosition().y /*+ this->sprite.getGlobalBounds().height / 2.f*/,
				this->aimDirNorm.x, this->aimDirNorm.y, 6.f, this->aimDirAngle, false, this->damage, this->range, 2,2

			)
		);
	
}
