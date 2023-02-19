#pragma once
#include"Random.h"
#include"dArr.h"
#include"Bullet.h"
#include"Entity.h"
#include"Inventory.h"
class Player:public Entity
{
private:
	std::map<sf::String, sf::Texture*> textures;
	
	sf::Texture texture;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
	float aimDirAngle;
	//accessories
	float movementspeed;
	int hp;
	int hpMax;
	float attackCooldown;
	bool playerOwner;
	float attackCooldownMax;
	float range;
	int vitality;
	float dexterity;
	int defense;
	//ScoreBoard Features
	int PotionsDranks;
	int EnemiesKilled;
	int BossesKilled;
	int DamageTaken;
	int DamageDealt;
	int ItemsBought;
	int goldAccumulated;
	


	//PlayerrGUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	//player resourcess
	sf::Clock frameClock;
	sf::Time secondCounter;
	float  hpCoolDown;
	float hpCoolDownMax;
	sf::IntRect rectSourceSprite;
	int counterWalking;
	int counterWalking2;
	//player bullet list 
	dArr<Bullet> bullets;
	
	//Private functions /


	void initVariables();
	void initTexture();
	void initSprite();
	void initHpbar();
	void animator(int direction);
	void calculatoAnglesandDistances(sf::Vector2f mousePos);
public:
	//accessors
	float getrange();
	void setrange(float newRange);

	Bullet& getBullet(unsigned index);
	void removeBullet(unsigned index);
	inline const int getBulletsSize()const { return this->bullets.size(); }
	//public stuff 
	void updateHpbar();
	int worldVelocity;
	sf::Vector2f playerCentre;
	Player();
	virtual ~Player();
	int damage;
	int direction;
	//inventory and item system
	Inventory playerINV;
	bool weaponequipped[3];	//Accessor for stats
	const int& getHp() const;
	const int& getHpMax() const;
	void increaseVitality(int inc);
	void increaseDexterity(float inc);
	int getDefense();
	void increaseDefense(int inc);
	void increaseSpeed(int inc);
	void operator +(int inc);
	//accessor for scoreboard system
	void incrementPotionsDrank(int i);
	void incrementEnemiesKIlled(int i);
	void incrementBossesKilled(int i);
	void incrementDamageTaken(int i);
	void incrementDamageDealth(int i);
	void incrementItemsBought(int i);
	void incrementgoldAccumulated(int i);

	int getPotionsDrank();
	int getEnemiesKIlled();
	int getBossesKIlled();
	int getDamageTaken();
	int getDamageDealth();
	int getItemsBought();
	int getgoldAccumulated();

	//FUnctions
	
	void stopVelocity();
	void resumeVelocity();
	const bool canAttack();
	void updateWindowsBollision(const sf::RenderTarget* target);
	void updateHp(const int damage);
	void PlayerMove();
	void attack(sf::Vector2f mousePos);
	void updateAttack();
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget& target);
	
	
};

