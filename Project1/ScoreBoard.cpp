#include "ScoreBoard.h"

void ScoreBoard::initVariables()
{
}

void ScoreBoard::initBackGround()
{
	this->Deathbackground.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	this->Deathbackground.setPosition(this->window->getPosition().x - (this->Deathbackground.getGlobalBounds().width / 2.5f),
		this->window->getPosition().y - (this->Deathbackground.getGlobalBounds().height / 4));
	this->Deathbackground.setFillColor(sf::Color(200, 0, 0, 155));
	this->ScoreText.setFont(this->font);
	this->ScoreText.setFillColor(sf::Color::Yellow);
	this->ScoreText.setCharacterSize(35);
	this->ScoreText.setPosition(150,0);
	this->ScoreText.setString("Previous Scores: ");



	this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	this->background.setPosition(this->window->getPosition().x - (this->background.getGlobalBounds().width / 2.5f),
		this->window->getPosition().y - (this->background.getGlobalBounds().height / 4));
	this->background.setFillColor(sf::Color(0, 0, 0, 255));


	this->deathText.setFont(this->font);
	this->deathText.setCharacterSize(30);
	this->deathText.setFillColor(sf::Color::Yellow);
	this->deathText.setPosition(this->Deathbackground.getPosition().x, this->Deathbackground.getPosition().y);

	this->deathText2.setFont(this->font);
	this->deathText2.setCharacterSize(30);
	this->deathText2.setFillColor(sf::Color::Yellow);
	this->deathText2.setPosition(this->Deathbackground.getPosition().x, this->Deathbackground.getPosition().y + 40);

	this->deathText3.setFont(this->font);
	this->deathText3.setCharacterSize(30);
	this->deathText3.setFillColor(sf::Color::Yellow);
	this->deathText3.setPosition(this->Deathbackground.getPosition().x, this->Deathbackground.getPosition().y+80);

	this->deathText4.setFont(this->font);
	this->deathText4.setCharacterSize(30);
	this->deathText4.setFillColor(sf::Color::Yellow);
	this->deathText4.setPosition(this->Deathbackground.getPosition().x, this->Deathbackground.getPosition().y+120);

	this->deathText5.setFont(this->font);
	this->deathText5.setCharacterSize(30);
	this->deathText5.setFillColor(sf::Color::Yellow);
	this->deathText5.setPosition(this->Deathbackground.getPosition().x, this->Deathbackground.getPosition().y+160);

	this->deathText6.setFont(this->font);
	this->deathText6.setCharacterSize(30);
	this->deathText6.setFillColor(sf::Color::Yellow);
	this->deathText6.setPosition(this->Deathbackground.getPosition().x, this->Deathbackground.getPosition().y+200);

	this->deathText7.setFont(this->font);
	this->deathText7.setCharacterSize(30);
	this->deathText7.setFillColor(sf::Color::Yellow);
	this->deathText7.setPosition(this->Deathbackground.getPosition().x, this->Deathbackground.getPosition().y+240);

	this->deathText8.setFont(this->font);
	this->deathText8.setCharacterSize(30);
	this->deathText8.setFillColor(sf::Color::Yellow);
	this->deathText8.setPosition(this->Deathbackground.getPosition().x, this->Deathbackground.getPosition().y+280);
}

void ScoreBoard::initFonts()
{
	if (!this->font.loadFromFile("Fonts/rpgFONT.ttf")) {
		std::cout << "error in font";
	}
}

void ScoreBoard::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
}

void ScoreBoard::initButtons()
{
	std::fstream f;
	f.open("ScoreFiles/ScoreBoard.txt", std::ios::in);

	while (!f.eof()) {
		std::getline(f, this->templine);
		ScoresWithValues.push_back(this->templine);
		for (int i = 0; i < this->templine.size(); i++) {
			if (this->templine[i] == ',') {
				break;
			}
			else {
				/*this->tempScore[i] = this->templine[i];*/
				this->tempScore.resize(i + 1);
				this->tempScore[i] = this->templine[i];
			}
		}
		std::cout << this->tempScore<<"\n";
		this->Scores.push_back(std::stoi(this->tempScore));
	}
	std::sort(this->Scores.begin(), this->Scores.end());
	int ygap = 0;
	for (int i = this->Scores.size() - 1; i >= 0; i--) {
		ygap++;
		this->buttons[std::to_string(this->Scores[i])] = new Button(450, 50 * ygap, 150, 50
			, (std::to_string(this->Scores[i])), &this->font, sf::Color(255, 215, 0, 255), sf::Color(255, 215, 0, 150), sf::Color(255, 215, 0, 255));
	}
	f.close();

	this->buttons["EXIT_BTN"] = new Button(0, 550, 150, 50
		, "EXIT", &this->font, sf::Color(255, 215, 0, 255), sf::Color(255, 215, 0, 150), sf::Color(255, 215, 0, 255));

}

