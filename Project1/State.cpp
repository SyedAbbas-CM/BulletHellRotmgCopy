#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, Player* player)
{
	this->window = window;
	this->supportedKeys = supportedKeys;
	this->states = states;
	this->quit = false;
	this->quitPressed = false;
	this->paused = false;
	this->player = player;
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::checkForQuit() {


	if (!quitPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))) {
			this->quitPressed = true;
		}
		
	}
	if (this->quitPressed) {
		this->quit = true;
	}
}



void State::updateMousePositions()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->moousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
