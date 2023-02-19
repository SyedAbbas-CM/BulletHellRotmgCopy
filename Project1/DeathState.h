#pragma once
#include "State.h"
#include"Button.h"
#include<fstream>
#include<iostream>
class DeathState :
    public State
{
private:
    sf::Font font;
    sf::Texture backgroundtexture;
    sf::Text Intro;
    sf::Text Intro2;
    sf::Text Intro3;
    sf::Text ScoreText;
    sf::Text Score;
    void initVariables();
    void initBackGround();
    void initFonts();
    void initKeybinds();
    void initButtons();
    void writeToFile();
    std::map<std::string, Button*> buttons;
    bool nameEntered;
    sf::RectangleShape background;
    int totalScore;
public:
    DeathState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, Player* player);
    virtual ~DeathState();
    int getState();
    void endState();
    void updateInput();
    void updateButtons();
    void update(Inventory* playerINV, unsigned* gold);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};

