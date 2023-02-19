#include "Game.h"
//Private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800,600),"Bullet Hell", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{
	this->player = new Player();
	this->gold = 0;
}
void Game::initGameWorld()
{
	this->gameWorld = new Gameworld();
	Enemy::setSpriteManager(spManager->getInstance());
}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys,&this->states,this->player));
}

void Game::initKeys()
{
	this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
	this->supportedKeys["Q"] = sf::Keyboard::Key::Q;
	this->supportedKeys["B"] = sf::Keyboard::Key::B;
	this->supportedKeys["A"] = sf::Keyboard::Key::A;
	this->supportedKeys["D"] = sf::Keyboard::Key::D;
	this->supportedKeys["W"] = sf::Keyboard::Key::W;
	this->supportedKeys["S"] = sf::Keyboard::Key::S;
}

void Game::initView()
{
	this->View1 = new sf::View(sf::Vector2f(400.f, 300.f), sf::Vector2f(1400.f, 1000.f));
	View1->setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	window->setView(*View1);
}

void Game::resetView()
{
	this->window->setView(this->window->getDefaultView());
}

//Con/Des
Game::Game()
{
	this->initWindow();
	this->initKeys();
	this->initPlayer();
	this->initStates();
	this->initGameWorld();
	this->spawner = new EnemySpawner(&this->enemies,this->spManager);
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	//Remove the textures to avoid mem leaks
	//For each i, which is a string, delete the second part which is a texture 
	for (auto &i : this->textures) {
		delete i.second;
	}
	// Delete Bullets 
	for (auto* i : this->enemies) {
		delete i;
	}
	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}
void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}
void Game::updateMousePosition(float dt)
{
	this->player->update(this->window);
	this->mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(*this->window));
}

void Game::updatePollEvents(float dt)
{
	sf::Event e;
	while (this->window->pollEvent(e)) {
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
	}

}
void Game::updateInput(float dt)
{
	View1->setCenter(player->getPos());
	window->setView(*View1);
	//Move the player
	this->player->PlayerMove();
	//Let Player Attack
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack()) {
			this->player->attack(this->mousePosWindow);
	}
}

