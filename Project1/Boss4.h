#pragma once
#include "Enemy.h"
class Boss4 :
    public Enemy
{
	int phaseno;
	float range;
	void initTexture();
	void initSprite();
	void initVariables();
	bool bossIsSpawning;
	sf::Clock phaseClock;
	sf::Time phaseCounter;
	int time;

public:

	bool isBossSpawning();
	void resetSpawnClock();
	sf::Time getSpawnClock();
	Boss4(int pos_x, int pos_y);
	~Boss4();
	void movement(float offset_x, float offset_y, sf::RenderWindow* window);
	void attack();
	void calculatedistances();
};


