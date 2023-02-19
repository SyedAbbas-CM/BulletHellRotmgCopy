#pragma once
#include "State.h"
#include"MainMenuState.h"
#include"Button.h"
#include"InvetoryState.h"
#include"ShopState.h"
#include"MerchantState.h"
#include"Merchant.h"
#include"DeathState.h"
class GameState :
    public State
{
private:
    void initKeybinds();
    void initFonts();
    void initButtons();
    void initGUI();
    void initMerchant();
    void updateDeathGUI();
    std::map<std::string, Button*> GameButtons;
    sf::Font font;
    sf::Sprite goldIcon;
    sf::Texture goldIconTexture;
    sf::Text goldText;
    Merchant* merchant;
    sf::RectangleShape DeathRect;
    float redValue;
    float TransparencyValue;
    float playerHpPercent;
    bool shopButtondisplayed;
public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, Player* player);
    virtual ~GameState();

    void endState();
    int getState();
    void updateInput();
    void updateButtons();
    void update(Inventory* playerINV,unsigned* gold);
    void render(sf::RenderTarget* target = nullptr);
};

