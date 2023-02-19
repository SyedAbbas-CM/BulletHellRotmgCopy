#include "MerchantState.h"

void MerchantState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["INVENTORY"] = this->supportedKeys->at("B");
}

void MerchantState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/rpgFONT.ttf")) {
		std::cout << "error in font";

	}
}

void MerchantState::initButtons()
{
	this->InventoryButtons["BACK_BTN"] = new Button(this->window->getView().getCenter().x - this->window->getView().getSize().x / 2,
		this->window->getView().getCenter().y - (this->window->getView().getSize().y / 2), 120, 40
		, "Back", &this->font, sf::Color(255, 215, 0, 255), sf::Color(255, 215, 0, 150), sf::Color(255, 215, 0, 255));
}

void MerchantState::initGUI()
{
	this->Inventorybackground.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	this->Inventorybackground.setPosition(this->window->getPosition().x - (this->Inventorybackground.getGlobalBounds().width / 2.5f),
		this->window->getPosition().y - (this->Inventorybackground.getGlobalBounds().height / 4));
	this->Inventorybackground.setFillColor(sf::Color::Black);
	this->itemrect = sf::IntRect(0, 0, 40, 40);
	this->Potionrect = sf::IntRect(0, 0, 40, 40);

	this->goldIconTexture.loadFromFile("Textures/goldIcon.png");
	this->goldIcon.setTexture(this->goldIconTexture);
	this->goldIcon.setPosition(this->window->getPosition().x, this->window->getPosition().y);
	this->goldIcon.setScale(4.f, 4.f);
	this->goldText.setFont(this->font);
	this->goldText.setFillColor(sf::Color::Yellow);
	this->goldText.setString("0");
}

MerchantState::MerchantState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, Player* player)
	:State(window, supportedKeys, states, player)
{
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initGUI();
	this->initItemTextures();
	this->initdisplayBackground();
	this->inventoryDisplayed = true;
	this->inventoryinit = false;
	this->hoverdisplay = false;
	this->potionsDisplay = false;
	this->itemsDisplay = false;
}

MerchantState::~MerchantState()
{
	auto it = this->InventoryButtons.begin();
	for (it = this->InventoryButtons.begin(); it != this->InventoryButtons.end(); ++it) {
		delete it->second;
	}
}

std::string MerchantState::returnItemName(int Id)
{
	if (Id == 100) {
		return "Old Sword";
	}
	else if (Id == 101) {
		return "Basic Sword";
	}
	else if (Id == 102) {
		return "Mighty Sword";
	}
	else if (Id == 103) {
		return "Long Sword";
	}
	else if (Id == 104) {
		return "Great Sword";
	}
	else if (Id == 105) {
		return "Fire Sword";
	}
	else if (Id == 106) {
		return "Heroic Sword";
	}
	else if (Id == 107) {
		return "Golden Sword";
	}
	else if (Id == 108) {
		return "Dark Sword";
	}
	else if (Id == 109) {
		return "Ancient Golden Sword";
	}
	else if (Id == 200) {
		return "Potion of Attack";
	}
	else if (Id == 201) {
		return "Potion of Vitality";
	}
	else if (Id == 202) {
		return "Potion of Dexterity";
	}
	else if (Id == 203) {
		return "Potion of Speed";
	}
	else if (Id == 204) {
		return "Potion of Defense";
	}
	else if (Id == 205) {
		return "Potion of Life";
	}
	else
	{
		return " ";
	}
}

