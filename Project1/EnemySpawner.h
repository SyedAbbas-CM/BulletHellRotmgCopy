#pragma once
#include"Random.h"
#include"Enemy.h"

#include"RedEnemy.h"



#include "SpriteManager.h"
class EnemySpawner
{
private:
	//spawnTimers
	float spawnTimer;
	float spawnTimerMax;
	float spawnTimer2;
	float spawnTimerMax2;
	float spawnTimer3;
	float spawnTimerMax3;
	float spawnTimer4;
	float spawnTimerMax4;

	//enemy count
	int enemyMaxCount;
	int enemiesSpawned;


	//enemy probability
	int RedKnightProbMax;
	int RedKnightProbMin;
	int SilverKnightProbMax;
	int SilverKnightProbMin;
	int normalEnemyProbMax;
	int normalEnemyProbMin;
	int MinotaurProbMax;
	int MinotaurProbMin;

	int randRedKnightSpawn;

	//wave
	bool waveSpawnOver;
	int waveNo;
	bool incremented;
	bool bossSpawned;
	int timeBetweenWave;
	Random rand;
	int randNo;
	int posX;
	int posY;
	sf::Time WaveClockTime;
	sf::Clock WaveClock;
	std::vector<Enemy*>* enemies;
	std::string texfilename;
	SpriteManager* spManager;
public:
	void incrementTimers();
	void updateTimerMax();
	void spawnEnemies();
	void update();
	EnemySpawner(std::vector<Enemy*>* enemies,SpriteManager* spManager);
	~EnemySpawner();
};

