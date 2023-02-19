#include "IntroState.h"

void IntroState::initVariables()
{
}

void IntroState::initBackGround()
{

	this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	this->background.setPosition(this->window->getPosition().x - (this->background.getGlobalBounds().width / 2.5f),
		this->window->getPosition().y - (this->background.getGlobalBounds().height / 4));
	this->background.setFillColor(sf::Color(75, 75, 75, 255));
	this->Intro.setFont(this->font);
	this->Intro.setCharacterSize(30);
	this->Intro.setFillColor(sf::Color::Yellow);
	this->Intro.setPosition(0, 0);

	this->Intro2.setFont(this->font);
	this->Intro2.setCharacterSize(30);
	this->Intro2.setFillColor(sf::Color::Yellow);
	this->Intro2.setPosition(0, 40);

	this->Intro3.setFont(this->font);
	this->Intro3.setCharacterSize(30);
	this->Intro3.setFillColor(sf::Color::Yellow);
	this->Intro3.setPosition(0, 80);

	this->Intro.setString("You are Trapped on an Island. Horrible Creatures are Chasing you");
	this->Intro2.setString("Is this a dream ? ");
	this->Intro3.setString("You MUST survive as long as possible, There maybe someone who can help you");
}

void IntroState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/rpgFONT.ttf")) {
		std::cout << "error in font";
	}
}

void IntroState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
}

void IntroState::initButtons()
{

	this->buttons["EXIT_BTN"] = new Button(0, 550, 150, 50
		, "EXIT", &this->font, sf::Color(255, 215, 0, 255), sf::Color(255, 215, 0, 150), sf::Color(255, 215, 0, 255));
}

IntroState::IntroState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, Player* player)
	:State(window, supportedKeys, states, player)
{
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initBackGround();
	
}

IntroState::~IntroState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}

int IntroState::getState()
{
	return -1;
}

void IntroState::endState()
{
	std::cout << "\nENDING INTRO STATE";
}

void IntroState::updateInput()
{
	this->checkForQuit();
}

void IntroState::updateButtons()
{
	for (auto it : this->buttons) {
		it.second->update(this->moousePosView);
	}

	if (this->buttons["EXIT_BTN"]->isPressed()) {
		this->quit = true;
	}
}

void IntroState::update(Inventory* playerINV, unsigned* gold)
{
	this->updateMousePositions();
	this->updateInput();
	//system("cls");
	//std::cout << this->moousePosView.x << "  " << this->moousePosView.y<<"\n";
	this->updateButtons();
}

void IntroState::renderButtons(sf::RenderTarget* target)
{
	for (auto it : this->buttons) {
		it.second->render(target);
	}
}

void IntroState::render(sf::RenderTarget* target)
{

	if (!target) {
		target = this->window;
	}
	target->draw(this->background);
	this->renderButtons(target);
	target->draw(this->Intro);
	target->draw(this->Intro2);
	target->draw(this->Intro3);
}
