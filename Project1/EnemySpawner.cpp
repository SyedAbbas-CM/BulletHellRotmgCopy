#include "EnemySpawner.h"

void EnemySpawner::incrementTimers()
{
	this->spawnTimer += 0.5;
	this->spawnTimer2 += 0.1;
	this->spawnTimer3 += 0.1;
	this->spawnTimer4 += 0.1;
}

void EnemySpawner::updateTimerMax()
{
	
	
	if (WaveClockTime.asSeconds() >= this->timeBetweenWave) {
		if (!this->incremented) {
			//this->enemyMaxCount += 5;
			this->waveNo += 1;
			this->incremented = true;
			//this->timeBetweenWave -= 2;
			std::cout << this->waveNo << "\m";
		}
		this->waveSpawnOver = false;
		this->enemiesSpawned = 0;
		this->incremented = false;
		
	}

	
}

void EnemySpawner::spawnEnemies()
{
	
	this->WaveClockTime = this->WaveClock.getElapsedTime();
	if (this->enemiesSpawned <= this->enemyMaxCount) {

		this->randNo = rand.generateRandom(100, 0);
		this->posX = rand.generateRandom(2000,500);
		this->posY = rand.generateRandom(2000, 500);


				if (this->spawnTimer >= this->spawnTimerMax) {
						this->enemies->push_back(new BasicEnemy(posX, posY));
				this->enemiesSpawned++;
				this->spawnTimer = 125.f;
				}
		this->WaveClock.restart();
	}
	else {
		this->waveSpawnOver = true;
		this->update();

	}


	
}

void EnemySpawner::update()
{
	if (waveSpawnOver) {
		this->updateTimerMax();
	}
}

EnemySpawner::EnemySpawner(std::vector<Enemy*>* enemies, SpriteManager* spManager)
{
	this->spManager = spManager;
	this->incremented = false;
	this->waveNo = 0;
	this->RedKnightProbMax = 60;
	this->RedKnightProbMin = 55;
	this->SilverKnightProbMax =100;
	this->SilverKnightProbMin = 95;
	this->normalEnemyProbMax= 50;
	this->normalEnemyProbMin = 0;
	this->MinotaurProbMax = 95;
	this->MinotaurProbMin = 90;
	this->waveSpawnOver = false;
	this->enemyMaxCount = 300;
	this->enemiesSpawned = 0;
	this->enemies = enemies;
	this->spawnTimerMax = 125.f;
	this->spawnTimerMax2 = 200.f;
	this->spawnTimer2 = this->spawnTimerMax2;
	this->spawnTimer = this->spawnTimerMax;
	this->spawnTimerMax3 = 225.f;
	this->spawnTimer3 = this->spawnTimerMax3;
	this->spawnTimerMax4 = 250.f;
	this->spawnTimer4 = this->spawnTimerMax3;
	this->WaveClockTime = sf::seconds(0.01f);
	this->timeBetweenWave = 15;

}

EnemySpawner::~EnemySpawner()
{
}
