#pragma once
#include "Entity.h"
class LifePotion :
    public Entity
{
public:
    LifePotion();
    ~LifePotion();
    void update(sf::Time elapsed) override;
    void render(sf::RenderWindow* window) override;
    void setOnFloor(bool onFloor);
    bool isOnFloor();
private:
    sf::Texture texture_;
    bool onFloor;
};

