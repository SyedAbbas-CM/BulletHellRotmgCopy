#pragma once
#include"Random.h"
class SpriteManager
{

public:
	
	void LoadTextureEnemy(std::string name, std::string filename);
	void LoadTextureBullet(std::string name, std::string filename);
	sf::Texture* getTextureEnemy(std::string name);
	sf::Texture* getTextureBullet(std::string name);
	void DeleteTexture(std::string name, std::string filename);
	static SpriteManager* getInstance();
private:
	SpriteManager();
	~SpriteManager();
	std::map<std::string, sf::Texture*> enemytextures;
	std::map<std::string, sf::Texture*> bullettextures;
	std::map<std::string, sf::Font> fonts;
	static SpriteManager* instance;

};

