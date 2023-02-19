#ifndef BULLET_H
#define BULLET_H
#include"Random.h"
#include"dArr.h"
class Bullet
{
private:
	sf::Sprite shape;
	sf::Vector2f direction;
	Random random;
	float bulletspeed ;
	sf::Vector2f aimDirNorm;
	bool rotated = 0;
	sf::Vector2f Origin;
	float distancetoTravel;
	int damage;
	float range;
	int type;
	int counter;
public :
	sf::Vector2f currVelcoity;

	bool piercing=0;
	bool playerOwner;
	Bullet();
	Bullet(sf::Texture * texure,float pos_x, float pos_y,float dirX,float dirY,float movement_speed,float angle,bool playerOwner, int damage,float range,int type);
	Bullet(sf::Texture* texure, float pos_x, float pos_y, float dirX, float dirY, float movement_speed, float angle, bool playerOwner, int damage, float range, int type, float scale);
	virtual ~Bullet();

	//Accessor
	const sf::FloatRect getBounds() const;
	const sf::Vector2f getOrigin() const;
	const sf::Vector2f getposition() const;
	const int getdamage() const;
	const float getrange() const;
	//functions

	void update();
	void render(sf::RenderTarget* target);
};

#endif //!BULLET_H

