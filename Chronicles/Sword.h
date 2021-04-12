#pragma once
#include "Weapon.h"
class Sword :
    public Weapon
{
public:
	Sword();
	Sword(sf::Vector2f position, float width, float height);
	~Sword();
	void update(sf::Time elapsed) override;
	void render(sf::RenderWindow* window) override;
};

