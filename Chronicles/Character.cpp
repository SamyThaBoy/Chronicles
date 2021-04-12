#include "Character.h"

void Character::setOnFloor(bool onFloor)
{
	onFloor_ = onFloor;
}

bool Character::asAttack()
{
	return attacked_;
}

void Character::enleverLife(int life)
{
	life_ -= life;
	if (life_ <= 0) dead = true;
	timerAnimationDead.restart();
}

int Character::getLife()
{
	return life_;
}

void Character::setLife(int life)
{
	life_ = life;
}

int Character::getAttack()
{
	return attack_;
}

bool Character::isDead()
{
	return dead;
}
