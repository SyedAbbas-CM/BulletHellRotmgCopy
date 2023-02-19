#pragma once
#include "Enemy.h"
class Boss2 :
    public Enemy
{
	int phaseno;
	float range;
	void initTexture();
	void initSprite();
	void initVariables();
	bool bossIsSpawning;
	sf::Vector2f tempaim;
	float tempangle;
	sf::Clock phaseClock;
	sf::Time phaseCounter;
	int damage2;
	int damage3;
	int movementspeed2;

public:

	bool isBossSpawning();
	void resetSpawnClock();
	sf::Time getSpawnClock();
	Boss2(int pos_x, int pos_y);
	~Boss2();
	void movement(float offset_x, float offset_y, sf::RenderWindow* window);
	void attack();
};

