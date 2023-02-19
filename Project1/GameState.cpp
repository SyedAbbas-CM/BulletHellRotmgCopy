#include "GameState.h"

void GameState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["INVENTORY"] = this->supportedKeys->at("B");
}

void GameState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/rpgFONT.ttf")) {
		std::cout << "error in font";
	}
}

void GameState::initButtons()
{
	this->GameButtons["QUIT_BTN"] = new Button(this->window->getPosition().x, this->window->getPosition().y, 120, 40
		, "PAUSE", &this->font, sf::Color(200, 10,10, 255), sf::Color(255, 0, 0, 150), sf::Color(255, 10, 10, 255));

	this->GameButtons["SHOP_BTN"] = new Button(this->window->getPosition().x+25, this->window->getPosition().y+25, 120, 40
		, "SHOP", &this->font, sf::Color(200, 10, 10, 255), sf::Color(255, 0, 0, 150), sf::Color(255, 10, 10, 255));

}
void GameState::initGUI()
{
	this->goldIconTexture.loadFromFile("Textures/goldIcon.png");
	this->goldIcon.setTexture(this->goldIconTexture);
	this->goldIcon.setPosition(this->window->getPosition().x, this->window->getPosition().y);
	this->goldIcon.setScale(4.f,4.f);
	this->goldText.setFont(this->font);
	this->goldText.setFillColor(sf::Color::Yellow);
	this->goldText.setString("0");
	this->redValue = 0;
	this->TransparencyValue = 0;
	this->DeathRect.setSize(sf::Vector2f(1000,1000));
	this->DeathRect.setPosition(this->window->getPosition().x, this->window->getPosition().y);
	this->DeathRect.setFillColor(sf::Color(redValue,0,0,TransparencyValue));
}
void GameState::initMerchant()
{
	this->merchant = new Merchant(1000,1000);
}
void GameState::updateDeathGUI()
{
	this->playerHpPercent = (this->player->getHp() / this->player->getHpMax()) * 100;
	if (this->player->getHp() >= this->player->getHpMax()) {
		this->redValue = 0;
		this->TransparencyValue = 0;
	}
	if (this->playerHpPercent < 60) {
		this->redValue = (this->player->getHpMax() - this->player->getHp());
		this->TransparencyValue = (this->player->getHpMax() - this->player->getHp());
	}
	this->DeathRect.setFillColor(sf::Color(redValue, 0, 0, TransparencyValue));
}
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, Player* player)
	:State(window,supportedKeys,states,player)
{
	this->shopButtondisplayed = false;
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initGUI();
	this->initMerchant();
}

GameState::~GameState()
{
	auto it = this->GameButtons.begin();
	for (it = this->GameButtons.begin(); it != this->GameButtons.end(); ++it) {
		delete it->second;
	}
}



void GameState::endState()
{
	std::cout << "ending gamestate\n";
}

int GameState::getState()
{
	return 1;
}

void GameState::updateInput()
{
	this->checkForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("INVENTORY")))) {
		std::cout << "Opening Inventory";
		this->states->push(new InvetoryState(this->window, this->supportedKeys, this->states,this->player));
	}
}

void GameState::updateButtons()
{
	for (auto it : this->GameButtons) {
		it.second->update(this->moousePosView);
		if (it.first == "QUIT_BTN") {
			it.second->shape.setPosition(this->window->getView().getCenter().x - this->window->getView().getSize().x / 2, this->window->getView().getCenter().y - this->window->getView().getSize().y / 2);
		}
		if (it.first == "SHOP_BTN") {
			it.second->shape.setPosition(this->window->getView().getCenter().x + (this->window->getView().getSize().x / 3)+20, this->window->getView().getCenter().y + (this->window->getView().getSize().y / 3)+60);
		}

	}

	if (this->GameButtons["QUIT_BTN"]->isPressed()) {

		this->quit = true;
	}
	if (shopButtondisplayed) {
		if (this->GameButtons["SHOP_BTN"]->isPressed()) {
			this->states->push(new MerchantState(this->window, this->supportedKeys, this->states, this->player));
			
		}
	}
}


void GameState::update(Inventory* playerINV,unsigned* gold)
{
	this->updateDeathGUI();
	this->DeathRect.setPosition(this->window->getView().getCenter().x - this->window->getView().getSize().x / 2, this->window->getView().getCenter().y - this->window->getView().getSize().y / 2);
	this->updateMousePositions();
	this->updateInput();
	this->updateButtons();
	this->goldIcon.setPosition(this->window->getView().getCenter().x + this->window->getView().getSize().x / 3,
		
	this->window->getView().getCenter().y - this->window->getView().getSize().y / 2);
	this->goldText.setPosition(this->window->getView().getCenter().x + this->window->getView().getSize().x / 2.5, 
		
	this->window->getView().getCenter().y - this->window->getView().getSize().y / 2);
	this->goldText.setString(std::to_string(*gold));

	if (this->merchant->interaction(this->player->getbounds())) {
		this->shopButtondisplayed = true;
	}
	else {
		this->shopButtondisplayed = false;
	}

	if (this->player->getHp() == 0) {
		this->states->push(new DeathState(this->window, this->supportedKeys, this->states, this->player));
	}



}

void GameState::render(sf::RenderTarget* target)
{
	for (auto it : this->GameButtons) {
		if (it.first == "SHOP_BTN") {
			if (shopButtondisplayed) {
				it.second->render(target);
			}
		}
		else {
			it.second->render(target);
		}
		
	}
	target->draw(this->goldIcon);
	target->draw(this->goldText);
	this->merchant->render(*this->window);
	target->draw(this->DeathRect);
}
