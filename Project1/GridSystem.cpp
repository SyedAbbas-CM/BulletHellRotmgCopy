#include "GridSystem.h"

GridSystem::GridSystem(int sizeX, int sizeY, int startx, int starty)
{
	this->gridXsize = 250; 
	this->gridYsize = 250;
	this->noOfGridsX = sizeX / gridXsize;
	this->noOfGridsY = sizeY / gridYsize;
	this->startX = startx;
	this->startY = starty;
	this->gridInit(sizeX,sizeY);
	

}

GridSystem::~GridSystem()
{
}

void GridSystem::DrawGrid(sf::RenderTarget* target)
{
	//target->draw(*this->grid);
	for (int x = 0; x < noOfGridsX; x++) {
		for (int y = 0; y < noOfGridsY; y++) {
			target->draw(*tilemaps[x][y]);
		}

	}
}

std::pair<int, int> GridSystem::getGridNumber(sf::FloatRect entity)
{
	for (int i = 0; i < noOfGridsX;i++) {
		for (int j = 0; j < noOfGridsY;j++) {
			if (tilemaps[i][j]->getGlobalBounds().intersects(entity)) {
				
				std::cout << i << ' ' << j << '\n';
				return std::pair<int, int>(i, j);
			}
		}
	}

}

void GridSystem::gridInit(int sizeX, int sizeY)
{
	

	for (int j = 0; j < noOfGridsX;j++) {
		for (int i = 0; i < noOfGridsY; i++) {
			
			this->tilemap.push_back(new sf::RectangleShape(sf::Vector2f(this->gridXsize, this->gridYsize)));
		}
		this->tilemaps.push_back(this->tilemap);
		this->tilemap.clear();
	}
	int posX = startX;
	for (int x = 0; x < noOfGridsX; x++) {
		int posY = this->startY;
		std::cout << this->startY;
		for (int y = 0; y < this->noOfGridsY; y++) {
			posY += this->gridYsize;
			tilemaps[x][y]->setFillColor(sf::Color::Transparent);
			tilemaps[x][y]->setOutlineThickness(1.5f);
			tilemaps[x][y]->setOutlineColor(sf::Color::Red);
			tilemaps[x][y]->setPosition(posX, posY);
		}
		posX += this->gridXsize;

	}
}
