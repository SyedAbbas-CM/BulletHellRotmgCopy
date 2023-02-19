#ifndef  GAMEWORLD_H
#define GAMEWORLD_H
#include"Tilemap.h"
#include"Wall.h"
#include"Doodads.h"
#include"nonInteractable.h"
#include"Interactable.h"
#include"GridSystem.h"
class Gameworld
{
private:
	void setUpInitialState();
	void gameworldupdate();
	void setUpBaseGround();
	void setUpWalls();
	void setupRooms();
	void setupEnviroment();
	void cleanEnviroment();
	Random rand;
	GridSystem* grid;
	int gridboxsize;
	int worldSizelimX;
	int worldSizelimNegX;
	int worldSizelimNegY;
	int worldSizelimY;

public:
	std::vector < std::vector<Tilemap*>> tiles;
	std::vector < std::vector<nonPassableObject*>> NonPassObjs;
	std::vector < std::vector<passableObject*>> passObjs;
	Gameworld();
	void drawGameWorld(sf::RenderTarget* target);
	std::pair<int, int> getGridLoc(sf::FloatRect entity);

};
#endif //GAMEWORLD_H

