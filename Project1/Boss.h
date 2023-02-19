#pragma once
#include "Enemy.h"
class Boss :
    public Enemy
{
private:
	int phaseno;
	float range2;
	float spread;
	void initTexture();
	void initSprite();
	void initVariables();
	void initVariables(int type);
	bool bossIsSpawning;
	double aimDirAngle2;
	double aimDirAngle3;
	sf::Clock spawnClock;
	sf::Time spawnCounter;
	
public:
	
	bool isBossSpawning();
	void resetSpawnClock();
	sf::Time getSpawnClock();
	Boss(int pos_x, int pos_y, int type);
	~Boss();
	void movement(float offset_x, float offset_y, sf::RenderWindow* window);
	void attack();
	void calculatedistances();
};

