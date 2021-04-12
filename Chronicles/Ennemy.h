#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Character.h"
#include "Physics.h"
class Ennemy : public Character
{

	 

protected:
	void died() ;
	//caracteistique ennemi
	
	sf::Vector2f movementSpeed_;
	sf::Vector2f direction_;
	sf::Texture texture_;




};