void MerchantState::updateItemSpriteandName(int Id)
{
	if (Id == 100) {
		this->itemrect.left = 0 * 40;
		itemcount = this->playerInv->itemList[0][1];
		itemDescription = "An old rusty sword. It is almost useless";
		this->itemsDisplay = true;
		this->potionsDisplay = false;
	}
	else if (Id == 101) {
		this->itemrect.left = 1 * 40;
		itemcount = this->playerInv->itemList[1][1];
		itemDescription = "A fine sword that is mastered by all warriors";
		this->itemsDisplay = true;
		this->potionsDisplay = false;
	}
	else if (Id == 102) {
		this->itemrect.left = 2 * 40;
		itemcount = this->playerInv->itemList[2][1];
		itemDescription = "A Powerful sword wielded by elite warriors";
		this->itemsDisplay = true;
		this->potionsDisplay = false;
	}
	else if (Id == 103) {
		this->itemrect.left = 3 * 40;
		itemcount = this->playerInv->itemList[3][1];
		itemcost = 250;
		itemDescription = "The Standard Weapon of a Skilled Knight";
		this->itemsDisplay = true;
		this->potionsDisplay = false;
	}
	else if (Id == 104) {
		this->itemrect.left = 4 * 40;
		itemcount = this->playerInv->itemList[4][1];
		itemcost = 500;
		itemDescription = "A Mighty GreatSword";
	}
	else if (Id == 105) {
		this->itemrect.left = 5 * 40;
		itemcount = this->playerInv->itemList[5][1];
		itemcost = 750;
		itemDescription = "A Sword that burns with an unholy flame";
		this->itemsDisplay = true;
		this->potionsDisplay = false;
	}
	else if (Id == 106) {
		this->itemrect.left = 6 * 40;
		itemcount = this->playerInv->itemList[6][1];
		itemcost = 1500;
		itemDescription = "Enchanted Runes Decorate this Sword";
		this->itemsDisplay = true;
		this->potionsDisplay = false;
	}
	else if (Id == 107) {
		this->itemrect.left = 7 * 40;
		itemcount = this->playerInv->itemList[7][1];
		itemDescription = "A Great Lord's Sword";
		this->itemsDisplay = true;
		this->potionsDisplay = false;
	}
	else if (Id == 108) {
		this->itemrect.left = 8 * 40;
		itemcount = this->playerInv->itemList[8][1];
		itemDescription = "An Evil Weapon that deals devastating damage";
		this->itemsDisplay = true;
		this->potionsDisplay = false;
	}
	else if (Id == 109) {
		this->Potionrect.left = 9 * 40;
		itemcount = 0;
		itemDescription = "A legendary knight of old once wielded this blade";
		this->itemsDisplay = true;
		this->potionsDisplay = false;
	}
	else if (Id == 200) {
		this->Potionrect.left = 0 * 40;
		itemcount = 0;
		itemcost = 100;
		itemDescription = "Increases Attack Damage";
		this->itemsDisplay = false;
		this->potionsDisplay = true;
	}
	else if (Id == 201) {
		this->Potionrect.left = 1 * 40;
		itemcount = 0;
		itemcost = 100;
		itemDescription = "Increases Health Regeneration";
		this->itemsDisplay = false;
		this->potionsDisplay = true;
	}
	else if (Id == 202) {
		this->Potionrect.left = 2 * 40;
		itemcount = 0;
		itemcost = 100;
		itemDescription = "Increases Attack Speed";
		this->itemsDisplay = false;
		this->potionsDisplay = true;
	}
	else if (Id == 203) {
		this->Potionrect.left = 3 * 40;
		itemcount = 0;
		itemcost = 100;
		itemDescription = "Increases Movement Speed";
		this->itemsDisplay = false;
		this->potionsDisplay = true;
	}
	else if (Id == 204) {
	this->Potionrect.left = 4 * 40;
	itemcount = 0;
	itemcost = 100;
	itemDescription = "Increases Defense";
	this->itemsDisplay = false;
	this->potionsDisplay = true;
	}
	else if (Id == 205) {
	this->Potionrect.left = 5 * 40;
	itemcount = 0;
	itemcost = 200;
	itemDescription = "Increases Maximum Health Points";
	this->itemsDisplay = false;
	this->potionsDisplay = true;
	}

	this->ItemIcons.setTextureRect(this->itemrect);
	this->PotionIcons.setTextureRect(this->Potionrect);
}

void MerchantState::initdisplayBackground()
{
	this->displayBackground.setSize(sf::Vector2f(500, 100));
	this->displayBackground.setPosition(this->window->getPosition().x - (this->Inventorybackground.getGlobalBounds().width / 2.5f),
		this->window->getPosition().y - (this->Inventorybackground.getGlobalBounds().height / 4));
	this->displayBackground.setFillColor(sf::Color(75, 75, 75, 255));
	this->ItemIcons.setPosition(this->displayBackground.getPosition().x, this->displayBackground.getPosition().y);
	this->PotionIcons.setPosition(this->displayBackground.getPosition().x, this->displayBackground.getPosition().y);
	this->itemDescriptionText.setFont(this->font);
	this->itemDescriptionText.setString(itemDescription);
	this->itemDescriptionText.setFillColor(sf::Color::White);
	this->itemDescriptionText.setPosition(
		this->displayBackground.getPosition().x + (this->displayBackground.getGlobalBounds().width / 2.f) / 2.f,
		this->displayBackground.getPosition().y + (this->displayBackground.getGlobalBounds().height / 2.f) / 2.f);
	this->itemCountText.setFont(this->font);
	this->itemCountText.setString(std::to_string(this->itemcount));
	this->itemCountText.setFillColor(sf::Color::White);
	this->itemCountText.setPosition(
		this->displayBackground.getPosition().x + (this->displayBackground.getGlobalBounds().width / 2.f) / 2.f,
		this->displayBackground.getPosition().y + (this->displayBackground.getGlobalBounds().height / 2.f) / 2.f);
	this->itemCostText.setFont(this->font);
	this->itemCostText.setString(std::to_string(this->itemcost));
	this->itemCostText.setFillColor(sf::Color::Yellow);
	this->itemCostText.setPosition(
		this->displayBackground.getPosition().x + (this->displayBackground.getGlobalBounds().width / 2.f) / 2.f,
		this->displayBackground.getPosition().y + (this->displayBackground.getGlobalBounds().height / 2.f) / 2.f);
}

