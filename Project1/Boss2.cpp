#include "Boss2.h"

void Boss2::initTexture()
{
	if (!this->texture.loadFromFile("Textures/Enemies/MinotaurSheet.png"))
		std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
	this->textures["BULLETBOSS2"] = new sf::Texture();
	this->textures["BULLETBOSS2"]->loadFromFile("Textures/Projectiles/EnemyAttackNormal.png");
}

void Boss2::initSprite()
{
	this->sprite = sf::Sprite(texture);
	this->sprite.scale(5.f, 5.f);
}

void Boss2::initVariables()
{
	this->phaseno = 1;
	this->counterWalking = 0;
	this->type = 3;
	this->movementspeed = 10.f;
	this->movementspeed2 = 3.f;
	this->hpMax = 250;
	this->hp = this->hpMax;
	this->damage = 15;
	this->damage2 = 25;
	this->damage3 = 50;
	this->points = 5;
	this->attackCDMax = 5;
	this->attackCD = 00;
	this->rectSourceSprite = sf::IntRect(0, 0, 16, 16);
	this->range = 100;
	this->counter = 0;
	this->secondCounter = sf::seconds(0.01f);
	this->vision = 400;
}

bool Boss2::isBossSpawning()
{
	return false;
}

void Boss2::resetSpawnClock()
{
	this->phaseClock.restart();
}

sf::Time Boss2::getSpawnClock()
{
	return this->phaseCounter;
}

Boss2::Boss2(int pos_x, int pos_y)
	:Enemy(pos_x,pos_y)
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
	this->sprite.setPosition(pos_x, pos_y);
}

Boss2::~Boss2()
{
	
}

void Boss2::movement(float offset_x, float offset_y, sf::RenderWindow* window)
{
	this->phaseCounter = this->phaseClock.getElapsedTime();
	counter++;
	if (counter == 4) {
		this->direction = random.generateRandom(5, 0);
		counter = 0;
	}
		if (phaseno ==1) {
			if (this->direction == 1)
				this->sprite.move(0, movementspeed2 );
			else if (this->direction == 2)
				this->sprite.move(0, -movementspeed2 );
			else if (this->direction == 3)
				this->sprite.move(-movementspeed2 , 0);
			else if (this->direction == 4)
				this->sprite.move(movementspeed2 , 0);
			else {
				//no movement
			}
			if (phaseCounter.asSeconds() > 2.f) {
				phaseno = 2;
				phaseClock.restart();
				tempaim = aimDirNorm;
				tempangle = aimDirAngle;
			}
		}
		else if(phaseno ==2){
			if (enemyToPlayerdis > 100) {
				
				this->sprite.move(this->tempaim.x * movementspeed, this->tempaim.y * movementspeed);
			}
			if (phaseCounter.asSeconds() > 0.75f) {
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
	if (counterWalking > 5 ) {
		counterWalking = 0;
	}
	if (rectSourceSprite.left >= 100) {
		counterWalking = 0;

	}
	rectSourceSprite.left = counterWalking * 16;
}

void Boss2::attack()
{
	if (enemyToPlayerdis < 250.f) {
		if (this->phaseno == 2) {
			counterWalking = 4;
			rectSourceSprite.left = counterWalking * 16;
			sprite.setTextureRect(rectSourceSprite);
			Enemy::enemybullets.add(
				Bullet(this->textures["BULLETBOSS2"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
					, this->sprite.getPosition().y ,
					this->tempaim.x, this->tempaim.y, 20.f, this->tempangle - 45, false, this->damage, this->range, 0,2

				)
			);
			Enemy::enemybullets.add(
				Bullet(this->textures["BULLETBOSS2"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
					, this->sprite.getPosition().y ,
					this->tempaim.x, this->tempaim.y, 20.f, this->tempangle - 45, false, this->damage2, this->range, 0, 1.2

				)
			);
			Enemy::enemybullets.add(
				Bullet(this->textures["BULLETBOSS2"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
					, this->sprite.getPosition().y ,
					this->tempaim.x, this->tempaim.y, 20.f, this->tempangle - 45, false, this->damage3, this->range, 0, 1.2

				)
			);
			counterWalking = 5;
			rectSourceSprite.left = counterWalking * 16;
			sprite.setTextureRect(rectSourceSprite);
		}
	}
}

