#pragma once

#include <ctime>
#include "Ninja.h"
#include "Physics.h"
#include "UI.h"
#include "TerrainManager.h"
#include "WhiteGhost.h"
#include "BlackGhost.h"
#include "Bouton.h"
#include "Kunai.h"
#include "LifePotion.h"
#include "Ennemy.h"
#include "SaveGame.h"
#include "Levels.h"


class Survival:public UI
{


public:
	//contructeur/desctructeur
	Survival();
	virtual ~Survival();

	// creer la liste dennemi
	
	void update(sf::RenderWindow* window, sf::Time elapsed) override;
	//render game
	
	void render(sf::RenderWindow* window) override;
	
	void reloadSave();
	bool goMenu();
	void setGoMenu(bool go);
	void begin();
private:

	void initAffichage();
	void spawnWhiteEnnemy(sf::RenderWindow* window);
	void spawnBlackEnnemy(sf::RenderWindow* window);
	void spawnKunai(sf::RenderWindow* window);
	void spawnPotion(sf::RenderWindow* window);
	//gere events
	void pollEvents(sf::RenderWindow* window) override;
	//update game
	void updateEnnemies(sf::RenderWindow* window, sf::Time elapsed);
	
	void updateKunai(sf::RenderWindow* window, sf::Time elapsed);
	void updatePotion(sf::RenderWindow* window, sf::Time elapsed);
	void updateMousePos(sf::RenderWindow* window);
	
	void renderEnnemies(sf::RenderWindow* window);
	void renderKunai(sf::RenderWindow* window);
	void manageColision();
	void retry();
	void endGame();
	void updateRecommencer(sf::RenderWindow* window);
	void renderRecommencer(sf::RenderWindow* window);
	void checkHoverBouton();


	//variable
	int score;
	int highScore;
	int ninjaXSpeed;
	bool kunaiAvailable;
	bool potionAvailable;

	sf::Clock timerKunai;
	sf::Clock timerPotion;
	sf::Clock levelTime;
	
	Levels level;
	sf::Time whiteGhostTimer;
	sf::Time& whiteGhostTimerMax;
	int& numberWhiteSpawn;
	sf::Time blackGhostTimer;
	sf::Time& blackGhostTimerMax;
	int& numberBlackSpawn;
	std::vector<Ennemy*> ennemies;
	int killedEnnemies;
	//objets
	Ninja ninja;
	Kunai kunaiDrop;
	LifePotion lifePotionDrop;
	std::vector<Kunai>throwedKunai;
	TerrainManager terrainManager;
	
	
	
	bool pause;
	bool menu;
	sf::Text displayScore;
	sf::Text displayHighScore;
	sf::Text displayLevel;
	sf::Text allLevelClear;
	sf::Text displayNbKunai;
	sf::Font textFont;
	sf::Text displayLife;
	Bouton buttonRetry;
	Bouton buttonMenu;
	sf::Text displayGold;
	sf::Text displayTimer;
	sf::Text ennemiesToKill;
	sf::SoundBuffer bufferMusic;
	sf::Sound music;
};

