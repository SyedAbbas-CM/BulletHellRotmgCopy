#pragma once
#include<map>
#include<stack>
#include<vector>
#include"Random.h"
#include"Inventory.h"
#include"Player.h"
class State
{
private:

protected:
	sf::Vector2i mousePosWindow;
	sf::Vector2f moousePosView;
	sf::Vector2i mousePosScreen;
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	std::stack<State*>* states;
	Player* player;
	bool quit;
	bool paused;
	bool quitPressed;
	virtual void initKeybinds() = 0;
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states,Player* player);
	~State();
	const bool& getQuit() const;
	virtual void checkForQuit();
	virtual void endState() = 0;
	virtual void updateMousePositions();
	virtual int getState() = 0;
	virtual void updateInput() = 0;
	virtual void update(Inventory* playerINV = NULL, unsigned* gold = 0) = 0;
	virtual void render(sf::RenderTarget* target = nullptr ) = 0;
};

