#pragma once
#include "Enemy.h"
class Ghost :
    public Enemy
{
private:
	void initTexture();
	void initSprite();
	void initVariables();
	int phaseno;
	sf::Clock phaseClock;
	sf::Time phaseCounter;
public:
	Ghost(int pos_x, int pos_y);
	~Ghost();
	void movement(float offset_x, float offset_y, sf::RenderWindow* window);
	void attack();

};

