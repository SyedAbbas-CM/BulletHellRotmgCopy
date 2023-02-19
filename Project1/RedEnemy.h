#pragma once
#include "Enemy.h"
#include"SpriteManager.h"
class BasicEnemy :
    public Enemy
{
private:
	virtual void initTexture();
	virtual void initSprite();
	virtual void initVariables();
	static bool textureloaded;
	static void loadedset();

public:
	void movement(float offset_x, float offset_y, sf::RenderWindow* window);
	void attack();
	BasicEnemy(int pos_x, int pos_y);
	void calculatedistances();
	
};

