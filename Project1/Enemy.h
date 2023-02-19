#pragma once
#include"Bullet.h"
#include"Entity.h"
#include"SpriteManager.h"
class Enemy:public Entity
{
protected:
	//basic SFML Resources
	
	sf::Texture texture;
	sf::Vector2f PlayerPos;
	sf::Vector2f CurrentPos;
	sf::RenderWindow* windowE;

	//enemy stats
	int type;
	float movementspeed;
	int hp;
	int hpMax;
	int points;
	float range;
	float attackCD;
	float attackCDMax;

	//pure virtual functions
	virtual void initTexture() = 0;
	virtual void initSprite() = 0;
	virtual void initVariables() = 0;
	
	//Bullet Player Interactions 
	sf::Vector2f aimDir;
	sf::Vector2f bulletAimDir;
	float directionX;
	float directionY;
	float enemyToPlayerdis;
	
	//resources for enenemy
	sf::Clock frameClock;
	sf::Time secondCounter;
	int counterWalking;
	Random random;
	int counter;
	int vision;
	sf::IntRect rectSourceSprite;
	
public:
	//animation
	Enemy(int pos_x, int pos_y);
	virtual ~Enemy();
	int damage;
	float aimDirAngle;
	sf::Vector2f aimDirNorm;
	//Accessors
	int gethp() const;
	int gettype() const;
	//pure virtual enemy functions
	virtual void attack()=0;
	virtual void movement(float offset_x, float offset_y, sf::RenderWindow* window) = 0;
	//FUnctions
	virtual void calculatedistances();
	virtual void updateAttack();
	virtual void updateMovement();
	bool isBoss();
	bool inVision();
	const bool canAttack();
	void updatePos(sf::Vector2f Player,  sf::RenderWindow* window);
	void update(float offset_x, float offset_y, sf::Vector2f Player, sf::RenderWindow* window);
	void render(sf::RenderTarget* target,float dt);
	void updatehp(int damage);
	friend class SpriteManager;
	static SpriteManager* spManager;
	static void setSpriteManager(SpriteManager* spManager);
	//Static
	static dArr<Bullet> enemybullets;
};


