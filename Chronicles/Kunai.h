#pragma once
#include "Weapon.h"
#include "Physics.h"
class Kunai :
    public Weapon
{
public:
    Kunai();
    ~Kunai();
    void update(sf::Time elapsed) override;
    void render(sf::RenderWindow* window) override;
    void setOnFloor(bool onFloor);
    bool isOnFloor();
private:
    sf::Texture texture_;
    bool onFloor;
};

