#pragma once
#include "State.h"
#include"Button.h"
#include"GameState.h"
class IntroState :
    public State
{
private:
    sf::Font font;
    sf::Text Intro;
    sf::Text Intro2;
    sf::Text Intro3;
    void initVariables();
    void initBackGround();
    void initFonts();
    void initKeybinds();
    void initButtons();
    std::map<std::string, Button*> buttons;

    sf::RectangleShape background;
public:
    IntroState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, Player* player);
    virtual ~IntroState();
    int getState();
    void endState();
    void updateInput();
    void updateButtons();
    void update(Inventory* playerINV, unsigned* gold);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};

