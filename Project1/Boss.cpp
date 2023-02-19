#include "Boss.h"

void Boss::initTexture()
{
	if (!this->texture.loadFromFile("Textures/Enemies/RedKnightSpriteSheetResized.png"))
		std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
	this->textures["BULLETBOSS2"] = new sf::Texture();
	this->textures["BULLETBOSS2"]->loadFromFile("Textures/Projectiles/BossAttackFire.png");
	this->textures["BULLETBOSS1"] = new sf::Texture();
	this->textures["BULLETBOSS1"]->loadFromFile("Textures/Projectiles/EnemyAttackFireRound.png");
}
void Boss::initVariables(int type)
{
	this->phaseno = 1;
	this->counterWalking = 1;
	this->type = type;
	this->movementspeed = 4.5f;
	this->hpMax = 200;
	this->hp = this->hpMax;
	this->damage = 50;
	this->spread = 100.f;
	this->points = 5;
	this->attackCDMax = 15;
	this->attackCD = 00;
	this->rectSourceSprite = sf::IntRect(0, 0, 150, 168);
	this->range = 50;
	this->range2 = 150;
	this->counter = 0;
	this->secondCounter = sf::seconds(0.01f);
	this->bossIsSpawning = false;
	this->vision = 600;
	
}

void Boss::initSprite()
{
	this->sprite = sf::Sprite(texture);
	this->sprite.scale(0.5f, 0.5f);
}

void Boss::initVariables()
{

}

bool Boss::isBossSpawning()
{
	return bossIsSpawning;
}

void Boss::resetSpawnClock()
{
	this->spawnClock.restart();
}

sf::Time Boss::getSpawnClock()
{
	return this->spawnCounter;
}

Boss::Boss(int pos_x, int pos_y, int type)
	:Enemy(pos_x,pos_y)
{
	
	this->initTexture();
	this->initVariables(type);
	this->initSprite();
	this->sprite.setPosition(pos_x, pos_y);
	
}

Boss::~Boss()
{
}


void Boss::movement(float offset_x, float offset_y, sf::RenderWindow* window)
{
	this->spawnCounter = this->spawnClock.getElapsedTime();
	counter++;
	if (counter == 5) {
		this->direction = random.generateRandom(10,0);
		counter = 0;
	}
	if (this->hp > 35) {
		if (enemyToPlayerdis < 200) {
			if (this->direction == 1)
				this->sprite.move(0, movementspeed / 5);
			else if (this->direction == 2)
				this->sprite.move(0, -movementspeed / 5);
			else if (this->direction == 3)
				this->sprite.move(-movementspeed / 5, 0);
			else if (this->direction == 4)
				this->sprite.move(movementspeed / 5, 0);
			else {
				//no movement
			}
			this->attackCDMax = 10.f;
		}
		else {
			this->sprite.move(this->aimDirNorm.x * movementspeed, this->aimDirNorm.y * movementspeed);
			this->attackCDMax = 65.f;
		}
	}
	else {
		this->range = 125;
		if (enemyToPlayerdis < 200)
		this->sprite.move(-this->aimDirNorm.x * (movementspeed), -this->aimDirNorm.y * (movementspeed));
		else {
			if (counter >= 5) {
				this->direction = random.generateRandom(5, 0);
				counter = 0;
			}
			if (this->direction == 1)
				this->sprite.move(0, movementspeed);
			else if (this->direction == 2)
				this->sprite.move(0, -movementspeed);
			else if (this->direction == 3)
				this->sprite.move(-movementspeed, 0);
			else if (this->direction == 4)
				this->sprite.move(movementspeed, 0);
			else {
				//no movement
			}
			this->sprite.move(this->aimDirNorm.x * movementspeed, this->aimDirNorm.y * movementspeed);
		}
		bossIsSpawning = true;
		this->attackCDMax = 15.f;
		this->phaseno = 2;
	}
	sprite.setTextureRect(rectSourceSprite);

	if (this->secondCounter.asSeconds() >= 0.2f)
	{
		counterWalking++;
		this->frameClock.restart();
	}
	if (counterWalking > 2 ) {
		counterWalking = 1;
	}
	if (rectSourceSprite.left >= 500) {
		counterWalking = 1;

	}
		rectSourceSprite.left = counterWalking * 162;
}

void Boss::attack()
{	
	counterWalking = 0;
	if (this->phaseno == 1) {
		Enemy::enemybullets.add(
			Bullet(this->textures["BULLETBOSS1"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
				, this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2.f,
				this->aimDirNorm.x, this->aimDirNorm.y, 7.f, this->aimDirAngle , false, this->damage, this->range2, 0

			)
		);
		Enemy::enemybullets.add(
			Bullet(this->textures["BULLETBOSS1"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
				, this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2.f,
				this->aimDirNorm.x-0.15, this->aimDirNorm.y-0.15, 7.f, this->aimDirAngle , false, this->damage, this->range2, 0

			)
		);
		Enemy::enemybullets.add(
			Bullet(this->textures["BULLETBOSS1"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
				, this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2.f,
				this->aimDirNorm.x+0.15, this->aimDirNorm.y+0.15, 7.f, this->aimDirAngle , false, this->damage, this->range2, 0

			)
		);
	}
	else {
		Enemy::enemybullets.add(
			Bullet(this->textures["BULLETBOSS2"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
				, this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2.f,
				0, 1, 10,+ 45, false, this->damage, this->range, 0

			)
		);
		Enemy::enemybullets.add(
			Bullet(this->textures["BULLETBOSS2"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
				, this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2.f,
				0, -1, 10.f, + 45, false, this->damage, this->range, 0
			)
		);
		Enemy::enemybullets.add(
			Bullet(this->textures["BULLETBOSS2"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
				, this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2.f,
				1, 0, 10.f,  - 45, false, this->damage, this->range, 0
			)
		);
		Enemy::enemybullets.add(
			Bullet(this->textures["BULLETBOSS2"], this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f
				, this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2.f,
				-1, 0, 10.f,  - 45, false, this->damage, this->range, 0
			));
	}
}

void Boss::calculatedistances()
{
	enemyToPlayerdis = sqrt((pow(static_cast<int>(PlayerPos.x - CurrentPos.x), 2) + pow(static_cast<int>(PlayerPos.y - CurrentPos.y), 2)));
	aimDir =  (PlayerPos) - CurrentPos;
	

	aimDirNorm.x = aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
	aimDirNorm.y = aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
	aimDirAngle = static_cast<double>((atan((aimDir.y / aimDir.x)) * 180) / 3.142);
}

