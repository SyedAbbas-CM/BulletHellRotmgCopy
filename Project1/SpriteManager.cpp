#include "SpriteManager.h"
//holy fuck you really need to call these static things in the cpp files otherwise linker errors !!!
SpriteManager* SpriteManager::instance;
SpriteManager::SpriteManager()
{
	

}

SpriteManager::~SpriteManager()
{
}

void SpriteManager::LoadTextureEnemy(std::string name, std::string filename)
{
	sf::Texture* tex = new sf::Texture();
	if (!tex->loadFromFile(filename)) {
		std::cout << "ERROR::enemy::INITTEXTURE:: could not load texture file\n";

	}
	else {
		this->enemytextures[name] = tex;
		std::cout << "TextureLoaded!\n";
	}

}

void SpriteManager::LoadTextureBullet(std::string name, std::string filename)
{
	sf::Texture* tex = new sf::Texture();
	if (!tex->loadFromFile(filename)) {
		std::cout << "ERROR::enemy::INITTEXTURE:: could not load texture file\n";

	}
	else {
		this->bullettextures[name] = tex;
		std::cout << "TextureLoaded!\n";
	}
}

sf::Texture* SpriteManager::getTextureEnemy(std::string name)
{
		return enemytextures[name];
}

sf::Texture* SpriteManager::getTextureBullet(std::string name)
{
		return bullettextures[name];
	
}

void SpriteManager::DeleteTexture(std::string name, std::string filename)
{
}

SpriteManager* SpriteManager::getInstance()
{
	if (SpriteManager::instance == NULL) {
		SpriteManager::instance = new SpriteManager();
	}
	else {
		return SpriteManager::instance;
	}
}
