#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include<string.h>
#include<string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include"dArr.h"
class Random
{
public:
	Random();
	~Random();
	int generateRandom(int max,int min);
	int generateRandom0(int max);
	bool generateRandomBool();
};

