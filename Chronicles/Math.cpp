#include "Math.h"

sf::Vector2f Math::unitVector(sf::Vector2f vecteur)
{
    return vecteur/std::sqrt(std::powf(vecteur.x,2)+ std::powf(vecteur.y,2));
}
