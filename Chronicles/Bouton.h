#pragma once
#include <SFML/Graphics.hpp>
class Bouton
{
public:
	Bouton();
	Bouton(sf::Vector2f position, sf::Vector2f size);
	~Bouton();
	bool addText(std::string txt);
	void setFont(std::string fontLocation);
	void setTextColor(sf::Color color);
	void setButtonColor(sf::Color color);
	void setTextPolice(int police);
	void setButtonSize(sf::Vector2f size);
	void setButtonPosition(sf::Vector2f position);
	void setTextPosition(sf::Vector2f position);
	void render(sf::RenderWindow* window);
	bool positionOnButton(sf::Vector2f pos);

private:
	sf::RectangleShape button;
	sf::Text buttonText;
	sf::Font font;
};

