#include "Ghost.h"

void Ghost::initTexture()
{
	if (!this->texture.loadFromFile("Textures/Enemies/Ghost.png"))
		std::cout << "ERROR::enemy::INITTEXTURE:: could not load texture file\n";
	this->textures["BULLETENEMY"] = new sf::Texture();
	this->textures["BULLETENEMY"]->loadFromFile("Textures/Projectiles/BULLET.png");
}

void Ghost::initSprite()
{
	this->sprite = sf::Sprite(texture);
	this->sprite.scale(4.f, 4.f);
}

void Ghost::initVariables()
{
	this->counterWalking = 0;
	this->movementspeed = 5.f;
	this->hpMax = 2;
	this->hp = this->hpMax;
	this->damage = 5;
	this->points = 5;
	this->attackCDMax = 5;
	this->attackCD = 00;
	this->rectSourceSprite = sf::IntRect(0, 0, 8, 8);
	this->secondCounter = sf::seconds(0.01f);
	this->range = 100;
	this->phaseno = 1;
	this->vision = 950;
	this->phaseCounter = sf::seconds(0.01f);
	this->type = 0;
}

Ghost::Ghost(int pos_x, int pos_y)
	:Enemy(pos_x, pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->sprite.setPosition(pos_x, pos_y);
}

Ghost::~Ghost()
{
}

void Ghost::movement(float offset_x, float offset_y, sf::RenderWindow* window)
{
	counter++;
	this->phaseCounter = this->phaseClock.getElapsedTime();
	if (this->phaseno == 0) {

		this->sprite.move(0, 0);
		if (this->phaseCounter.asSeconds() > 1.f) {
			this->phaseno = 1;
			this->phaseClock.restart();
		}


	}
	else if (this->phaseno == 1) {
		if (counter >= 5) {
			this->direction = random.generateRandom(5, 0);
			counter = 0;
		}
		if (this->direction == 1)
			this->sprite.move(0, movementspeed );
		else if (this->direction == 2)
			this->sprite.move(0, -movementspeed );
		else if (this->direction == 3)
			this->sprite.move(-movementspeed, 0);
		else if (this->direction == 4)
			this->sprite.move(movementspeed , 0);
		else {
			//no movement
		}
		this->sprite.move(aimDirNorm.x * movementspeed, aimDirNorm.y * movementspeed);

		if (this->phaseCounter.asSeconds() > 1.f) {
			this->phaseno = 0;
			this->phaseClock.restart();
		}
	}
	sprite.setTextureRect(rectSourceSprite);

	if (this->secondCounter.asSeconds() >= 0.2f)
	{

		counterWalking++;
		this->frameClock.restart();
	}
	if (counterWalking > 2) {
		counterWalking = 0;
	}
	if (rectSourceSprite.left > 56) {
		rectSourceSprite.left = 0;

	}
	else {

		rectSourceSprite.left = counterWalking * 8;
	}
}

void Ghost::attack()
{
	if (this->phaseno == 1) {
		Enemy::enemybullets.add(
			Bullet(this->textures["BULLETENEMY"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
				, this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2.f,
				this->aimDirNorm.x, this->aimDirNorm.y, 7.f, this->aimDirAngle, false, this->damage, this->range, 0

			)
		);
	}
}
