#include "DeathState.h"

void DeathState::initVariables()
{
}

void DeathState::initBackGround()
{
	this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	this->background.setPosition(this->window->getPosition().x - (this->background.getGlobalBounds().width / 2.5f),
		this->window->getPosition().y - (this->background.getGlobalBounds().height / 4));
	this->background.setFillColor(sf::Color(155,0, 0, 255));
	this->Intro.setFont(this->font);
	this->Intro.setCharacterSize(30);
	this->Intro.setFillColor(sf::Color::Yellow);
	this->Intro.setPosition(80, 0);

	this->Intro2.setFont(this->font);
	this->Intro2.setCharacterSize(30);
	this->Intro2.setFillColor(sf::Color::Yellow);
	this->Intro2.setPosition(60, 40);

	this->Intro3.setFont(this->font);
	this->Intro3.setCharacterSize(30);
	this->Intro3.setFillColor(sf::Color::Yellow);
	this->Intro3.setPosition(70, 80);

	this->Intro.setString("Alas , the Dream has ended!");
	this->Intro2.setString("Worry not! You safely return to your awakened state ");
	this->Intro3.setString("..but did you show enough Courage ?");
}

void DeathState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/rpgFONT.ttf")) {
		std::cout << "error in font";
	}
}

void DeathState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
}

void DeathState::initButtons()
{
	this->buttons["EXIT_BTN"] = new Button(0, 550, 150, 50
		, "EXIT", &this->font, sf::Color(75, 75, 75, 255), sf::Color(75, 75, 75, 255), sf::Color(75, 75, 75, 255));
}

void DeathState::writeToFile()
{
	totalScore = (this->player->getEnemiesKIlled()*2) + (this->player->getBossesKIlled() *3) + (this->player->getgoldAccumulated()/5) +
		(this->player->getPotionsDrank() * 2) + (this->player->getItemsBought() * 3);
	std::fstream f;
	f.open("ScoreFiles/ScoreBoard.txt", std::ios::app);
	f <<"\n"<<this->totalScore <<","<<this->player->getDamageTaken() << "," << this->player->getDamageDealth() << "," << this->player->getEnemiesKIlled() << "," << this->player->getBossesKIlled() <<
		"," << this->player->getgoldAccumulated() << "," << this->player->getPotionsDrank() << "," << this->player->getItemsBought() ;
	f.close();

	this->ScoreText.setFont(this->font);
	this->ScoreText.setCharacterSize(30);
	this->ScoreText.setFillColor(sf::Color::Yellow);
	this->ScoreText.setPosition(0, 160);
	this->ScoreText.setString("Your Total Score is: ");

	this->Score.setFont(this->font);
	this->Score.setCharacterSize(30);
	this->Score.setFillColor(sf::Color::Yellow);
	this->Score.setPosition(200, 160);
	this->Score.setString(std::to_string(this->totalScore));
	
}

DeathState::DeathState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, Player* player)
	:State(window, supportedKeys, states, player)
{
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initBackGround();
	this->writeToFile();
}

DeathState::~DeathState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}

int DeathState::getState()
{
	return 5;
}

void DeathState::endState()
{
	std::cout << "\nENDING Death STATE";
}

void DeathState::updateInput()
{
	this->checkForQuit();
}

void DeathState::updateButtons()
{
	for (auto it : this->buttons) {
		it.second->update(this->moousePosView);
	}

	if (this->buttons["EXIT_BTN"]->isPressed()) {
		
		this->window->close();
		
	}
}

void DeathState::update(Inventory* playerINV, unsigned* gold)
{
	this->updateMousePositions();
	this->updateInput();
	//system("cls");
	//std::cout << this->moousePosView.x << "  " << this->moousePosView.y<<"\n";
	this->updateButtons();
}

void DeathState::renderButtons(sf::RenderTarget* target)
{
	for (auto it : this->buttons) {
		it.second->render(target);
	}
}

void DeathState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
	target->draw(this->background);
	this->renderButtons(target);
	target->draw(this->Intro);
	target->draw(this->Intro2);
	target->draw(this->Intro3);
	target->draw(this->ScoreText);
	target->draw(this->Score);

}
