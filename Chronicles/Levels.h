#pragma once
#include "SFML/Graphics.hpp"
#include <map>
#include <functional>


class Levels
{
	
public:
	Levels();
	~Levels();
	void play();
	void levelClear();


	int getLevel();

	sf::Time& getWhiteGhostTimerMax();
	int& getNumberWhiteSpawn();

	sf::Time& getBlackGhostTimerMax();
	int& getNumberBlackSpawn();

	int getLevelmax();
	int getEnnemiesObjectives();
	sf::Time getTimeRestriction();
	
private:
	
	void level_1();
	void level_2();
	void level_3();
	void level_4();
	void level_5();
	void level_6();
	void level_7();
	void level_8();
	void level_9();
	void level_10();
	void initMap();
	
	std::map<int, std::function<void(void)>> levelMap;
	int level;
	sf::Time whiteGhostTimerMax;
	int numberWhiteSpawn;
	sf::Time blackGhostTimerMax;
	int numberBlackSpawn;
	int levelMax;
	int ennemiesObjectives;
	sf::Time timeRestriction;
};

