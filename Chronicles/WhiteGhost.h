#pragma once
#include "Ennemy.h"
class WhiteGhost :
    public Ennemy
{
public:
        WhiteGhost();
        ~WhiteGhost();

        void update(sf::Time elapsed);
        void render(sf::RenderWindow* window);
        void attack() override;
        void move(sf::Vector2f movement);
private:
    std::vector<sf::RectangleShape> deadAnimation;

        
};

