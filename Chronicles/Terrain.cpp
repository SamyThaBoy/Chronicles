#include "Terrain.h"
Terrain::Terrain(sf::Vector2f position,float width, float height)
{


	position_ = position;
	height_ = height;
	width_ = width;
	weight_ = 100;
	box_.setSize(sf::Vector2f(width_, height_));
	box_.setFillColor(sf::Color::Green);
	box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);


}
Terrain::Terrain(sf::Vector2f position, float width, float height, sf::Texture& texture)
{
	position_ = position;
	height_ = height;
	width_ = width;
	weight_ = 100;
	box_.setSize(sf::Vector2f(width_, height_));
	box_.setFillColor(sf::Color::Green);
	box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
	sprite_.setTexture(texture);
	sprite_.setPosition(box_.getPosition());
	sprite_.setColor(sf::Color(61, 56, 207, 255));
	sprite_.setTextureRect(sf::IntRect(position_.x - width_ / 2, position_.y - height_ / 2, width_, height_));
}
Terrain::~Terrain()
{
}

void Terrain::update(sf::Time elapsed)
{
}

void Terrain::render(sf::RenderWindow* window)
{
	window->draw(sprite_);
}

