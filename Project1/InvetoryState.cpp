#include "InvetoryState.h"

void InvetoryState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["INVENTORY"] = this->supportedKeys->at("B");
}

void InvetoryState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/rpgFONT.ttf")) {
		std::cout << "error in font";
	}
}

void InvetoryState::initButtons()
{
	this->InventoryButtons["BACK_BTN"] = new Button(this->window->getView().getCenter().x - this->window->getView().getSize().x / 2,
		this->window->getView().getCenter().y - (this->window->getView().getSize().y / 2), 120, 40
		, "Back", &this->font, sf::Color(255, 215, 0, 255), sf::Color(255, 215, 0, 150), sf::Color(255, 215, 0, 255));
}

void InvetoryState::initGUI()
{
	this->Inventorybackground.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	this->Inventorybackground.setPosition(this->window->getPosition().x - (this->Inventorybackground.getGlobalBounds().width / 2.5f),
		this->window->getPosition().y - (this->Inventorybackground.getGlobalBounds().height / 4));
	this->Inventorybackground.setFillColor(sf::Color::Black);
	this->itemrect = sf::IntRect(0,0,40,40);





	this->goldIconTexture.loadFromFile("Textures/goldIcon.png");
	this->goldIcon.setTexture(this->goldIconTexture);
	this->goldIcon.setPosition(this->window->getPosition().x, this->window->getPosition().y);
	this->goldIcon.setScale(4.f, 4.f);
	this->goldText.setFont(this->font);
	this->goldText.setFillColor(sf::Color::Yellow);
	this->goldText.setString("0");

}

InvetoryState::InvetoryState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states,  Player* player)
	:State(window, supportedKeys, states,player)
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
}

InvetoryState::~InvetoryState()
{
	auto it = this->InventoryButtons.begin();
	for (it = this->InventoryButtons.begin(); it != this->InventoryButtons.end(); ++it) {
		delete it->second;
	}
}

std::string InvetoryState::returnItemName(int Id)
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
	else
	{
		return " ";
	}
}

void InvetoryState::updateItemSpriteandName(int Id)
{
	if (Id == 100) {
		this->itemrect.left = 0 * 40;
		itemcount = this->playerInv->itemList[0][1];
		itemDescription = "An old rusty sword. It is almost useless";
	}
	else if (Id == 101) {
		this->itemrect.left = 1 * 40;
		itemcount = this->playerInv->itemList[1][1];
		itemDescription = "A fine sword that is mastered by all warriors";
	}
	else if (Id == 102) {
		this->itemrect.left = 2 * 40;
		itemcount = this->playerInv->itemList[2][1];
		itemDescription = "A Powerful sword wielded by elite warriors";
	}
	else if (Id == 103) {
		this->itemrect.left = 3 * 40;
		itemcount = this->playerInv->itemList[3][1];
		itemDescription = "The Standard Weapon of a Skilled Knight";
	}
	else if (Id == 104) {
		this->itemrect.left = 4 * 40;
		itemcount = this->playerInv->itemList[4][1];

		itemDescription = "A Mighty GreatSword";
	}
	else if (Id == 105) {
		this->itemrect.left = 5 * 40;
		itemcount = this->playerInv->itemList[5][1];
	
		itemDescription = "A Sword that burns with an unholy flame";

	}
	else if (Id == 106) {
		this->itemrect.left = 6 * 40;
		itemcount = this->playerInv->itemList[6][1];

		itemDescription = "Enchanted Runes Decorate this Sword";
	}
	else if (Id == 107) {
		this->itemrect.left = 7 * 40;
		itemcount = this->playerInv->itemList[7][1];
		itemDescription = "A Great Lord's Sword";
	}
	else if (Id == 108) {
		this->itemrect.left = 8 * 40;
		itemcount = this->playerInv->itemList[8][1];
		itemDescription = "An Evil Weapon that deals devastating damage";
	}
	else if (Id == 109) {
		this->itemrect.left = 9 * 40;
		itemcount = 0;
		itemDescription = "A legendary knight of old once wielded this blade";

	}
	this->ItemIcons.setTextureRect(this->itemrect);
	
}

void InvetoryState::initdisplayBackground()
{
	this->displayBackground.setSize(sf::Vector2f(500,100));
	this->displayBackground.setPosition(this->window->getPosition().x - (this->Inventorybackground.getGlobalBounds().width / 2.5f),
		this->window->getPosition().y - (this->Inventorybackground.getGlobalBounds().height / 4));
	this->displayBackground.setFillColor(sf::Color(75, 75, 75,255));
	this->ItemIcons.setPosition(this->displayBackground.getPosition().x, this->displayBackground.getPosition().y);
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
}

void InvetoryState::initItemTextures()
{
	this->itemTextures.loadFromFile("Textures/Items/ItemSheet.png");
	this->ItemIcons.setTexture(this->itemTextures);
}

void InvetoryState::endState()
{
	std::cout << "ending INVENTORY STATE\n";
}

int InvetoryState::getState()
{
	return 2;
}

void InvetoryState::updateInput()
{
	this->checkForQuit();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("INVENTORY")))) {
		this->playerInv->displayInv();
	}
}

void InvetoryState::updateButtons()
{
	for (auto it : this->InventoryButtons) {
		it.second->update(this->moousePosView);
		if(it.first == "BACK_BTN")
		it.second->shape.setPosition(this->window->getView().getCenter().x - this->window->getView().getSize().x / 2, this->window->getView().getCenter().y + (this->window->getView().getSize().y / 2) - 50);
		
	}
	if (this->InventoryButtons["BACK_BTN"]->isPressed()) {
		this->quitPressed = true;
	}
}

