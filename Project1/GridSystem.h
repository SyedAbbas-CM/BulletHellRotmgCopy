#pragma once
#include"Random.h"
class GridSystem
{
public:
	GridSystem(int sizeX,int sizeY,int startx,int starty);
	~GridSystem();
	void DrawGrid(sf::RenderTarget* target);
	std::pair<int, int> getGridNumber(sf::FloatRect entity);
	
private:
	void gridInit(int sizeX, int sizeY);
	int gridXsize, gridYsize;
	std::vector<std::vector<sf::RectangleShape*>> tilemaps;
	std::vector<sf::RectangleShape*> tilemap;
	int sizeX;
	int sizeY;
	int startX;
	int startY;
	int noOfGridsX;
	int noOfGridsY;
	class gridQuadNode {
	public:
		sf::RectangleShape* grid;
		gridQuadNode* next1;
		gridQuadNode* next2;
		gridQuadNode* next3;
		gridQuadNode* next4;
	private:

	};
};

