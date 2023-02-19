#pragma once
#include "Enemy.h"
class BlackKnight :
    public Enemy
{
private:
	int phaseno;
	void initTexture();
	void initSprite();
	void initVariables();
	void initVariables(int type);
	sf::Clock spawnClock;
	sf::Time spawnCounter;

public:
	BlackKnight(int pos_x, int pos_y, int type);
	~BlackKnight();
	void movement(float offset_x, float offset_y, sf::RenderWindow* window);
	void attack();
	
};

