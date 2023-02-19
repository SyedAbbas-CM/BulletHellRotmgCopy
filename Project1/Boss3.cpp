#include "Boss3.h"

void Boss3::initTexture()
{
	if (!this->texture.loadFromFile("Textures/Enemies/SilverKnight.png"))
		std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
	this->textures["BULLETBOSS2"] = new sf::Texture();
	this->textures["BULLETBOSS2"]->loadFromFile("Textures/Projectiles/Spear.png");
}

void Boss3::initSprite()
{
	this->sprite = sf::Sprite(texture);
	this->sprite.scale(5.f, 5.f);
}

void Boss3::initVariables()
{
	this->phaseno = 1;
	this->counterWalking = 0;
	this->type = 4;
	this->movementspeed = 10.f;
	this->movementspeed2 = 2.f;
	this->hpMax = 400;
	this->hp = this->hpMax;
	this->damage = 65;
	this->points = 5;
	this->attackCDMax = 15;
	this->attackCD = 00;
	this->rectSourceSprite = sf::IntRect(0, 0, 14, 16);
	this->range = 350;
	this->counter = 0;
	this->secondCounter = sf::seconds(0.01f);
	this->defense = 10;
	this->vision = 800;
}

bool Boss3::isBossSpawning()
{
	return false;
}

void Boss3::resetSpawnClock()
{
	this->phaseClock.restart();
}

sf::Time Boss3::getSpawnClock()
{
	return this->phaseCounter;
}

Boss3::Boss3(int pos_x, int pos_y)
	:Enemy(pos_x,pos_y)
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
}

Boss3::~Boss3()
{
}

void Boss3::movement(float offset_x, float offset_y, sf::RenderWindow* window)
{
	this->phaseCounter = this->phaseClock.getElapsedTime();
	counter++;
	if (counter == 4) {
		this->direction = random.generateRandom(5, 0);
		counter = 0;
	}
	if (phaseno == 1) {
		if (this->direction == 1)
			this->sprite.move(0, movementspeed2);
		else if (this->direction == 2)
			this->sprite.move(0, -movementspeed2);
		else if (this->direction == 3)
			this->sprite.move(-movementspeed2, 0);
		else if (this->direction == 4)
			this->sprite.move(movementspeed2, 0);
		else {
			//no movement
		}
		if (phaseCounter.asSeconds() > 0.5f) {
			phaseno = 2;
			phaseClock.restart();
			tempaim = aimDirNorm;
		}
	}
	else if (phaseno == 2) {
		if (enemyToPlayerdis > 10) {

			this->sprite.move(this->tempaim.x * movementspeed, this->tempaim.y * movementspeed);
		}
		if (phaseCounter.asSeconds() > 2.f) {
			phaseno = 1;
			phaseClock.restart();
		}
	}

	sprite.setTextureRect(rectSourceSprite);

	if (this->secondCounter.asSeconds() >= 0.1f)
	{
		counterWalking++;
		this->frameClock.restart();

	}
	if (counterWalking == 3) {
		counterWalking = 0;
	}
	if (counterWalking > 5) {
		counterWalking = 0;
	}
	if (rectSourceSprite.left >= 100) {
		counterWalking = 0;

	}
	rectSourceSprite.left = counterWalking * 16;
}

void Boss3::attack()
{
	if (enemyToPlayerdis < 500.f) {
		if (this->phaseno == 2) {
			counterWalking = 4;
			rectSourceSprite.left = counterWalking * 16;
			sprite.setTextureRect(rectSourceSprite);
			if (this->aimDirNorm.x <0 ) {
				this->aimDirAngle = this->aimDirAngle - 45 + 180;
			}
			if (this->aimDirNorm.x > 0) {
				this->aimDirAngle = this->aimDirAngle - 45 ;
			}
			Enemy::enemybullets.add(
				Bullet(this->textures["BULLETBOSS2"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
					, this->sprite.getPosition().y - this->sprite.getGlobalBounds().height / 2.f,
					this->aimDirNorm.x, this->aimDirNorm.y, 9.f, this->aimDirAngle , false, this->damage, this->range, 0, 4

				)
			);
			counterWalking = 5;
			rectSourceSprite.left = counterWalking * 16;
			sprite.setTextureRect(rectSourceSprite);
		}
	}
}
