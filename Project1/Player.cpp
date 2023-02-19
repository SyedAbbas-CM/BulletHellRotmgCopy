#include "Player.h"
#include <iostream>
float Player::getrange()
{
	return this->range;
}
void Player::setrange(float newRange)
{
	this->range = newRange;
}
Bullet& Player::getBullet(unsigned index)
{
	if (index < 0 || index > this->bullets.size())
		throw"OUT OF BOUNDS! PLAYER::GETBULLET!";

	return this->bullets[index];
}
void Player::removeBullet(unsigned index)
{
	if (index < 0 || index > this->bullets.size())
		throw"OUT OF BOUNDS! PLAYER::REMOVEBULLET!";

	this->bullets.remove(index);
}
void Player::updateHpbar()
{
	float hpPercent = static_cast<float>(this->getHp()) / this->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(100.f * hpPercent, this->playerHpBar.getSize().y));
	this->playerHpBar.setPosition(this->getPos().x - this->getbounds().width / 3, this->getPos().y + this->getbounds().height);
	this->playerHpBarBack.setPosition(this->playerHpBar.getPosition());
}
void Player::initVariables()
{
	this->hpMax = 200;
	this->hp = this->hpMax;
	this->movementspeed = 15.f;
	this->attackCooldownMax = 15.f;
	this->attackCooldown = this->attackCooldownMax;
	this->damage = 0;
	this->defense = 0;
	this->range = 150.f;
	this->vitality = 1;
	this->dexterity = 0;
	this->hpCoolDown =this->hpCoolDownMax ;
	this->hpCoolDownMax = 15;
	this->rectSourceSprite = sf::IntRect(0, 1, 41, 40);
	this->PotionsDranks = 0;
	this->EnemiesKilled = 0;
	this->BossesKilled = 0;
	this->DamageTaken = 0;
	this->DamageDealt = 0;
	this->ItemsBought = 0;
	this->goldAccumulated = 0;

}
void Player::initTexture()
{
	//Load Texure from file
	if (!this->texture.loadFromFile("Textures/Warrior/WarriorSheet.png"))
		std::cout << "ERROR::PlAYER::INITTEXTURE:: could not load texture file\n";
	this->textures["BULLET1"] = new sf::Texture();
	this->textures["BULLET1"]->loadFromFile("Textures/Projectiles/BULLET.png");
	this->textures["BULLET2"] = new sf::Texture();
	this->textures["BULLET2"]->loadFromFile("Textures/Projectiles/Weapon0Proj.png");
	this->textures["BULLET3"] = new sf::Texture();
	this->textures["BULLET3"]->loadFromFile("Textures/Projectiles/Weapon1Proj.png");
	this->textures["BULLET4"] = new sf::Texture();
	this->textures["BULLET4"]->loadFromFile("Textures/Projectiles/Weapon2Proj.png");
	this->textures["BULLET5"] = new sf::Texture();
	this->textures["BULLET5"]->loadFromFile("Textures/Projectiles/Weapon3Proj.png");
	this->textures["BULLET6"] = new sf::Texture();
	this->textures["BULLET6"]->loadFromFile("Textures/Projectiles/Weapon4Proj.png");
	this->textures["BULLET7"] = new sf::Texture();
	this->textures["BULLET7"]->loadFromFile("Textures/Projectiles/EnemyAttackNormal.png");
}
void Player::initSprite()
{
	//Set the texure to the sprite
	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.9f,0.9f);
	sprite.setTextureRect(rectSourceSprite);
	//Resize the sprites
}
void Player::initHpbar()
{
	this->playerHpBar.setSize(sf::Vector2f(100.f, 15.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(650.f, 40.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color::Black);
	this->playerHpBar.setScale(0.4f, 0.3f);
	this->playerHpBarBack.setScale(0.4f, 0.3f);
}
void Player::calculatoAnglesandDistances(sf::Vector2f mousePos)
{
;
	//std::cout << "  x:  "<<aimDirAngle<<"\n";
	aimDir = mousePos - sf::Vector2f(400.f, 300.f);
	aimDirAngle = static_cast<float>((atan((aimDir.y / aimDir.x)) * 180) / 3.142);

	aimDirNorm.x = aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
	aimDirNorm.y = aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
}
Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initHpbar();
	this->sprite.setPosition(0, 0);
}
Player::~Player()
{
	
}

const int& Player::getHp() const
{
	return this->hp;
}
const int& Player::getHpMax() const
{
	return this->hpMax;
	
}

void Player::increaseVitality(int inc)
{
	this->vitality = vitality + inc;
}

void Player::increaseDexterity(float inc)
{
	this->dexterity = dexterity + inc;
}

void Player::increaseDefense(int inc)
{
	this->defense = this->defense + inc;
}

void Player::increaseSpeed(int inc)
{
	this->movementspeed = this->movementspeed + inc;
}


void Player::operator+(int inc)
{
	this->hpMax += inc;
}

void Player::incrementPotionsDrank(int i)
{
	this->PotionsDranks += i;
}

void Player::incrementEnemiesKIlled(int i)
{
	this->EnemiesKilled += i;
}

void Player::incrementBossesKilled(int i)
{
	this->BossesKilled += i;
}

void Player::incrementDamageTaken(int i)
{
	this->DamageTaken += i;
}

void Player::incrementDamageDealth(int i)
{
	this->DamageDealt += i;
}

void Player::incrementItemsBought(int i)
{
	this->ItemsBought += i;
}

void Player::incrementgoldAccumulated(int i)
{
	this->goldAccumulated += i;
}

int Player::getPotionsDrank()
{
	return this->PotionsDranks;
}

int Player::getEnemiesKIlled()
{
	return this->EnemiesKilled;
}

int Player::getBossesKIlled()
{
	return this->BossesKilled;
}

int Player::getDamageTaken()
{
	return this->DamageTaken;
}

int Player::getDamageDealth()
{
	return this->DamageDealt;
}

int Player::getItemsBought()
{
	return this->ItemsBought;
}

int Player::getgoldAccumulated()
{
	return this->goldAccumulated;
}

int Player::getDefense()
{
	return this->defense;
}

void Player::animator(int direction)
{
	sprite.setTextureRect(rectSourceSprite);
	if (this->direction == 1) {
		counterWalking2 = 1;
	}
	else if (this->direction == 2) {
		counterWalking2 = 2;
	}
	else {
		counterWalking2 = 0;
	}
	if (this->direction == 3) {
		this->sprite.setScale(-0.9f,0.9f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width/0.9f,0.9f);
	}
	else if(this->direction == 4) {
		this->sprite.setScale(0.9f, 0.9f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	if (this ->direction == 6|| this->direction == 8) {
		this->sprite.setScale(-0.9f, 0.9f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 0.9f, 0.9f);
	}
	else if (this->direction == 5 || this->direction == 7) {
		this->sprite.setScale(0.9f, 0.9f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	if (this->secondCounter.asSeconds() >= 0.1f)
	{

		counterWalking++;
		this->rectSourceSprite = sf::IntRect(0, 1, 40, 40);
		this->frameClock.restart();
	}
	if (counterWalking == 2 && (this->direction != 1 && this->direction != 2)) {
		counterWalking = 0;
		this->rectSourceSprite = sf::IntRect(0, 1, 40, 40);
	}
	if (counterWalking > 2) {
		counterWalking = 0;
	}
	if (rectSourceSprite.left > 240) {
		rectSourceSprite.left = 0;

	}
	else {

		rectSourceSprite.left = counterWalking * 41;
		rectSourceSprite.top = (counterWalking2 * 40) +1;
	}
}

void Player::stopVelocity()
{
	this->movementspeed = 0;
}
void Player::resumeVelocity()
{
	this->movementspeed = 5;
}
const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax) {
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}
void Player::updateWindowsBollision(const sf::RenderTarget* target)
{
	
	if (this->sprite.getGlobalBounds().left <= 0.f)
		this->sprite.setPosition(0, this->sprite.getGlobalBounds().top);
	//Right
	if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= 3000)
		this->sprite.setPosition(3000 - this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().top);
	//Top
	if (this->sprite.getGlobalBounds().top <= 0.f)
		this->sprite.setPosition(this->sprite.getGlobalBounds().left, 0.f);
	//Bottom
	if (this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= 3000)
		this->sprite.setPosition(this->sprite.getGlobalBounds().left,3000 - this->sprite.getGlobalBounds().height);
		
}
void Player::updateHp(const int damage)
{

	if (this->hp > 0) {
		if ((damage - defense) < 0) {
			this->hp = this->hp;
		}
		else {
			this->hp -= (damage - defense);
		}
	}
	if (this->hp < 0) {
		this->hp = 0
			;
	}
	
}
void Player::PlayerMove()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

		this->sprite.move(this->movementspeed / 1.5, -this->movementspeed / 1.5);
		this->direction = 5;
		this->animator(this->direction);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		this->sprite.move(-this->movementspeed / 1.5, -this->movementspeed / 1.5);
		this->direction = 6;
		this->animator(this->direction);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

		this->sprite.move(this->movementspeed / 1.5, this->movementspeed / 1.5);
		this->direction = 7;
		this->animator(this->direction);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		this->sprite.move(-this->movementspeed / 1.5, this->movementspeed / 1.5);
		this->direction = 8;
		this->animator(this->direction);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		
			this->sprite.move(-this->movementspeed, 0.f);
			this->direction = 3;
			this->animator(this->direction);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		
			this->sprite.move(this->movementspeed, 0.f);
			this->direction = 4;
			this->animator(this->direction);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		
			this->sprite.move(0.f, -this->movementspeed);
			this->direction = 2;
			this->animator(this->direction);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		
			this->sprite.move(0.f, this->movementspeed);
			this->direction = 1;
			this->animator(this->direction);
	}
}
void Player::attack(sf::Vector2f mousePos)
{
	this->calculatoAnglesandDistances( mousePos);

	if (this->playerINV.itemListEquipped[0][1]) {
		this->bullets.add(
			Bullet(this->textures["BULLET1"], (this->sprite.getPosition().x + (this->sprite.getGlobalBounds().width / 2)),
				(this->sprite.getPosition().y + (this->sprite.getGlobalBounds().height / 2)),
				aimDirNorm.x, aimDirNorm.y, 5.f, aimDirAngle, true, 1+ this->damage, this->range, 0)
		);
	}
	if (this->playerINV.itemListEquipped[1][1]) {
		if (this->aimDirNorm.x < 0) {
			this->aimDirAngle = this->aimDirAngle + 90 ;
		}
		if (this->aimDirNorm.x > 0) {
			this->aimDirAngle = this->aimDirAngle + 90+180;
		}
		this->bullets.add(
			Bullet(this->textures["BULLET2"], (this->sprite.getPosition().x + (this->sprite.getGlobalBounds().width / 2)),
				(this->sprite.getPosition().y + (this->sprite.getGlobalBounds().height / 2)),
				aimDirNorm.x, aimDirNorm.y, 5.f, aimDirAngle, true, 4+ this->damage, this->range, 0,0.85)
		);
	}
	if (this->playerINV.itemListEquipped[2][1]) {
		this->range = 225;
		if (this->aimDirNorm.x < 0) {
			this->aimDirAngle = this->aimDirAngle + 90;
		}
		if (this->aimDirNorm.x > 0) {
			this->aimDirAngle = this->aimDirAngle + 90 + 180;
		}
		this->bullets.add(
			Bullet(this->textures["BULLET3"], (this->sprite.getPosition().x + (this->sprite.getGlobalBounds().width / 2)),
				(this->sprite.getPosition().y + (this->sprite.getGlobalBounds().height / 2)),
				aimDirNorm.x, aimDirNorm.y, 5.f, aimDirAngle, true, 8 + this->damage, this->range, 0, 0.85)
		);
	}
	if (this->playerINV.itemListEquipped[3][1]) {
		this->range = 200;;
		if (this->aimDirNorm.x < 0) {
			this->aimDirAngle = this->aimDirAngle + 90;
		}
		if (this->aimDirNorm.x > 0) {
			this->aimDirAngle = this->aimDirAngle + 90 + 180;
		}
		this->bullets.add(
			Bullet(this->textures["BULLET4"], (this->sprite.getPosition().x + (this->sprite.getGlobalBounds().width / 2)),
				(this->sprite.getPosition().y + (this->sprite.getGlobalBounds().height / 2)),
				aimDirNorm.x, aimDirNorm.y, 5.f, aimDirAngle, true, 12 + this->damage, this->range, 0, 0.85)
		);
	}
	if (this->playerINV.itemListEquipped[4][1]) {
		this->range = 150;
		if (this->aimDirNorm.x < 0) {
			this->aimDirAngle = this->aimDirAngle + 90;
		}
		if (this->aimDirNorm.x > 0) {
			this->aimDirAngle = this->aimDirAngle + 90 + 180;
		}
		this->bullets.add(
			Bullet(this->textures["BULLET5"], (this->sprite.getPosition().x + (this->sprite.getGlobalBounds().width / 2)),
				(this->sprite.getPosition().y + (this->sprite.getGlobalBounds().height / 2)),
				aimDirNorm.x, aimDirNorm.y, 5.f, aimDirAngle, true, 15 + this->damage, this->range, 0, 0.85)
		);
	}
	if (this->playerINV.itemListEquipped[5][1]) {
		if (this->aimDirNorm.x < 0) {
			this->aimDirAngle = this->aimDirAngle + 90;
		}
		if (this->aimDirNorm.x > 0) {
			this->aimDirAngle = this->aimDirAngle + 90 + 180;
		}
		this->bullets.add(
			Bullet(this->textures["BULLET6"], (this->sprite.getPosition().x + (this->sprite.getGlobalBounds().width / 2)),
				(this->sprite.getPosition().y + (this->sprite.getGlobalBounds().height / 2)),
				aimDirNorm.x, aimDirNorm.y, 5.f, aimDirAngle, true, 18 + this->damage, this->range, 0, 0.85)
		);
	}
	if (this->playerINV.itemListEquipped[6][1]) {
		this->bullets.add(
			Bullet(this->textures["BULLET7"], (this->sprite.getPosition().x + (this->sprite.getGlobalBounds().width / 2)),
				(this->sprite.getPosition().y + (this->sprite.getGlobalBounds().height / 2)),
				aimDirNorm.x, aimDirNorm.y, 5.f, aimDirAngle-45, true, 21 + this->damage, this->range, 0, 1.2)
		);
	}
	
}
void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax )
		this->attackCooldown += (0.5f + this->dexterity);
	
	if (this->hpCoolDown >= this->hpCoolDownMax && this->hp < this->hpMax) {
		this->hp += this->vitality;
		this->hpCoolDown = 0;
	}
	else {
		this->hpCoolDown += 0.5;
	}
}
void Player::update(const sf::RenderTarget* target)
{
	
	this->secondCounter = this->frameClock.getElapsedTime();
	this->updateAttack();
	playerCentre = sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y);
	this->updateWindowsBollision(target);
	this->updateHpbar();

}
void Player::render(sf::RenderTarget& target)
{
	
	target.draw(this->sprite);
	target.draw(this->playerHpBarBack);
	target.draw(this->playerHpBar);
}
