#include "Ennemy.h"

void Ennemy::died()
{
	if(timerAnimationDead.getElapsedTime() > sf::seconds(1))
	position_ = (sf::Vector2f(0, 5000));
}
