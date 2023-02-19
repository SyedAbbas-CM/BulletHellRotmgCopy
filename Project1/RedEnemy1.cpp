#include "RedEnemy1.h"

void RedEnemy1::initTexture()
{

	if (!this->texture.loadFromFile("Textures/Enemies/RedEnemy2.png"))
		std::cout << "ERROR::enemy::INITTEXTURE:: could not load texture file\n";
	this->textures["BULLETENEMY"] = new sf::Texture();
	this->textures["BULLETENEMY"]->loadFromFile("Textures/Projectiles/EnemyAttackNormal.png");
}

void RedEnemy1::initSprite()
{
	this->sprite = sf::Sprite(texture);
	this->sprite.scale(1.f, 1.f);
}

void RedEnemy1::initVariables()
{
	this->counterWalking = 0;
	this->movementspeed = 3.f;
	this->hpMax = 10;
	this->hp = this->hpMax;
	this->damage = 10;
	this->points = 5;
	this->attackCDMax = 3;
	this->attackCD = 00;
	this->rectSourceSprite = sf::IntRect(0, 0, 40, 40);
	this->secondCounter = sf::seconds(0.01f);
	this->range = 100;
	this->phaseno = 1;
	this->vision = 450;
	this->phaseCounter = sf::seconds(0.01f);
	this->type = 0;
}

RedEnemy1::RedEnemy1(int pos_x, int pos_y, int type)
	:Enemy(pos_x, pos_y)
{

	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->sprite.setPosition(pos_x, pos_y);
}

RedEnemy1::~RedEnemy1()
{
}

void RedEnemy1::movement(float offset_x, float offset_y, sf::RenderWindow* window)
{
	this->phaseCounter = this->phaseClock.getElapsedTime();
	if (this->phaseno == 0) {

		this->sprite.move(aimDirNorm.x * movementspeed, aimDirNorm.y * movementspeed);
		tempaim = aimDirNorm;
		if(this->phaseCounter.asSeconds() > 2.f){
			this->phaseno = 1;
			this->phaseClock.restart();
		}
		
		
	}
	else if(this->phaseno ==1)  {

		this->sprite.move(0, 0);
		this->bulletAimDir =  this->aimDirNorm + 5.f * ( this->tempaim);


		if (this->phaseCounter.asSeconds() > 0.3f) {
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
	if (rectSourceSprite.left > 240) {
		rectSourceSprite.left = 0;

	}
	else {

		rectSourceSprite.left = counterWalking * 40;
	}
}

void RedEnemy1::attack()
{
	if (this->phaseno == 1) {
		Enemy::enemybullets.add(
			Bullet(this->textures["BULLETENEMY"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
				, this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2.f,
				this->bulletAimDir.x, this->bulletAimDir.y, 2.f, this->aimDirAngle - 45 , false, this->damage, this->range, 0

			)
		);
	}
}