void InvetoryState::update(Inventory* playerINV,unsigned* gold)
{
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
	this->ItemIcons.setPosition(this->displayBackground.getPosition().x+this->displayBackground.getGlobalBounds().width/2, this->displayBackground.getPosition().y);
	this->itemDescriptionText.setPosition(this->displayBackground.getPosition().x, this->displayBackground.getPosition().y + 45);
	this->itemDescriptionText.setString(itemDescription);
	this->itemCountText.setPosition(this->displayBackground.getPosition().x + 40, this->displayBackground.getPosition().y);
	this->itemCountText.setString(std::to_string(this->itemcount));
	
}

void InvetoryState::InitInventory()
{

		for (int i = 0; i < 10; i++) {
			std::cout << "\n" << this->playerInv->itemList[i][0] << "  " << this->playerInv->itemList[i][1] << "\n";
		}
		
		int ygap=0;
		for (int i = 0; i < 10; i++) {
			if (this->playerInv->itemList[i][1] > 0) {
				this->itemDisplayButtons[this->playerInv->itemList[i][0]] = new Button(
					this->window->getView().getCenter().x - this->window->getView().getSize().x / 2,
					this->window->getView().getCenter().y - (this->window->getView().getSize().y / 2) + ygap,
					120, 40, this->returnItemName(this->playerInv->itemList[i][0]), &this->font);
				ygap += 100;
				//std::cout << "something happened";
			}
		}
		
}

void InvetoryState::UpdateInventory()
{
	hoverdisplaybool = false;
	int ygap = 0;
	for (auto it : this->itemDisplayButtons) {
		it.second->update(this->moousePosView);
			it.second->shape.setPosition(
				this->window->getView().getCenter().x - this->window->getView().getSize().x / 2 + 100,
				this->window->getView().getCenter().y - (this->window->getView().getSize().y / 3)+ygap);
			ygap += 45; 
				//std::cout << "happening";
	}
	if (this->playerInv->itemList[0][1]) {
		if (this->itemDisplayButtons[100]->isHovered()) {
			this->updateItemSpriteandName(100);
			this->hoverdisplaybool = true;
		}
		if (this->itemDisplayButtons[100]->isPressed()) {
			if (!this->playerInv->getEquip(100)) {
				this->playerInv->equipItem(100);
			}
			else {
				this->playerInv->unequipItem(100);
			}
		}
		
	}

	if (this->playerInv->itemList[1][1]) {
		if (this->itemDisplayButtons[101]->isHovered()) {
			this->updateItemSpriteandName(101);
			this->hoverdisplaybool = true;
		}
		if (this->itemDisplayButtons[101]->isPressed()) {
			if (!this->playerInv->getEquip(101)) {
				this->playerInv->equipItem(101);
			}
			else {
				this->playerInv->unequipItem(101);
			}
		}
		
	}
	if (this->playerInv->itemList[2][1]) {
		if (this->itemDisplayButtons[102]->isHovered()) {
			this->updateItemSpriteandName(102);
			this->hoverdisplaybool = true;
		}
		if (this->itemDisplayButtons[102]->isPressed()) {
			if (!this->playerInv->getEquip(102)) {
				this->playerInv->equipItem(102);
			}
			else {
				this->playerInv->unequipItem(102);
			}
		}
		
	}
	if (this->playerInv->itemList[3][1]) {
		if (this->itemDisplayButtons[103]->isHovered()) {
			this->updateItemSpriteandName(103);
			this->hoverdisplaybool = true;
		}
		if (this->itemDisplayButtons[103]->isPressed()) {
			if (!this->playerInv->getEquip(103)) {
				this->playerInv->equipItem(103);
			}
			else {
				this->playerInv->unequipItem(103);
			}
		}
		
	}
	if (this->playerInv->itemList[4][1]) {
		if (this->itemDisplayButtons[104]->isHovered()) {
			this->updateItemSpriteandName(104);
			this->hoverdisplaybool = true;
		}
		if (this->itemDisplayButtons[104]->isPressed()) {
			if (!this->playerInv->getEquip(104)) {
				this->playerInv->equipItem(104);
			}
			else {
				this->playerInv->unequipItem(104);
			}
		}

	}
	if (this->playerInv->itemList[5][1]) {
		if (this->itemDisplayButtons[105]->isHovered()) {
			this->updateItemSpriteandName(105);
			this->hoverdisplaybool = true;
		}
		if (this->itemDisplayButtons[105]->isPressed()) {
			if (!this->playerInv->getEquip(105)) {
				this->playerInv->equipItem(105);
			}
			else {
				this->playerInv->unequipItem(103);
			}
		}

	}
	if (this->playerInv->itemList[6][1]) {
		if (this->itemDisplayButtons[106]->isHovered()) {
			this->updateItemSpriteandName(106);
			this->hoverdisplaybool = true;
		}
		if (this->itemDisplayButtons[106]->isPressed()) {
			if (!this->playerInv->getEquip(106)) {
				this->playerInv->equipItem(106);
			}
			else {
				this->playerInv->unequipItem(106);
			}
		}

	}
	if (this->hoverdisplaybool) {
		this->hoverdisplay = true;
	}
	else {
		this->hoverdisplay = false;
	}
	
}

void InvetoryState::render(sf::RenderTarget* target)
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
		target->draw(this->ItemIcons);
		target->draw(this->itemDescriptionText);
		target->draw(this->itemCountText);
	}
	

}