//Functions
void Game::run()
{
	while (this->window->isOpen()) 
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
void Game::updateGameWorld(float dt)
{
	
		for (int j = 0; j < gameWorld->passObjs[1].size(); j++) {
			if (gameWorld->passObjs[1][j]->isInteractable()) {
				interactable = dynamic_cast<Interactable*>(gameWorld->passObjs[1][j]);
				if (interactable->interaction(this->player->getbounds())) {
					if (interactable->getitemID() == 1) {
						this->gold += 35;
						this->player->incrementgoldAccumulated(35);
					}
					if (interactable->getitemID() == 2) {
						this->gold += 55;
						this->player->incrementgoldAccumulated(55);
					}
					if (interactable->getitemID() == 100) {
						this->player->playerINV.itemList[0][1] ++;
					}
					if (interactable->getitemID() == 101) {
						this->player->playerINV.itemList[1][1] ++;
					}
					if (interactable->getitemID() == 102) {
						this->player->playerINV.itemList[2][1] ++;
					}
					if (interactable->getitemID() == 103) {
							this->player->playerINV.itemList[3][1] ++;
					}
					if (interactable->getitemID() == 104) {
						this->player->playerINV.itemList[4][1] ++;
					}
					if (interactable->getitemID() == 105) {
						this->player->playerINV.itemList[5][1] ++;
					}
					if (interactable->getitemID() == 106) {
						this->player->playerINV.itemList[6][1] ++;
					}
					delete gameWorld->passObjs[1][j];
					gameWorld->passObjs[1].erase(gameWorld->passObjs[1].begin() + j);
					
				}
			}
		}
		this->gameWorld->getGridLoc(this->player->getbounds());
	
}

void Game::wallCollisions(float dt)
{
	for (int i = 0; i < gameWorld->NonPassObjs.size(); i++) {
		for (int j = 0; j < gameWorld->NonPassObjs[i].size(); j++) {
			if (gameWorld->NonPassObjs[i][j]->getbounds().intersects(this->player->getbounds())) {
				if (gameWorld->NonPassObjs[i][j]->nonPassableCollision(this->player->getbounds()) == 1) {
					player->setPosition(this->player->getbounds().left, gameWorld->NonPassObjs[i][j]->getbounds().top - this->player->getbounds().height);
				}
				else if (gameWorld->NonPassObjs[i][j]->nonPassableCollision(this->player->getbounds()) == 2) {
					player->setPosition(this->player->getbounds().left, gameWorld->NonPassObjs[i][j]->getbounds().top + gameWorld->NonPassObjs[i][j]->getbounds().height);
				}
				if (gameWorld->NonPassObjs[i][j]->nonPassableCollision(this->player->getbounds()) == 3) {
					player->setPosition(gameWorld->NonPassObjs[i][j]->getbounds().left - this->player->getbounds().width, this->player->getbounds().top);
				}
				else if (gameWorld->NonPassObjs[i][j]->nonPassableCollision(this->player->getbounds()) == 4) {
					player->setPosition(gameWorld->NonPassObjs[i][j]->getbounds().left + gameWorld->NonPassObjs[i][j]->getbounds().width, this->player->getbounds().top);
				}
				}
		for (size_t k = 0; k < this->enemies.size(); k++) {
			if (gameWorld->NonPassObjs[i][j]->getbounds().intersects(this->enemies[k]->getbounds())) {
			if (gameWorld->NonPassObjs[i][j]->nonPassableCollision(this->enemies[k]->getbounds()) == 1) {
				this->enemies[k]->setPosition(this->enemies[k]->getbounds().left, gameWorld->NonPassObjs[i][j]->getbounds().top - this->enemies[k]->getbounds().height);
			}
			else if (gameWorld->NonPassObjs[i][j]->nonPassableCollision(this->enemies[k]->getbounds()) == 2) {
				this->enemies[k]->setPosition(this->enemies[k]->getbounds().left, gameWorld->NonPassObjs[i][j]->getbounds().top + gameWorld->NonPassObjs[i][j]->getbounds().height);
			}
			if (gameWorld->NonPassObjs[i][j]->nonPassableCollision(this->enemies[k]->getbounds()) == 3) {
				this->enemies[k]->setPosition(gameWorld->NonPassObjs[i][j]->getbounds().left - this->enemies[k]->getbounds().width, this->enemies[k]->getbounds().top);
			}
			else if (gameWorld->NonPassObjs[i][j]->nonPassableCollision(this->enemies[k]->getbounds()) == 4) {
				this->enemies[k]->setPosition(gameWorld->NonPassObjs[i][j]->getbounds().left + gameWorld->NonPassObjs[i][j]->getbounds().width, this->enemies[k]->getbounds().top);
			}
			}
		}
		bool EbulletRemoved = false;
		for (size_t k = 0; k < Enemy::enemybullets.size() && !EbulletRemoved; k++) {
			if (gameWorld->NonPassObjs[i][j]->getbounds().intersects(Enemy::enemybullets[k].getBounds())) {
				EbulletRemoved = true;
			}
			if (EbulletRemoved) {
				Enemy::enemybullets.remove(k);

			}
		}
		bool PbulletRemoved = false;
		for (size_t k = 0; k < this->player->getBulletsSize() && !PbulletRemoved; k++) {
			if (gameWorld->NonPassObjs[i][j]->getbounds().intersects(this->player->getBullet(k).getBounds())) {
				PbulletRemoved = true;
			}
			if (PbulletRemoved) {
				this->player->removeBullet(k);

			}
		}
	}
	}
}

void Game::playerBulletUpdate(float dt)
{
	bool enemyRemoved = false;
	bool bulletRemoved = false;
	for (size_t k = 0; k < this->player->getBulletsSize() && !bulletRemoved; k++) {
		this->player->getBullet(k).update();
		for (size_t j = 0; j < this->enemies.size() && !enemyRemoved; j++) {
			if (this->player->getBullet(k).getBounds().intersects(this->enemies[j]->getbounds())) {

				enemies[j]->updatehp(this->player->getBullet(k).getdamage());

				this->player->incrementDamageDealth(this->player->getBullet(k).getdamage());

				texts.push_back(new textDisplay(this->enemies[j]->getPos().x+this->enemies[j]->getbounds().width/2, this->enemies[j]->getbounds().top-25, this->player->getBullet(k).getdamage()));
				
				if (enemies[j]->gethp() == 0) {
					this->gameWorld->passObjs[1].push_back(new Interactable(this->enemies[j]->getPos().x, this->enemies[j]->getPos().y, this->enemies[j]->gettype()));
					if (enemies[j]->gettype() > 1) {
						this->player->incrementBossesKilled(1);
					}
					delete enemies[j];
					this->enemies.erase(this->enemies.begin() + j);
					enemyRemoved = true;
					this->player->incrementEnemiesKIlled(1);
				}
				if(!this->player->getBullet(k).piercing)
				bulletRemoved = true;
			}
		}
		if ((sqrt((pow(static_cast<int>(this->player->getBullet(k).getposition().x - this->player->getBullet(k).getOrigin().x), 2) +
			(pow(static_cast<int>(this->player->getBullet(k).getposition().y - this->player->getBullet(k).getOrigin().y), 2)))) > this->player->getrange())) {
			bulletRemoved = true;
		}
		if (bulletRemoved) {
			this->player->removeBullet(k);
			bulletRemoved = false;
		}
	}
}

void Game::enemyBulletUpdate(float dt)
{
	bool bulletRemoved = false;
	for (size_t k = 0; k < Enemy::enemybullets.size() && !bulletRemoved; k++) {
		Enemy::enemybullets[k].update();
		if (Enemy::enemybullets[k].getBounds().intersects(this->player->getbounds())) {
			this->player->updateHp(Enemy::enemybullets[k].getdamage());
			this->player->incrementDamageTaken(Enemy::enemybullets[k].getdamage());
			texts.push_back(new textDisplay(this->player->getPos().x, this->player->getbounds().top-25,Enemy::enemybullets[k].getdamage()- this->player->getDefense()));
			bulletRemoved = true;
		}
		if ((sqrt((pow(static_cast<int>(Enemy::enemybullets[k].getposition().x - Enemy::enemybullets[k].getOrigin().x), 2) +
			pow(static_cast<int>(Enemy::enemybullets[k].getposition().y - Enemy::enemybullets[k].getOrigin().y), 2)))) > Enemy::enemybullets[k].getrange()) {
			bulletRemoved = true;
		}
		if (bulletRemoved) {
			Enemy::enemybullets.remove(k);
		}
	}

}

void Game::updateEnemiesAndCombat(float dt)
{	
	this->spawner->spawnEnemies();
	for (int i =0; i < this->enemies.size(); ++i)
	{
		this->enemies[i]->update((rand.generateRandom(800, 0) - 800), rand.generateRandom(800, 0) - 800, this->player->getPos(), this->window);
		if (this->enemies[i]->canAttack() && this->enemies[i]->inVision())
			this->enemies[i]->attack();
	}	
}

void Game::update()
{
	if (!this->states.empty()) {
		if (this->states.top()->getState() == 1) {
			this->initView();
			this->updateGameWorld(this->dt);
			this->spawner->incrementTimers();
			for (size_t i = 0; i < texts.size(); i++) {
				texts[i]->update();
				if (texts[i]->textDeleted()) {
					delete texts[i];
					this->texts.erase(this->texts.begin() + i);
				}
			}
			this->secondCounter = this->mainClock.getElapsedTime();
			this->updatePollEvents(this->dt);
			this->updateInput(this->dt);
			//this->wallCollisions(this->dt);
			this->updateMousePosition(this->dt);

			this->playerBulletUpdate(this->dt);
			this->enemyBulletUpdate(this->dt);
			this->updateEnemiesAndCombat(this->dt);

		}
		else {
			this->resetView();
	}
	
	}
	if (!this->states.empty()) {
		this->states.top()->update(&this->player->playerINV,&this->gold);
		if (this->states.top()->getQuit())
		{
			std::cout << "\nENDING STATE:" << this->states.top()->getState()<<"\n";
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else {
		this->endApplication();
		this->window->close();
	}
}

void Game::render()
{
	//Erase the old frame
	this->window->clear();

	//Draw the new stuff
	if (!this->states.empty()) {
		if (this->states.top()->getState() == 1) {
			this->gameWorld->drawGameWorld(this->window);
			for (auto* enemy : this->enemies) {
				if (enemy->inVision()) {
					enemy->render(this->window,this->dt);
				}
			}
			for (size_t i = 0; i < this->player->getBulletsSize(); i++) {
				this->player->getBullet(i).render(this->window);
			}
			for (size_t i = 0; i < Enemy::enemybullets.size(); i++) {
				Enemy::enemybullets[i].render(this->window);
			}
			this->player->render(*this->window);
			for (size_t i = 0; i < texts.size(); i++) {
				texts[i]->render(this->window);
			}
		}
	}
	if (!this->states.empty())
		this->states.top()->render(this->window);
	this->window->display();
}
void Game::endApplication()
{
	std::cout << "\nended application";
}
