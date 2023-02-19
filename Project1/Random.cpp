#include "Random.h"

Random::Random()
{
}

Random::~Random()
{
}

int Random::generateRandom(int max,int min)
{
	int randomNumber = rand();
	float random = (randomNumber % (2*max)) - max;
	if (random <= min) {
		random = min;
	}
	int myRandom = random;
	return myRandom;
}

int Random::generateRandom0(int max)
{
	int randomNumber = rand();
	float random = (randomNumber & max);
	int myRandom = random;
	return myRandom;
}

bool Random::generateRandomBool()
{
	int randomNumber = rand();
	float random = (randomNumber % 2) + 1;
	int myRandom = random;
	if (myRandom == 1) {
		return true;
	}
	else {
		return false;
	}
}
