#pragma once
#include "UI.h"
#include"Bouton.h"
#include "ShopItem.h"
#include "SaveGame.h"
class Shop:public UI
{
public:
	Shop();
	~Shop();
	void update(sf::RenderWindow* window, sf::Time elapsed) override;
	void updateGold();
	void render(sf::RenderWindow* window) override;
	bool clickStart();
	void setStart(bool start);

private:
	void pollEvents(sf::RenderWindow* window) override;
	void checkClickButton();
	void checkHoverButton();


	std::vector<ShopItem*> items;
	Bouton back;
	sf::Text goldTxt;
	int gold;
	bool start;
	sf::Font font;
	
};

