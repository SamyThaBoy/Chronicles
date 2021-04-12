#pragma once
#include "Player.h"
#include "Sword.h"
#include "Kunai.h"
class Ninja : public Player
{
public:
	//constructeur/destructeur
	 //Ninja(sf::Texture *texture);
	 Ninja();
	 ~Ninja();
	 //utilitaire perso
	 void move(sf::Vector2f movement) override;
	 void attack() override;
	 void update(sf::Time elapsed) override;
	 void render(sf::RenderWindow* window) override;
	 void ninjaSide(sf::Vector2f mousePos);
	 //bouger
	
	 void stopX() override;
	 void stopY() override;
	 

	 void incrementJumped();
	 void resetJumped();
	 Sword* getSword();
	 void incrementNbKunai();
	 Kunai throwKunai();
	 int getNbkunai();
	 void setNbKunai(int nb);
	 void setMaxJump(int maxJump);

	 
private:
	void initTexture();
	int maxJump_;
	int jumped_;
	int nbKunai_;
	Sword sword_;
	Kunai kunai_;
	float countAttack;
	
	
};