#pragma once
#include "Entity.h"
class Terrain:public Entity
{
public:
	//constructeur/destructeur
	Terrain(sf::Vector2f position, float width, float height);
	Terrain(sf::Vector2f position, float width, float height,sf::Texture& texture);
	~Terrain();

	void update(sf::Time elapsed) override;
	void render(sf::RenderWindow* window) override;

	
private:
	sf::Sprite sprite_;
};