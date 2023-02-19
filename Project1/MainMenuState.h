#pragma once
#include "State.h"
#include"GameState.h"
#include"IntroState.h"
#include"Button.h"
#include"ScoreBoard.h"
class MainMenuState :
    public State
{
private:
    sf::Font font;
    sf::Texture backgroundtexture;
    void initVariables();
    void initBackGround();
    void initFonts();
    void initKeybinds();
    void initButtons();
    std::map<std::string, Button*> buttons;

    sf::RectangleShape background;
public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, Player* player);
    virtual ~MainMenuState();
    int getState();
    void endState();
    void updateInput();
    void updateButtons();
    void update(Inventory* playerINV,unsigned* gold);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};

