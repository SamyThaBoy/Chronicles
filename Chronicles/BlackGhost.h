#pragma once
#include "Ennemy.h"
class BlackGhost :
    public Ennemy
{
public:
    BlackGhost();
    ~BlackGhost();

    void update(sf::Time elapsed);
    void render(sf::RenderWindow* window);
    void attack() override;
    void move(sf::Vector2f movement);
private:
    std::vector<sf::RectangleShape> deadAnimation;


};


