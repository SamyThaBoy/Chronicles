#include "Entity.h"


float Entity::getWeight()
{
	return weight_;
}

sf::Sprite* Entity::getSprite()
{
	return &sprite_;
}

void Entity::setPosition(sf::Vector2<float> position)
{
	position_ = position;
	box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
}

void Entity::setPosition(float x, float y)
{
	position_ = sf::Vector2f(x, y);
	box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
}

void Entity::setSpeed(sf::Vector2<float> vitesse)
{
	speed_ = vitesse;
}

void Entity::setSpeed(float x, float y)
{
	speed_ = sf::Vector2f(x, y);
}

void Entity::setShapeColor(sf::Color color)
{
	box_.setFillColor(color);
}

void Entity::setWidth(float width)
{
	width_ = width;
	box_.setSize(sf::Vector2f(width_, height_));
	box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
}

void Entity::setHeight(float height)
{
	height_ = height;
	box_.setSize(sf::Vector2f(width_, height_));
	box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
}

void Entity::setWeight(float masse)
{
	weight_ = masse;
}

void Entity::setSprite(sf::Sprite sprite)
{
	sprite_ = sprite;
}

sf::RectangleShape* Entity::getShape()
{
	return &box_;
}

sf::Vector2f* Entity::getSpeed()
{
	return &speed_;
}

sf::Vector2f* Entity::getPosition()
{
	return &position_;
}

float Entity::getWidth()
{
	return width_;
}

float Entity::getHeight()
{
	return height_;
}
