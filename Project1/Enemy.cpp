#include "Enemy.h"
dArr<Bullet> Enemy::enemybullets;
SpriteManager* Enemy::spManager;

Enemy::Enemy(int pos_x, int pos_y) {
	
	this->sprite.setPosition(pos_x, pos_y);
}

Enemy::~Enemy() {

}

int Enemy::gethp() const
{
	return this->hp;
}
int Enemy::gettype() const
{
	return this->type;
}
//Accessors

bool Enemy::isBoss()
{
	if (this->type == 1) {
		return true;
	}
	else
		return false;
}

bool Enemy::inVision()
{
	if (enemyToPlayerdis <= this->vision) {
		return true;
	}
	return false;
}

const bool Enemy::canAttack()
{
	if (this->attackCD >= this->attackCDMax) {
		this->attackCD = 0.f;
		return true;
	}
	return false;
}

void Enemy::updatePos(sf::Vector2f Player,  sf::RenderWindow* window)
{
	this->CurrentPos = this->sprite.getPosition();
	this->PlayerPos = Player;
	this->windowE = window;
}



void Enemy::updateMovement()
{
}


//Functions
void Enemy::update(float offset_x, float offset_y, sf::Vector2f Player, sf::RenderWindow* window)
{
	this->secondCounter = frameClock.getElapsedTime();
	
	this->updateAttack();
	this->updatePos(Player, window);
	this->calculatedistances();
	this->movement(offset_x,offset_y,window);
	
}
void Enemy::render(sf::RenderTarget* target,float dt)
{
	target->draw(this->sprite);
}

void Enemy::updatehp(int damage)
{
	this->hp -= damage;
	if (this->hp < 0) {
		this->hp = 0;
	}

}

void Enemy::setSpriteManager(SpriteManager* spManager)
{
	Enemy::spManager = spManager;



}


void Enemy::calculatedistances()
{
	enemyToPlayerdis = sqrt((pow(static_cast<int>(PlayerPos.x - CurrentPos.x), 2)+ pow(static_cast<int>(PlayerPos.y - CurrentPos.y), 2)));
	aimDir = PlayerPos - CurrentPos;
	aimDirAngle = (float)((atan((aimDir.y / aimDir.x)) * 180) / 3.142);
	aimDirNorm.x = aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
	aimDirNorm.y = aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
}

void Enemy::updateAttack()
{
	
	if (this->attackCD < this->attackCDMax) {
		this->attackCD += 0.5f;
	}
	

}


