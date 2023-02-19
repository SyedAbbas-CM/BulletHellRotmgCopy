#include "textDisplay.h"

void textDisplay::initFont()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")) {
		std::cout<<"error in font";
	}
}

textDisplay::textDisplay(float posX, float posY, int dmgText)
{
	std::stringstream ss;
	ss << "-"<<dmgText;
	this->initFont();
	text.setPosition(posX, posY);
	text.setFont(font);
	text.setString(ss.str());
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(40);
	this->lifetime = 70;
	this->counter = 0;
	this->deleted = false;
}

textDisplay::~textDisplay()
{
}

void textDisplay::update()
{
	text.move(0, -2);
	counter = counter + 5;
	if (this->counter == this->lifetime) {
		this->deleted = true;
	}
}

void textDisplay::render(sf::RenderTarget* target)
{
	target->draw(this->text);
}

bool textDisplay::textDeleted()
{
	return this->deleted;
}
