#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>

class Entity
{
public:
	virtual void update(sf::Time elapsed)=0 ;
	virtual void render(sf::RenderWindow* window) = 0;

	virtual sf::RectangleShape* getShape();
	virtual sf::Vector2f* getSpeed();
	virtual sf::Vector2f* getPosition();
	virtual float getWidth();
	virtual float getHeight();
	virtual float getWeight();
	virtual sf::Sprite* getSprite();

	virtual void setPosition(sf::Vector2<float> position);
	virtual void setPosition(float x, float y);
	virtual void setSpeed(sf::Vector2<float> vitesse);
	virtual void setSpeed(float x, float y);
	virtual void setShapeColor(sf::Color color);
	virtual void setWidth(float width) ;
	virtual void setHeight(float height);
	virtual void setWeight(float masse);
	virtual void setSprite(sf::Sprite sprite);

protected :
	sf::RectangleShape box_;
	sf::Vector2f speed_;
	sf::Vector2f position_;
	float width_ = 0;
	float height_=0;
	float weight_=0;
	sf::Sprite sprite_;
};

