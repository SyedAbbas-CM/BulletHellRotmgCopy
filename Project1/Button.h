#pragma once
#include"Random.h"
enum button_states { BTN_IDLE = 0, BTN_HOVER,BTN_ACTIVE };
class Button
{
public:
	short unsigned buttonstate;
	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
	const bool isPressed() const;
	const bool isHovered() const;
	Button(float x,float y,float width,float height,std::string text,sf::Font* font
	,sf::Color idleColor, sf::Color HoverColor, sf::Color ActiveColor);
	Button(float x, float y, float width, float height, std::string text, sf::Font* font);
	virtual ~Button();
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

	//Accessors
};

