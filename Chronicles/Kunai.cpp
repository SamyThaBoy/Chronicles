#include "Kunai.h"

Kunai::Kunai()
{

	speed_ = sf::Vector2f(0,0);
	position_= sf::Vector2f(0,0);
	width_ = 10;
	height_ =40;
	weight_ = 10;
	onFloor = false;
	texture_ = *new sf::Texture();
	texture_.loadFromFile("Kunai.png");
	sprite_. setTexture(texture_);
	box_.setSize(sf::Vector2f(width_, height_));
	box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
	sprite_.setPosition(box_.getPosition());
	sprite_.setScale(0.25, 0.25);
	
}



Kunai::~Kunai()
{
}

void Kunai::update(sf::Time elapsed)
{
	if (!onFloor) {
		Physics::calculPosition(&speed_, &position_, weight_, elapsed);
	}
	else {
		Physics::calculPosition(&speed_, &position_);
	}
	box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
	sprite_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
}

void Kunai::render(sf::RenderWindow* window)
{
	
	window->draw(sprite_);
	
}

void Kunai::setOnFloor(bool onFloor)
{
	this->onFloor = onFloor;
}

bool Kunai::isOnFloor()
{
	return onFloor;
}
