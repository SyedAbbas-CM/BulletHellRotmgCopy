#ifndef  TILEMAP_H
#define TILEMAP_H
#include"Random.h"
class Tilemap
{
public:
	bool isPassable;
	bool isExit;
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::FloatRect fBounds;
	sf::IntRect iBounds;
	//constructtos destructors
	Tilemap(std::string, float x, float y, bool, bool, float width,float height);
	virtual ~Tilemap();
	//functions
	bool setUpSprite(std::string);
	void movesprite(sf::Vector2f vector);
	const sf::FloatRect getBounds() const;
	const sf::Vector2f getPos() const;
};
#endif //TILEMAP_H
