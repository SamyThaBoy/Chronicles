#pragma once

#include "Character.h"
//interface des joueurs
class Player : public Character
{
public:

	
	virtual void stopX() = 0;
	virtual void stopY() = 0;
		
protected:

	float countTexture_;
	std::vector<sf::Texture> idleTexture_;
	std::vector<sf::Texture> jumpTexture_;
	std::vector<sf::Texture> attackTexture_;
	std::vector<sf::Texture> runTexture_;

	
	
};