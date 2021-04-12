#pragma once
#include "Bouton.h"

class ShopItem
{
public:
	ShopItem();
	~ShopItem();
	bool addItemText(std::string txt);
	void setFont(std::string fontLocation);
	void setTextColor(sf::Color color);
	void setTextPolice(int police);
	void setBoxSize(sf::Vector2f size);
	void setItemPosition(sf::Vector2f position);
	bool setCharacter(std::string txt);
	bool setPrice(int price);
	void render(sf::RenderWindow* window);
	bool onButton(sf::Vector2f pos);
	Bouton* getBouton();
	int getPrice();
	void setSold(bool sold);
	bool isSold();
private:
	Bouton button;
	sf::Font font;
	sf::Text itemDescription;
	sf::Text character;
	sf::RectangleShape itemBoundary;
	bool sold;
	int price;
	float width;
	float height;
};

