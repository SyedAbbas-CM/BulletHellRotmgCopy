#include "RedEnemy.h"
bool BasicEnemy::textureloaded=0;
void BasicEnemy::initTexture()
{
	if (!textureloaded) {
		Enemy::spManager->LoadTextureEnemy("RedEnemy","Textures/Enemies/RedEnemy3.png");
		Enemy::spManager->LoadTextureBullet("BULLETENEMY", "Textures/Projectiles/ENEMYATTACKFIRE.png");
		BasicEnemy::loadedset();
	}
	

}

void BasicEnemy::initSprite()
{
	this->sprite = sf::Sprite(*Enemy::spManager->getTextureEnemy("RedEnemy"));
	this->sprite.scale(1.f, 1.f);
	
}

void BasicEnemy::initVariables()
{
	this->type = 0;
	this->counterWalking = 0;
	this->movementspeed = 4.f;
	this->hpMax = 3;
	this->hp = this->hpMax;
	this->damage = 0;
	this->points = 5;
	this->attackCDMax = 150;
	this->attackCD = 00;
	this->rectSourceSprite = sf::IntRect(0, 0, 40, 40);
	this->secondCounter = sf::seconds(0.01f);
	this->range = 50;
	this->counter = 0;
	this->vision = 1000;
}

void BasicEnemy::loadedset()
{
	textureloaded = 1;


}

void BasicEnemy::movement(float offset_x, float offset_y, sf::RenderWindow* window)
{
	counter++;
	this->sprite.move(aimDirNorm.x, aimDirNorm.y);


	sprite.setTextureRect(rectSourceSprite);
	if (this->secondCounter.asSeconds() >= 0.2f)
	{
		counterWalking++;
		this->rectSourceSprite = sf::IntRect(0, 0, 40, 40);
		this->frameClock.restart();
	}
	if (counterWalking == 3) {
		counterWalking = 5;
		this->rectSourceSprite = sf::IntRect(0, 0, 50, 40);
	}
	if (counterWalking > 5) {
		counterWalking = 0;
	}
	if (rectSourceSprite.left > 240) {
		rectSourceSprite.left = 0;
	}
	else {
		rectSourceSprite.left = counterWalking * 40;
	}
}

void BasicEnemy::attack()
{
	/*Enemy::enemybullets.add(
		Bullet(Enemy::spManager->getTextureBullet("BULLETENEMY"), this->sprite.getPosition().x
				, this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2.f,
				this->aimDirNorm.x, this->aimDirNorm.y, 3.f, this->aimDirAngle - 45, false, this->damage, this->range, 0

			)
		);*/
}

BasicEnemy::BasicEnemy(int pos_x, int pos_y)
	:Enemy(pos_x,pos_y)
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
	this->sprite.setPosition(pos_x, pos_y);
}

void BasicEnemy::calculatedistances()
{
	enemyToPlayerdis = sqrt((pow(static_cast<int>(PlayerPos.x - CurrentPos.x), 2) + pow(static_cast<int>(PlayerPos.y - CurrentPos.y), 2)));
	aimDirAngle = (float)((atan((aimDir.y / aimDir.x)) * 180) / 3.142);
	if (enemyToPlayerdis < this->vision) {
		aimDir = PlayerPos - CurrentPos;
		aimDirAngle = (float)((atan((aimDir.y / aimDir.x)) * 180) / 3.142);
		aimDirNorm.x = aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
		aimDirNorm.y = aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
	}
	else {
		if (counter == 40) {
			this->directionX = random.generateRandom(1000, -1000);
			this->directionY = random.generateRandom(1000, -1000);
			aimDir.x = this->directionX;
			aimDir.y = this->directionY;
			aimDirNorm.x = aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
			aimDirNorm.y = aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
			counter = 0;
		}
	}
}
