#pragma once
#include "SFML/Graphics.hpp"
#include "Start.h"
#include "Survival.h"
#include "Shop.h"

enum Page
{
	start,
	shop,
	survival
};

class UIGestionnaire
{
public: 
	UIGestionnaire();
	~UIGestionnaire();
	void update(sf::RenderWindow* window, sf::Time elapsed);
	void render(sf::RenderWindow* window);
private:
	Start start;
	Survival survival;
	Shop shop;
	Page current;
};

