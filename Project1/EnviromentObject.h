#pragma once
#include"Random.h"
class EnviromentObject
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	int spriteID;
	Random rand;
public:
	virtual void initTextureAndSprite() = 0;
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getbounds() const;
	void render(sf::RenderTarget& target);
	int getspriteID();
};

