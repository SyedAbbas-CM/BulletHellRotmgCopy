#pragma once
#include "State.h"
#include"Button.h"
#include<fstream>
class ScoreBoard :
    public State
{
    sf::Font font;
    void initVariables();
    void initBackGround();
    void initFonts();
    void initKeybinds();
    void initButtons();
    void updateScoreStats();
    std::map<std::string, Button*> buttons;
    sf::RectangleShape background;
    sf::Text ScoreText;
    std::string templine;
    std::string tempScore;
    std::vector<int> Scores;
    std::vector<std::string> ScoresWithValues;



    sf::RectangleShape Deathbackground;
    sf::Text deathText;
    sf::Text deathText2;
    sf::Text deathText3;
    sf::Text deathText4;
    sf::Text deathText5;
    sf::Text deathText6;
    sf::Text deathText7;
    sf::Text deathText8;
    int flag;
    std::string TotalScore;
    std::string DamageTaken;
    std::string DamageDealt;
    std::string EnemiesKilled;
    std::string BossesKilled;
    std::string goldAccumulated;
    std::string ItemsBought;
    std::string PotionsDrank;
    int position;
    bool breaker;
    bool DisplayDeathBg;

public:
    ScoreBoard(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, Player* player);
    virtual ~ScoreBoard();
    int getState();
    void endState();
    void updateInput();
    void updateButtons();
    void update(Inventory* playerINV, unsigned* gold);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};

