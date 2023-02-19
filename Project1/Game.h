#pragma once

#include"Player.h"
#include"Bullet.h"
#include"Game.h"
#include"Gameworld.h"
#include"textDisplay.h"
#include"MainMenuState.h"
#include"EnemySpawner.h"
class Game {
private:
	//Window
	sf::RenderWindow* window;

	//Resources
	std::map<sf::String, sf::Texture*> textures;
	sf::View* View1;
	Random rand;
	sf::Time secondCounter;
	sf::Clock mainClock;
	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;
	sf::Clock dtClock;
	float dt;
	//GUI
	unsigned gold;
	//Gameworld
	Gameworld* gameWorld;
	Interactable* interactable;
	//systems
	unsigned points;
	//Player
	Player* player;
	//Enemies
	std::vector<Enemy*> enemies;
	std::vector<textDisplay*> texts;
	sf::Vector2f mousePosWindow;
	sf::Vector2f moousePosView;
	EnemySpawner* spawner;
	SpriteManager* spManager;
	//PRivate FUnctions
	void initWindow();
	void initPlayer();
	void initGameWorld();
	void initStates();
	void initKeys();
	void initView();
	void resetView();
public:
	Game();
	virtual ~Game();
	void updateDt();
	//Functions
	void updateMousePosition(float dt);

	void updatePollEvents(float dt);
	void updateInput(float dt);



	void run();
	void drawGameWorld(float dt);
	void updateGameWorld(float dt);
	void wallCollisions(float dt);


	void playerBulletUpdate(float dt);
	void enemyBulletUpdate(float dt);
	void updateEnemiesAndCombat(float dt);
	void update();
	void render();
	void endApplication();
};


