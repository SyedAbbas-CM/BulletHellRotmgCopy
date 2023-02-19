#pragma once
#include "State.h"
#include"Button.h"
class MerchantState :
    public State
{
private:
    void initKeybinds();
    void initFonts();
    void initButtons();
    void initGUI();
    std::map<std::string, Button*> InventoryButtons;
    sf::Font font;

    //GUI
    sf::Texture goldIconTexture;
    sf::Text goldText;
    sf::Sprite goldIcon;
    unsigned* gold;
 

    //INVENTORY ITEMS DISPLAY
    sf::Sprite ItemIcons;
    sf::Texture itemTextures;
    sf::IntRect itemrect;

    sf::Sprite PotionIcons;
    sf::Texture PotionTextures;
    sf::IntRect Potionrect;
    //IVENTORY DISPLAY SYSTEM
    std::map<int, Button*> itemDisplayButtons;
    sf::RectangleShape displayBackground;
    std::string itemDescription;
    sf::Text itemDescriptionText;
    int itemcount;
    int itemcost;
    sf::Text itemCountText;
    sf::Text itemCostText;

    sf::RectangleShape Inventorybackground;
    Inventory* playerInv;
    bool inventoryDisplayed;
    bool inventoryinit;
    bool hoverdisplay;
    bool hoverdisplaybool;


    bool potionsDisplay;
    bool itemsDisplay;


public:

    MerchantState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, Player* player);
    virtual ~MerchantState();

    std::string returnItemName(int Id);
    void updateItemSpriteandName(int Id);
    void initdisplayBackground();
    void initItemTextures();
    void endState();
    int getState();
    void updateInput();
    void updateButtons();
    void update(Inventory* playerINV, unsigned* gold);
    void InitInventory();
    void UpdateInventory();

    void render(sf::RenderTarget* target = nullptr);
};

