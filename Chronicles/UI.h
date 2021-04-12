#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class UI
{
public:
	virtual void update(sf::RenderWindow* window, sf::Time elapsed)=0;
	virtual void render(sf::RenderWindow* window)=0;
protected:
	virtual void pollEvents(sf::RenderWindow* window)=0;
	sf::Texture textureBackground;
	sf::Sprite background;
	sf::Event event;
	sf::Vector2i mousePos;
	sf::Vector2f mousePosView;
};