void MerchantState::initItemTextures()
{
	this->itemTextures.loadFromFile("Textures/Items/ItemSheet.png");
	this->ItemIcons.setTexture(this->itemTextures);

	this->PotionTextures.loadFromFile("Textures/Items/PotionSheet.png");
	this->PotionIcons.setTexture(this->PotionTextures);
}

void MerchantState::endState()
{
	std::cout << "ending MERCHANT STATE\n";
}

int MerchantState::getState()
{
	return 3;
}

void MerchantState::updateInput()
{
	this->checkForQuit();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("INVENTORY")))) {
		this->playerInv->displayInv();
	}
}

void MerchantState::updateButtons()
{
	for (auto it : this->InventoryButtons) {
		it.second->update(this->moousePosView);
		if (it.first == "BACK_BTN")
			it.second->shape.setPosition(this->window->getView().getCenter().x - this->window->getView().getSize().x / 2, this->window->getView().getCenter().y + (this->window->getView().getSize().y / 2) - 50);

	}
	if (this->InventoryButtons["BACK_BTN"]->isPressed()) {
		this->quitPressed = true;
	}
}

void MerchantState::update(Inventory* playerINV, unsigned* gold)
{
	this->gold = gold;
	this->playerInv = playerINV;
	if (!inventoryinit) {
		this->InitInventory();
		this->inventoryinit = true;
	}
	this->updateMousePositions();
	this->updateInput();
	this->updateButtons();

	this->goldIcon.setPosition(this->window->getView().getCenter().x + this->window->getView().getSize().x / 3,
		this->window->getView().getCenter().y - this->window->getView().getSize().y / 2);
	this->goldText.setPosition(this->window->getView().getCenter().x + this->window->getView().getSize().x / 2.5,
		this->window->getView().getCenter().y - this->window->getView().getSize().y / 2);
	//std::cout << gold<<"\n";
	this->goldText.setString(std::to_string(*gold));

	if (inventoryinit) {
		this->UpdateInventory();
	}
	this->displayBackground.setPosition(this->moousePosView);
	this->ItemIcons.setPosition(this->displayBackground.getPosition().x + this->displayBackground.getGlobalBounds().width / 2, this->displayBackground.getPosition().y);
	this->PotionIcons.setPosition(this->displayBackground.getPosition().x + this->displayBackground.getGlobalBounds().width / 2, this->displayBackground.getPosition().y);
	this->itemDescriptionText.setPosition(this->displayBackground.getPosition().x, this->displayBackground.getPosition().y + 45);
	this->itemDescriptionText.setString(itemDescription);
	this->itemCountText.setPosition(this->displayBackground.getPosition().x + 40, this->displayBackground.getPosition().y);
	this->itemCountText.setString(std::to_string(this->itemcount));
	this->itemCostText.setPosition(this->displayBackground.getPosition().x + this->displayBackground.getGlobalBounds().width-50, this->displayBackground.getPosition().y);
	this->itemCostText.setString(std::to_string(this->itemcost));

}

