#pragma once
#include"Random.h"
class Entity
{
private:
	
protected:
	sf::Sprite sprite;
	sf::RectangleShape rect;
public:
	Entity(int posx,int  posy);
	Entity();
	//Accessor
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getbounds() const;
	

	//Modifeirs
	virtual void initTexture() = 0;
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
};

