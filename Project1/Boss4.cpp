#include "Boss4.h"

void Boss4::initTexture()
{
	if (!this->texture.loadFromFile("Textures/Enemies/Enemy4.png"))
		std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
	this->textures["BULLETBOSS2"] = new sf::Texture();
	this->textures["BULLETBOSS2"]->loadFromFile("Textures/Projectiles/BossAttackDark.png");
}

void Boss4::initSprite()
{
	this->sprite = sf::Sprite(texture);
	this->sprite.scale(5.f, 5.f);
}

void Boss4::initVariables()
{
	this->phaseno = 1;
	this->counterWalking = 0;
	this->type = 4;
	this->movementspeed = 7.f;
	this->hpMax = 175;
	this->hp = this->hpMax;
	this->damage = 15;
	this->points = 5;
	this->attackCDMax = 2;
	this->attackCD = 00;
	this->rectSourceSprite = sf::IntRect(0, 0, 16, 16);
	this->range = 200;
	this->counter = 0;
	this->secondCounter = sf::seconds(0.01f);
	this->vision = 400;
	this->bulletAimDir.x = 1;
	this->bulletAimDir.y = 1;
}

bool Boss4::isBossSpawning()
{
	return false;
}

void Boss4::resetSpawnClock()
{
	this->phaseClock.restart();
}

sf::Time Boss4::getSpawnClock()
{
	return this->phaseCounter;
}

Boss4::Boss4(int pos_x, int pos_y)
	:Enemy(pos_x,pos_y)
{
	this->time = -360;
	this->initTexture();
	this->initSprite();
	this->initVariables();
	this->sprite.setPosition(pos_x, pos_y);
}

Boss4::~Boss4()
{
	
}

void Boss4::movement(float offset_x, float offset_y, sf::RenderWindow* window)
{



	this->phaseCounter = this->phaseClock.getElapsedTime();
	if (phaseno == 1) {
		if (phaseCounter.asSeconds() > 1.f) {
			phaseno = 2;
			phaseClock.restart();
		}
	}
	else if (phaseno == 2) {
		if (enemyToPlayerdis > 25) {
			this->sprite.move(this->aimDirNorm.x * movementspeed, this->aimDirNorm.y * movementspeed);
		}
		if (phaseCounter.asSeconds() > 3.f) {
			phaseno = 1;
			phaseClock.restart();
		}
	}

	sprite.setTextureRect(rectSourceSprite);

	if (this->secondCounter.asSeconds() >= 0.2f)
	{
		counterWalking++;
		this->frameClock.restart();

	}
	if (counterWalking == 3) {
		counterWalking = 0;
	}
	if (counterWalking > 2) {
		counterWalking = 0;
	}
	if (rectSourceSprite.left >= 100) {
		counterWalking = 0;

	}
	rectSourceSprite.left = counterWalking * 16;
}

void Boss4::attack()
{

	if (this->phaseno == 1) {

		Enemy::enemybullets.add(
			Bullet(this->textures["BULLETBOSS2"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
				, this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2.f,
				this->bulletAimDir.x, this->bulletAimDir.y, 5.f, 0, false, this->damage, this->range, 0, 0.7
			)
		);
		if (this->secondCounter.asSeconds() >= 0.1f) {
			counterWalking = 4;
			rectSourceSprite.left = counterWalking * 16;
			sprite.setTextureRect(rectSourceSprite);
			this->frameClock.restart();
		}
		else {
			counterWalking = 5;
			rectSourceSprite.left = counterWalking * 16;
			sprite.setTextureRect(rectSourceSprite);
		}
	}
}

	
	

void Boss4::calculatedistances()
{
	if (this->phaseno == 1) {
		time += 1;
	}
	enemyToPlayerdis = sqrt((pow(static_cast<int>(PlayerPos.x - CurrentPos.x), 2) + pow(static_cast<int>(PlayerPos.y - CurrentPos.y), 2)));
	this->bulletAimDir.x = cos(time);
	this->bulletAimDir.y = sin(time);


	aimDir = PlayerPos - CurrentPos;
	aimDirAngle = static_cast<float>((atan((aimDir.y / aimDir.x)) * 180) / 3.142);
	aimDirNorm.x = aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
	aimDirNorm.y = aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
	if (time >= 360)
		time = -360;
}
