#pragma once
#include <stdio.h>
#include<iostream>
class Inventory
{
private:
	
	void inititemList();
public:
	Inventory();
	~Inventory();
	int itemList[10][2];
	int itemListEquipped[10][2];
	void addItem(int Id);
	void removeItem(int Id);
	void equipItem(int Id);
	void unequipItem(int Id);
	void displayInv();
	int getEquip(int Id);
	//int* getitemList();
};

