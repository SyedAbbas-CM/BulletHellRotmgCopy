#include "Inventory.h"
void Inventory::inititemList()
{
	int Id = 100;
	for (int i=0; i < 10; i++) {
			this->itemList[i][0] = Id;
			this->itemListEquipped[i][0] = Id;
			if (Id == 100) {
				this->itemList[i][1] = 1;
				this->itemListEquipped[i][1] = 1;
			}
			else {
				this->itemList[i][1] = 0;
				this->itemListEquipped[i][1] = 0;
			}
		Id++;
	}
}

Inventory::Inventory()
{
	this->inititemList();
}

Inventory::~Inventory()
{
}

void Inventory::addItem(int Id)
{
	for (int i=0; i < 10; i++) {
		if (this->itemList[i][0] == Id) {
			this->itemList[i][1]++;
		}
		else {
			printf("\n item not found ??\n");
		}
	}
}

void Inventory::removeItem(int Id)
{
	for (int i=0; i < 10; i++) {
		if (this->itemList[i][0] == Id) {
			this->itemList[i][1]--;
		}
		else {
			printf("\n item not found ??\n");
		}
	}
}

void Inventory::equipItem(int Id)
{
	for (int i = 0; i < 10; i++) {
		if (this->itemListEquipped[i][0] == Id) {
			this->itemListEquipped[i][1] = 1;
		}
		else {
			this->itemListEquipped[i][1] = 0;
		}

	}
}

void Inventory::unequipItem(int Id)
{
	for (int i = 0; i < 10; i++) {
		if (this->itemListEquipped[i][0] == Id) {
			this->itemListEquipped[i][1] = 0;
		}
		else {
			this->itemListEquipped[i][1] = 0;
		}
	}
}

void Inventory::displayInv()
{
	for (int i = 0; i < 10; i++) {
		std::cout << "\n" << this->itemListEquipped[i][0] << "  " << this->itemListEquipped[i][1] << "\n";
	}
}

int Inventory::getEquip(int Id)
{
	for (int i = 0; i < 10; i++) {
		if (this->itemListEquipped[i][0] == Id) {
			return this->itemListEquipped[i][1];
		}
	}
	
}


