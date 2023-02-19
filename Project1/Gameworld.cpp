#include "Gameworld.h"

void Gameworld::setUpInitialState()
{
	this->setUpBaseGround();
	this->setUpWalls();
	this->setupEnviroment();
	this->cleanEnviroment();
}

Gameworld::Gameworld()
{
	this->worldSizelimNegX = -5000;
	this->worldSizelimX = 8000;
	this->worldSizelimNegY = -5000;
	this->worldSizelimY = 8000;

	this->grid = new GridSystem(3000,3000,0,-250);
	this->setUpInitialState();
}

void Gameworld::drawGameWorld(sf::RenderTarget* target)
{
	
	for (unsigned i = 0; i < this->tiles.size(); i++) {
		for (unsigned j = 0; j < this->tiles[i].size(); j++) {
			target->draw(this->tiles[i][j]->sprite);
		}
	}
	for (unsigned i = 0; i < this->passObjs.size(); i++) {
		for (unsigned j = 0; j < this->passObjs[i].size(); j++) {
			this->passObjs[i][j]->render(*target);
		}
	}
	for (unsigned i = 0; i < this->NonPassObjs.size(); i++) {
		for (unsigned j = 0; j < this->NonPassObjs[i].size(); j++) {
			this->NonPassObjs[i][j]->render(*target);
		}
	}
	this->grid->DrawGrid(target);
}

std::pair<int, int> Gameworld::getGridLoc(sf::FloatRect entity)
{
	return this->grid->getGridNumber(entity);
}

void Gameworld::gameworldupdate()
{
}

void Gameworld::setUpBaseGround()
{
	tiles.clear();
	std::vector<Tilemap*> firstRow;
	firstRow.push_back(new Tilemap("Textures/Tiles/Water.png", this->worldSizelimNegX, this->worldSizelimNegY, true, false, 
		this->worldSizelimX + abs(this->worldSizelimNegX), this->worldSizelimY+ abs(this->worldSizelimNegY)));
	firstRow.push_back(new Tilemap("Textures/Tiles/DarkGrass.png", 0, 0, true, false,3000,3000));
	
	tiles.push_back(firstRow);

}

void Gameworld::setUpWalls()
{
	NonPassObjs.clear();
	setupRooms();

}

void Gameworld::setupRooms()

{
	std::vector<nonPassableObject*> firstRow;
	std::vector<Tilemap*> SecondRow;
	int startx, starty, roomsize, doorlocation, noOfRooms;
	noOfRooms = rand.generateRandom(15, 10);
	startx = rand.generateRandom0(500);
	starty = rand.generateRandom0(500);
	int doorposx[4] = {0,0,0,0};
	int doorposy[4] = { 0,0,0,0 };;
	roomsize = rand.generateRandom(7, 7);
	doorlocation = rand.generateRandom(roomsize, 1);
	for (int r = 0; r < noOfRooms; r++) {
		
		for (int i = 0; i < roomsize; i++) {
			if (i != doorlocation && i != doorlocation + 1 && i != doorlocation - 1) {
				firstRow.push_back(new Wall(0, i * 75 + startx, starty));

			}
			else if (i == doorlocation) {
				doorposx[0] = i * 75 + startx +150;
				doorposy[0] = starty + 150;
			}
		}

		for (int i = 0; i < roomsize; i++) {
			if (i != doorlocation && i != doorlocation + 1 && i != doorlocation - 1) {
				firstRow.push_back(new Wall(0, i * 75 + startx, roomsize * 75 + starty));

			}
			else if (i == doorlocation) {
				doorposx[1] = i * 75 + startx + 150;
				doorposy[1] = roomsize * 75 + starty + 150;
			}
		}
		for (int i = 0; i < roomsize; i++) {
			if (i != doorlocation && i != doorlocation + 1 && i != doorlocation - 1) {
				firstRow.push_back(new Wall(0, startx, i * 75 + starty));

			}
			else if (i == doorlocation) {
				doorposx[2] = startx + 75 + 150;
				doorposy[2] = i * 75 + starty + 150;
			}
		}
		for (int i = 0; i < roomsize + 1; i++) {
			if (i != doorlocation && i != doorlocation + 1 && i != doorlocation - 1) {
				firstRow.push_back(new Wall(0, roomsize * 75 + startx, i * 75 + starty));

			}
			else if (i == doorlocation) {
				doorposx[3] = roomsize * 75 + startx + 150;
				doorposy[3] = i * 75 + starty + 150;
			}
		}
		SecondRow.push_back(new Tilemap("Textures/Tiles/Stones.png", startx, starty, true, false, 80 * (roomsize + 1), 70 * (roomsize+1 )));
		startx = doorposx[rand.generateRandom(3, 0)];
		starty = doorposy[rand.generateRandom(3, 0)];
	}
	NonPassObjs.push_back(firstRow);
	tiles.push_back(SecondRow);
}

void Gameworld::setupEnviroment()
{
	int posX, posY;
	int objectno = rand.generateRandom(50, 35);
	std::vector<passableObject*> FirstRow;
	std::vector<passableObject*> secondRow;
	std::vector<nonPassableObject*> SecondRow;
	for (int i = 0; i < objectno + 1; i++) {
		 posX = rand.generateRandom0(3000) ;
		 posY = rand.generateRandom0(3000) ;
		 SecondRow.push_back(new Doodads(posX, posY));
		 posX = rand.generateRandom0(3000);
		 posY = rand.generateRandom0(3000);
		 FirstRow.push_back(new nonInteractable(posX,posY));
	}

	for (int j = 0; j < 30; j++) {
		posY = rand.generateRandom(3000 , 0);
		posX = rand.generateRandom(3000 , 0);
		secondRow.push_back(new Interactable(posX, posY,0));
	}
	
	NonPassObjs.push_back(SecondRow);
	passObjs.push_back(FirstRow);
	passObjs.push_back(secondRow);
}

void Gameworld::cleanEnviroment()
{
	for (int i = 0; i < tiles[1].size(); i++) {
		for (int j = 0; j < NonPassObjs[1].size(); j++) {
			if (this->tiles[1][i]->getBounds().intersects(this->NonPassObjs[1][j]->getbounds())) {
				delete NonPassObjs[1][j];
				this->NonPassObjs[1].erase(this->NonPassObjs[1].begin() + j);
			}
		}
		for (int j = 0; j < passObjs[1].size(); j++) {
			if (this->tiles[1][i]->getBounds().intersects(this->passObjs[1][j]->getbounds())) {
				delete passObjs[1][j];
				this->passObjs[1].erase(this->passObjs[1].begin() + j);
			}
		}
	}

}
