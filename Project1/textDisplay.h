#pragma once
#include"Random.h"

class textDisplay
{
private:
	sf::Font font;
	void initFont();
	sf::Text text;
	int counter;
	int lifetime;
	bool deleted;
public:
	textDisplay(float posX,float posY,int dmgText);
	~textDisplay();
	void update();
	void render(sf::RenderTarget* target);
	bool textDeleted();
	
};

