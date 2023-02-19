#pragma once
#include "Enemy.h"
class Skeleton :
    public Enemy
{
private:
	void initTexture();
	void initSprite();
	void initVariables();
	bool flagy = false;
	bool flagyx = false;
	int phaseno;
	sf::Clock phaseClock;
	sf::Time phaseCounter;
	sf::Vector2f tempaim;
public:
	Skeleton(int pos_x, int pos_y);
	~Skeleton();
	void movement(float offset_x, float offset_y, sf::RenderWindow* window);
	void attack();
};

