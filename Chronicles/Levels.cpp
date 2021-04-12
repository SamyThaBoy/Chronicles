#include "Levels.h"
#include <iostream>



Levels::Levels()
{
	whiteGhostTimerMax = sf::Time();
	numberWhiteSpawn =0;
	blackGhostTimerMax = sf::Time();
	numberBlackSpawn = 0;
	level = 1;
	initMap();
	levelMax = 10;
	
	

}

Levels::~Levels()
{
	
}



void Levels::play()
{
	level = 1;
	level_1();
}

void Levels::levelClear()
{
	level++;
	
	if (levelMap[level]) {
		levelMap[level]();
	}
	else {
		//std::cout << "empty";
	}
	
}

int Levels::getLevel()
{
	return level;
}



sf::Time& Levels::getWhiteGhostTimerMax()
{
	return whiteGhostTimerMax;
}

int& Levels::getNumberWhiteSpawn()
{
	return numberWhiteSpawn;
}



sf::Time& Levels::getBlackGhostTimerMax()
{
	return blackGhostTimerMax;
}

int& Levels::getNumberBlackSpawn()
{
	return numberBlackSpawn;
}

int Levels::getLevelmax()
{
	return levelMax;
}

int Levels::getEnnemiesObjectives()
{
	return ennemiesObjectives;
}

sf::Time Levels::getTimeRestriction()
{
	return timeRestriction;
}

void Levels::level_1()
{
	
	whiteGhostTimerMax = sf::seconds(6);
	numberWhiteSpawn = 2;
	blackGhostTimerMax = sf::seconds(10);
	numberBlackSpawn = 0;
	ennemiesObjectives = 5;
	timeRestriction = sf::seconds(25);
}
void Levels::level_2()
{

	whiteGhostTimerMax = sf::seconds(6);
	numberWhiteSpawn = 3;
	blackGhostTimerMax = sf::seconds(10);
	numberBlackSpawn = 1;
	ennemiesObjectives = 8;
	timeRestriction = sf::seconds(20);
}

void Levels::level_3()
{
	whiteGhostTimerMax = sf::seconds(5);
	numberWhiteSpawn = 1;
	blackGhostTimerMax = sf::seconds(8);
	numberBlackSpawn = 3;
	ennemiesObjectives = 8;
	timeRestriction = sf::seconds(22);
}

void Levels::level_4()
{
	whiteGhostTimerMax = sf::seconds(5);
	numberWhiteSpawn = 3;
	blackGhostTimerMax = sf::seconds(7);
	numberBlackSpawn = 3;
	ennemiesObjectives = 11;
	timeRestriction = sf::seconds(20);
}

void Levels::level_5()
{
	whiteGhostTimerMax = sf::seconds(5);
	numberWhiteSpawn = 2;
	blackGhostTimerMax = sf::seconds(10);
	numberBlackSpawn = 5;
	ennemiesObjectives = 11;
	timeRestriction = sf::seconds(23);
}

void Levels::level_6()
{
	whiteGhostTimerMax = sf::seconds(6);
	numberWhiteSpawn = 4;
	blackGhostTimerMax = sf::seconds(8);
	numberBlackSpawn = 5;
	ennemiesObjectives = 11;
	timeRestriction = sf::seconds(20);
}

void Levels::level_7()
{
	whiteGhostTimerMax = sf::seconds(6);
	numberWhiteSpawn = 5;
	blackGhostTimerMax = sf::seconds(8);
	numberBlackSpawn = 5;
	ennemiesObjectives = 15;
	timeRestriction = sf::seconds(20);
}

void Levels::level_8()
{
	whiteGhostTimerMax = sf::seconds(5);
	numberWhiteSpawn = 7;
	blackGhostTimerMax = sf::seconds(8);
	numberBlackSpawn = 5;
	ennemiesObjectives = 25;
	timeRestriction = sf::seconds(20);
}

void Levels::level_9()
{
	whiteGhostTimerMax = sf::seconds(6);
	numberWhiteSpawn = 8;
	blackGhostTimerMax = sf::seconds(2);
	numberBlackSpawn = 2;
	ennemiesObjectives = 30;
	timeRestriction = sf::seconds(20);
}

void Levels::level_10()
{
	whiteGhostTimerMax = sf::seconds(3);
	numberWhiteSpawn = 5;
	blackGhostTimerMax = sf::seconds(2);
	numberBlackSpawn = 2;
	ennemiesObjectives = 55;
	timeRestriction = sf::seconds(20);
}

void Levels::initMap()
{
	

	levelMap = 
	{ {1, std::bind(&Levels::level_1,this)},
		{2, std::bind(&Levels::level_2,this)},
		{3, std::bind(&Levels::level_3,this)},
		{4, std::bind(&Levels::level_4,this)},
		{5, std::bind(&Levels::level_5,this)},
		{6, std::bind(&Levels::level_6,this)},
		{7, std::bind(&Levels::level_7,this)},
		{8, std::bind(&Levels::level_8,this)},
		{9, std::bind(&Levels::level_9,this)},
		{10, std::bind(&Levels::level_10,this)},
	};
	
}