void MerchantState::InitInventory()
{
	for (int i = 0; i < 10; i++) {
		std::cout << "\n" << this->playerInv->itemList[i][0] << "  " << this->playerInv->itemList[i][1] << "\n";
	}

	int ygap = 0;
	for (int i = 3; i <= 6; i++) {
			this->itemDisplayButtons[this->playerInv->itemList[i][0]] = new Button(
				this->window->getView().getCenter().x - this->window->getView().getSize().x / 2,
				this->window->getView().getCenter().y - (this->window->getView().getSize().y / 2) + ygap,
				120, 40, this->returnItemName(this->playerInv->itemList[i][0]), &this->font);
			this->itemDisplayButtons[1000+this->playerInv->itemList[i][0]] = new Button(
				this->window->getView().getCenter().x - (this->window->getView().getSize().x / 2)+40,
				this->window->getView().getCenter().y - (this->window->getView().getSize().y / 2) +ygap,
				40, 40, "+", &this->font,sf::Color::Green, sf::Color(0,255,0,15574), sf::Color::Green);
			this->itemDisplayButtons[2000 + this->playerInv->itemList[i][0]] = new Button(
				this->window->getView().getCenter().x - (this->window->getView().getSize().x / 2)+65,
				this->window->getView().getCenter().y - (this->window->getView().getSize().y / 2) + ygap,
				40, 40, "-", &this->font,sf::Color::Red, sf::Color(255,0,0,155), sf::Color::Red);
			ygap += 100;
	}
	
		this->itemDisplayButtons[200] = new Button(
			this->window->getView().getCenter().x - this->window->getView().getSize().x / 2,
			this->window->getView().getCenter().y - (this->window->getView().getSize().y / 2) + ygap,
			120, 40, "Attack Potion", &this->font);
		ygap += 100;
		this->itemDisplayButtons[201] = new Button(
			this->window->getView().getCenter().x - this->window->getView().getSize().x / 2,
			this->window->getView().getCenter().y - (this->window->getView().getSize().y / 2) + ygap,
			120, 40, "Vitality Potion", &this->font);
		ygap += 100;
		this->itemDisplayButtons[202] = new Button(
			this->window->getView().getCenter().x - this->window->getView().getSize().x / 2,
			this->window->getView().getCenter().y - (this->window->getView().getSize().y / 2) + ygap,
			120, 40, "Dexterity Potion", &this->font);
		ygap += 100;
		this->itemDisplayButtons[203] = new Button(
			this->window->getView().getCenter().x - this->window->getView().getSize().x / 2,
			this->window->getView().getCenter().y - (this->window->getView().getSize().y / 2) + ygap,
			120, 40, "Speed Potion", &this->font);
		ygap += 100;
		this->itemDisplayButtons[204] = new Button(
			this->window->getView().getCenter().x - this->window->getView().getSize().x / 2,
			this->window->getView().getCenter().y - (this->window->getView().getSize().y / 2) + ygap,
			120, 40, "Defense Potion", &this->font);
		ygap += 100;
		this->itemDisplayButtons[205] = new Button(
			this->window->getView().getCenter().x - this->window->getView().getSize().x / 2,
			this->window->getView().getCenter().y - (this->window->getView().getSize().y / 2) + ygap,
			120, 40, "Life Potion", &this->font);
		ygap += 100;
	
}

