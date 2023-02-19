#pragma once
#include "Enemy.h"
class RedEnemy1 :
	public Enemy
{
private:
	void initTexture();
	void initSprite();
	void initVariables();
	int phaseno;
	sf::Clock phaseClock;
	sf::Time phaseCounter;
	sf::Vector2f tempaim;
public:
	RedEnemy1(int pos_x, int pos_y, int type);
	~RedEnemy1();
	void movement(float offset_x, float offset_y, sf::RenderWindow* window);
	void attack();

};
