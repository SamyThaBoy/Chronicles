#pragma once
#include "Entity.h"
class Character :
    public Entity
{
public:
	virtual void attack()=0;
	virtual void move(sf::Vector2f movement)=0;
	/*pt devoir mettre un move X et move Y*/
	virtual void setOnFloor(bool onFloor);
	virtual bool asAttack();
	virtual void enleverLife(int life);
	virtual int getLife();
	virtual void setLife(int life);
	virtual int getAttack();
	virtual bool isDead();
protected:
	sf::Clock timerAnimationDead;
	int attack_ = 0;
	int life_ = 0;
	int lifeMax_ = 0;
	
	bool onFloor_;
	bool attacked_;
	bool dead = false;

};