void MerchantState::UpdateInventory()
{
	
	int ygap = 0;
	int addygap = 0;
	int subygap = 0;
	for (auto it : this->itemDisplayButtons) {
		it.second->update(this->moousePosView);
		if (it.first > 1000 && it.first < 2000) {
			it.second->shape.setPosition(
				this->window->getView().getCenter().x - (this->window->getView().getSize().x / 2) + 100 + 160,
				this->window->getView().getCenter().y - (this->window->getView().getSize().y / 3) + addygap);
			addygap += 45;
		}
		else if (it.first > 2000) {
			it.second->shape.setPosition(
				this->window->getView().getCenter().x - (this->window->getView().getSize().x / 2) + 100 + 200,
				this->window->getView().getCenter().y - (this->window->getView().getSize().y / 3) + subygap);
			subygap += 45;
		}
		else {
			it.second->shape.setPosition(
				this->window->getView().getCenter().x - (this->window->getView().getSize().x / 2) + 100,
				this->window->getView().getCenter().y - (this->window->getView().getSize().y / 3) + ygap);
			ygap += 45;
		}
	
		
		
	}
	hoverdisplaybool = false;
	if (this->itemDisplayButtons[103]->isHovered()) {
		this->updateItemSpriteandName(103);
		this->hoverdisplaybool = true;
	}
	if (this->itemDisplayButtons[1103]->isPressed()) {
		if (*this->gold > 250) {
			this->playerInv->itemList[3][1]++;
			this->player->incrementItemsBought(1);
			*this->gold -= 250;
		}
	}
	if (this->itemDisplayButtons[2103]->isPressed()) {
		if(this->playerInv->itemList[3][1])
		this->playerInv->itemList[3][1]--;
		this->gold += 125;
	}

	

	if (this->itemDisplayButtons[104]->isHovered()) {
		this->updateItemSpriteandName(104);
		this->hoverdisplaybool = true;
	}
	if (this->itemDisplayButtons[1104]->isPressed()) {
		if (*this->gold > 500) {
			this->playerInv->itemList[4][1]++;
			this->player->incrementItemsBought(1);
			*this->gold -= 500;
		}
	}
	if (this->itemDisplayButtons[2104]->isPressed()) {
		if (this->playerInv->itemList[4][1])
		this->playerInv->itemList[4][1]--;
		this->gold += 250;
	}


	if (this->itemDisplayButtons[105]->isHovered()) {
		this->updateItemSpriteandName(105);
		this->hoverdisplaybool = true;
	}
	if (this->itemDisplayButtons[1105]->isPressed()) {
		if (*this->gold > 750) {
			this->playerInv->itemList[5][1]++;
			this->player->incrementItemsBought(1);
			*this->gold -= 750;
		}
	}
	if (this->itemDisplayButtons[2105]->isPressed()) {
		if (this->playerInv->itemList[5][1])
		this->playerInv->itemList[5][1]--;
		this->gold += 325;
	}


	if (this->itemDisplayButtons[106]->isHovered()) {
		this->updateItemSpriteandName(106);
		this->hoverdisplaybool = true;
	}
	if (this->itemDisplayButtons[1106]->isPressed()) {
		if (*this->gold > 1500) {
			this->playerInv->itemList[6][1]++;
			this->player->incrementItemsBought(1);
			*this->gold -= 1500;
		}
	}
	if (this->itemDisplayButtons[2106]->isPressed()) {
		if (this->playerInv->itemList[6][1])
		this->playerInv->itemList[6][1]--;
		this->gold += 750;
	}
	if (this->hoverdisplaybool) {
		this->hoverdisplay = true;
	}
	if (this->itemDisplayButtons[200]->isHovered()) {
		this->updateItemSpriteandName(200);
		this->hoverdisplaybool = true;
	}
	if (this->itemDisplayButtons[200]->isPressed()) {
		if (*this->gold > 100) {
			this->player->damage+10;
			this->player->incrementPotionsDrank(1);
			*this->gold -= 100;
		}
	}
	if (this->itemDisplayButtons[201]->isHovered()) {
		this->updateItemSpriteandName(201);
		this->hoverdisplaybool = true;
	}
	if (this->itemDisplayButtons[201]->isPressed()) {
		if (*this->gold > 100) {
			this->player->increaseVitality(2);
			this->player->incrementPotionsDrank(1);
			*this->gold -= 100;
		}
	}
	if (this->itemDisplayButtons[202]->isHovered()) {
		this->updateItemSpriteandName(202);
		this->hoverdisplaybool = true;
	}
	if (this->itemDisplayButtons[202]->isPressed()) {
		if (*this->gold > 100) {
			this->player->increaseDexterity(0.1);
			this->player->incrementPotionsDrank(1);
			*this->gold -= 100;
		}
	}
	if (this->itemDisplayButtons[203]->isHovered()) {
		this->updateItemSpriteandName(203);
		this->hoverdisplaybool = true;
	}
	if (this->itemDisplayButtons[203]->isPressed()) {
		if (*this->gold > 100) {
			this->player->increaseSpeed(1);

			this->player->incrementPotionsDrank(1);
			*this->gold -= 100;
		}
	}
	if (this->itemDisplayButtons[204]->isHovered()) {
		this->updateItemSpriteandName(204);
		this->hoverdisplaybool = true;
	}
	if (this->itemDisplayButtons[204]->isPressed()) {
		if (*this->gold > 100) {
			this->player->increaseDefense(10);
			this->player->incrementPotionsDrank(1);
			*this->gold -= 100;
		}
	}
	if (this->itemDisplayButtons[205]->isHovered()) {
		this->updateItemSpriteandName(205);
		this->hoverdisplaybool = true;
	}
	if (this->itemDisplayButtons[205]->isPressed()) {
		if (*this->gold > 200) {
			this->player + 50;
			this->player->incrementPotionsDrank(1);
			*this->gold -= 200;
		}
	}
}

void MerchantState::render(sf::RenderTarget* target)
{
	target->draw(this->Inventorybackground);
	for (auto it : this->InventoryButtons) {
		it.second->render(target);
	}
	target->draw(this->goldIcon);
	target->draw(this->goldText);
	if (inventoryDisplayed) {
		for (auto it : this->itemDisplayButtons) {
			it.second->render(target);
		}
	}
	if (hoverdisplay) {
		target->draw(this->displayBackground);
		if (itemsDisplay) {
		target->draw(this->ItemIcons);
		target->draw(this->itemCountText);
		}
		if (potionsDisplay) {
			target->draw(this->PotionIcons);
		}
		target->draw(this->itemDescriptionText);
		target->draw(this->itemCostText);
	}
}
