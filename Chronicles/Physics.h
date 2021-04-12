#pragma once
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Physics
{
public:
	//calcul nouvelle poistion objet
	static void calculPosition(sf::Vector2<float>* vitesse, sf::Vector2<float>* position);

	static void calculPosition(sf::Vector2<float>* vitesse, sf::Vector2<float>* position, float masse, sf::Time timeBetweenLastRender);
	//vrai s'il y a une collision
	static bool collision(Entity& entity1, Entity& entity2);
	static bool adjustPosition(Entity& entityToAdjust, Entity& reference);

private:
	//acceleration physique
	static sf::Vector2<float> calculAcceleration(sf::Vector2<float> force, float masse);
	//force
	static int calculGravityForce(float masse);
	static sf::Vector2<float> calculForce(float masse);
	//vitesse perso
	static void calculSpeed(sf::Vector2<float> acceleration, sf::Vector2<float>* vitesse, const sf::Time timeBetweenLastRender);
	//variable
	static const float GRAVITY;
};