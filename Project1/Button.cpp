#include "Button.h"

const bool Button::isPressed() const
{
	if (this->buttonstate == BTN_ACTIVE) {
		return true;
	}
	return false;
}

const bool Button::isHovered() const
{
	if (this->buttonstate == BTN_HOVER) {
		return true;
	}
	return false;
}

Button::Button(float x, float y, float width, float height,
	std::string text, sf::Font* font,
	sf::Color idleColor, sf::Color HoverColor, sf::Color ActiveColor)
{
	this->buttonstate = BTN_IDLE;
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::Black);
	this->text.setPosition(
		this->shape.getPosition().x+(this->shape.getGlobalBounds().width /2.f)/2.f,
		this->shape.getPosition().y+(this->shape.getGlobalBounds().height / 2.f) / 2.f);
	this->idleColor = idleColor;
	this->activeColor = ActiveColor;
	this->hoverColor = HoverColor;
	this->shape.setFillColor(this->idleColor);
}

Button::Button(float x, float y, float width, float height, std::string text, sf::Font* font)
{
	this->buttonstate = BTN_IDLE;
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition(
		this->shape.getPosition().x ,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) / 2.f);
	this->idleColor =   sf::Color::Black;
	this->activeColor = sf::Color(45,45,45,255);
	this->hoverColor =  sf::Color(15, 15, 15, 255);
	this->shape.setFillColor(this->idleColor);
}

Button::~Button()
{
}

void Button::update(const sf::Vector2f mousePos)
{
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 5.f),
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 5.f) );
	this->buttonstate = BTN_IDLE;
	//Update the booleans for the hovber and pressed 
	if (this->shape.getGlobalBounds().contains(mousePos)) {
		this->buttonstate = BTN_HOVER;
		//std::cout << "button pressed";
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->buttonstate = BTN_ACTIVE;
			//std::cout << "button pressed";
		}
	}
	switch (this->buttonstate) {
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;
	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;
	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
	//std::cout << this->shape.getPosition().x << "  " << this->shape.getPosition().y << "\n";
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
