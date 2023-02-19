#include "MainMenuState.h"

void MainMenuState::initVariables()
{
}

void MainMenuState::initBackGround()
{
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/rpgFONT.ttf")) {
		std::cout << "error in font";
	}
}

void MainMenuState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE_BTN"] = new Button(325, 200, 150, 50
		, "PLAY", &this->font, sf::Color(255, 215, 0, 255), sf::Color(255, 215, 0, 150), sf::Color(255, 215, 0, 255));

	this->buttons["EXIT_BTN"] = new Button(325, 250, 150, 50
		, "EXIT", &this->font, sf::Color(255, 215, 0, 255), sf::Color(255, 215, 0, 150), sf::Color(255, 215, 0, 255));

	this->buttons["INTRO_BTN"] = new Button(325, 150, 150, 50
		, "INTRO", &this->font, sf::Color(255, 215, 0, 255), sf::Color(255, 215, 0, 150), sf::Color(255, 215, 0, 255));
	this->buttons["SCORES_BTN"] = new Button(325, 100, 150, 50
		, "SCORES", &this->font, sf::Color(255, 215, 0, 255), sf::Color(255, 215, 0, 150), sf::Color(255, 215, 0, 255));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, Player* player)
	:State(window, supportedKeys,states,player)
{
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	
	this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	this->background.setPosition(this->window->getPosition().x - (this->background.getGlobalBounds().width / 2.5f),
		this->window->getPosition().y - (this->background.getGlobalBounds().height / 4));
	this->backgroundtexture.loadFromFile("Textures/TitleScreen.png");
	this->background.setTexture(&this->backgroundtexture);
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}

int MainMenuState::getState()
{
	return 0;
}

void MainMenuState::endState()
{
	std::cout << "\nENDING MAIN MENU STATE";
}

void MainMenuState::updateInput()
{
	this->checkForQuit();
}

void MainMenuState::updateButtons()
{
	for (auto it : this->buttons) {
		it.second->update(this->moousePosView);
	}
	if (this->buttons["GAME_STATE_BTN"]->isPressed()) {
		this->states->push(new GameState(this->window,this->supportedKeys,this->states,this->player));
	}
	if (this->buttons["EXIT_BTN"]->isPressed()) {
		this->quit = true;
	}
	if (this->buttons["INTRO_BTN"]->isPressed()) {
		this->states->push(new IntroState(this->window, this->supportedKeys, this->states, this->player));
	}
	if (this->buttons["SCORES_BTN"]->isPressed()) {
		this->states->push(new ScoreBoard(this->window, this->supportedKeys, this->states, this->player));
	}
}

void MainMenuState::update(Inventory* playerINV,unsigned* gold)
{
	this->updateMousePositions();
	this->updateInput();
	//system("cls");
	//std::cout << this->moousePosView.x << "  " << this->moousePosView.y<<"\n";
	this->updateButtons();
	
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto it : this->buttons) {
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
	target->draw(this->background);
	this->renderButtons(target);

}
