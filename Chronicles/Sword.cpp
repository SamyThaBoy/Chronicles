#include "Sword.h"

Sword::Sword()
{
}

Sword::Sword(sf::Vector2f position, float width, float height)
{
	position_ = position;
	height_ = height;
	width_ = width;
	weight_ = 100;
	box_.setSize(sf::Vector2f(width_, height_));
	box_.setFillColor(sf::Color::Green);
	box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
}

Sword::~Sword()
{
}

void Sword::update(sf::Time elapsed)
{
}

void Sword::render(sf::RenderWindow* window)
{
	window->draw(box_);
}




