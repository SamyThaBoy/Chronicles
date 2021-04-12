#pragma once

#include "UI.h"
#include <iostream>
#include"Bouton.h"
class Start: public UI
{
public:
	Start();
	~Start();
	void update(sf::RenderWindow* window, sf::Time elapsed) override;
	void render(sf::RenderWindow* window) override;
	bool clickPlay();
	void setPlay(bool play);
	bool clickShop();
	void setShop(bool shop);

private:
	void pollEvents(sf::RenderWindow* window) override;
	void checkClickButton();
	void checkHoverButton();



	Bouton playButton;
	Bouton shopButton;
	sf::Text title;
	sf::Font font;
	bool play;
	bool shop;

	


};