void ScoreBoard::updateScoreStats()
{
	int j = 0;
	for (int i = 0; i < this->ScoresWithValues[position].size(); i++) {
		if (this->ScoresWithValues[position][i] == ',') {
			this->flag++;
			j = 0;
			continue;
		}
		if (flag == 0) {
			this->TotalScore.resize(j + 1);
			this->TotalScore[j] = ScoresWithValues[position][i];
		}
		if (flag == 1) {
			this->DamageTaken.resize(j + 1);
			this->DamageTaken[j] = ScoresWithValues[position][i];
		}
		if (flag == 2) {
			this->DamageDealt.resize(j + 1);
			this->DamageDealt[j] = ScoresWithValues[position][i];
		}
		if (flag == 3) {
			this->EnemiesKilled.resize(j + 1);
			this->EnemiesKilled[j] = ScoresWithValues[position][i];
		}
		if (flag == 4) {
			this->BossesKilled.resize(j + 1);
			this->BossesKilled[j] = ScoresWithValues[position][i];
		}
		if (flag == 5) {
			this->goldAccumulated.resize(j + 1);
			this->goldAccumulated[j] = ScoresWithValues[position][i];
		}
		if (flag == 6) {
			this->PotionsDrank.resize(j + 1);
			this->PotionsDrank[j] = ScoresWithValues[position][i];
		}
		if (flag == 7) {
			this->ItemsBought.resize(j + 1);
			this->ItemsBought[j] = ScoresWithValues[position][i];
		}
		j++;
	}
	this->deathText.setString("Total Score: "+this->TotalScore);
	this->deathText2.setString("Total Damage Taken: " + this->DamageTaken);
	this->deathText3.setString("Total Damage Dealt: " + this->DamageDealt);
	this->deathText4.setString("Total Enemies Killed: " + this->EnemiesKilled);
	this->deathText5.setString("Total Bosses Killed: " + this->BossesKilled);
	this->deathText6.setString("Total Gold Accumulated: " + this->goldAccumulated);
	this->deathText7.setString("Total Potions Drank: " + this->PotionsDrank);
	this->deathText8.setString("Total Items Bought: " + this->ItemsBought);





}

ScoreBoard::ScoreBoard(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, Player* player)
	:State(window, supportedKeys, states, player)
{
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initBackGround();
	this->flag = 0;
	this->breaker = false;
}

ScoreBoard::~ScoreBoard()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}

int ScoreBoard::getState()
{
	return 6;
}

void ScoreBoard::endState()
{
	std::cout << "\nENDING MAIN MENU STATE";
}

void ScoreBoard::updateInput()
{
	this->checkForQuit();
}

void ScoreBoard::updateButtons()
{
	for (auto it : this->buttons) {
		it.second->update(this->moousePosView);
		
	}
	
	this->position = 0;
	for (int i = this->Scores.size() - 1; i >= 0; i--) {
		if (breaker) {
			break;
		}
		if (this->buttons[std::to_string(this->Scores[i])]->isPressed()) {
			for (int k = 0; k < this->ScoresWithValues.size(); k++) {
				for (int j = 0; j < this->ScoresWithValues[k].size(); j++) {
					if (this->ScoresWithValues[k][j] == ',') {
						break;
					}
					else {
						/*this->tempScore[i] = this->templine[i];*/
						this->tempScore.resize(j + 1);
						this->tempScore[j] = this->ScoresWithValues[k][j];
					}
					if (this->tempScore == std::to_string(this->Scores[i])) {
						std::cout << this->tempScore<<"\n";
						std::cout << std::to_string(this->Scores[i]) << "\n";
						position = k;
						this->updateScoreStats();
						breaker = true;
						this->DisplayDeathBg = true;
					}
				}
				
				
			}
			
		}

	}
	if (this->buttons["EXIT_BTN"]->isPressed()) {
		this->quit = true;
	}
}

				
void ScoreBoard::update(Inventory* playerINV, unsigned* gold)
{
	this->updateMousePositions();
	this->updateInput();
	//system("cls");
	//std::cout << this->moousePosView.x << "  " << this->moousePosView.y<<"\n";
	this->updateButtons();
}

void ScoreBoard::renderButtons(sf::RenderTarget* target)
{
	for (auto it : this->buttons) {
		it.second->render(target);
	}
}

void ScoreBoard::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
	target->draw(this->background);
	this->renderButtons(target);
	target->draw(this->ScoreText);
	if (this->DisplayDeathBg) {
		target->draw(this->Deathbackground);
		target->draw(this->deathText);
		target->draw(this->deathText2);
		target->draw(this->deathText3);
		target->draw(this->deathText4);
		target->draw(this->deathText5);
		target->draw(this->deathText6);
		target->draw(this->deathText7);
		target->draw(this->deathText8);
	
	
	}
}
