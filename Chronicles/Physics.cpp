#include "Physics.h"

const float Physics::GRAVITY = 9.8;

sf::Vector2<float> Physics::calculForce(float masse)
{
	sf::Vector2<float> force;
	force.y= force.y+calculGravityForce(masse);
	return force;
}
sf::Vector2<float> Physics::calculAcceleration(sf::Vector2<float> force, float masse)
{
	sf::Vector2<float> acceleration;
	acceleration = force / masse;
	return acceleration;
}

int Physics::calculGravityForce(float masse)
{
	return Physics::GRAVITY * masse;
}

void Physics::calculSpeed(sf::Vector2<float> acceleration, sf::Vector2<float>* vitesse, const sf::Time timeBetweenLastRender)
{
	vitesse->x += acceleration.x * timeBetweenLastRender.asSeconds();
	vitesse->y += acceleration.y * timeBetweenLastRender.asSeconds();
}

	
void Physics::calculPosition(sf::Vector2<float>* vitesse, sf::Vector2<float>* position)
{
	position->x += vitesse->x;
	position->y += vitesse->y;
}
void Physics::calculPosition(sf::Vector2<float>* vitesse, sf::Vector2<float>* position, float masse, const  sf::Time timeBetweenLastRender)
{
	calculSpeed(calculAcceleration(calculForce(masse),masse), vitesse,timeBetweenLastRender);
	position->x += vitesse->x;
	position->y += vitesse->y;
}

bool Physics::collision(Entity& entity1, Entity& entity2)
{
	
	return(entity1.getShape()->getGlobalBounds().intersects(entity2.getShape()->getGlobalBounds()));

	
}



bool Physics::adjustPosition(Entity& entityToAdjust, Entity& reference)
{


	//faire abs ?
	//Haut
	int distanceYH = std::abs((reference.getPosition()->y - reference.getHeight()/2) - (entityToAdjust.getPosition()->y + entityToAdjust.getHeight()/2 )) ;
	//BAS
	int distanceYB = std::abs((reference.getPosition()->y + reference.getHeight() / 2) - (entityToAdjust.getPosition()->y - entityToAdjust.getHeight() / 2));

	//DROIT
	int distanceXD = std::abs((reference.getPosition()->x + reference.getWidth() / 2) - (entityToAdjust.getPosition()->x - entityToAdjust.getWidth() / 2));
	//GAUCHE
	int distanceXG = std::abs((reference.getPosition()->x - reference.getWidth() / 2) - (entityToAdjust.getPosition()->x + entityToAdjust.getWidth() / 2));
	
	int distance = std::min(distanceXD, std::min(distanceXG, std::min(distanceYB, distanceYH)));

	if (distanceYH == distance) { //plus petit distance YH
		entityToAdjust.setPosition(sf::Vector2f(entityToAdjust.getPosition()->x,entityToAdjust.getPosition()->y - distance ));
		entityToAdjust.setSpeed(entityToAdjust.getSpeed()->x,0);
		return true;
	}
	if (distanceYB == distance) { //plus petit distance YB
		entityToAdjust.setPosition(sf::Vector2f(entityToAdjust.getPosition()->x, entityToAdjust.getPosition()->y + distance));
		
	}
	if (distanceXD == distance) { //plus petit distance XD
		entityToAdjust.setPosition(sf::Vector2f(entityToAdjust.getPosition()->x + distance, entityToAdjust.getPosition()->y ));
	}
	if (distanceXG == distance) { //plus petit distance XG
		entityToAdjust.setPosition(sf::Vector2f(entityToAdjust.getPosition()->x - distance, entityToAdjust.getPosition()->y));
	}
	return false;
}



	