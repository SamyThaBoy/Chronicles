#include "LifePotion.h"
#include "Physics.h"
LifePotion::LifePotion()
{
	speed_ = sf::Vector2f(0, 0);
	position_ = sf::Vector2f(-200, 0);
	width_ = 40;
	height_ = 40;
	weight_ = 1;
	onFloor = false;
	
	texture_.loadFromFile("lifePotion.png");
	sprite_.setTexture(texture_);
	box_.setSize(sf::Vector2f(width_, height_));
	box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
	sprite_.setPosition(box_.getPosition());
	sprite_.setScale(0.1, 0.1);
}

LifePotion::~LifePotion()
{
}

void LifePotion::update(sf::Time elapsed)
{
	if (!onFloor) {
		Physics::calculPosition(&speed_, &position_, weight_, elapsed);
	}
	else {
		Physics::calculPosition(&speed_, &position_);
	}
	box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
	sprite_.setPosition(position_.x - 3*width_/4 , position_.y - height_ / 2);
}

void LifePotion::render(sf::RenderWindow* window)
{

	window->draw(sprite_);
}

void LifePotion::setOnFloor(bool onFloor)
{
	this->onFloor = onFloor;
}

bool LifePotion::isOnFloor()
{
	return onFloor;
}
