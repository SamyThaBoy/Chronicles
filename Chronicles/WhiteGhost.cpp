#include "WhiteGhost.h"

WhiteGhost::WhiteGhost()
{


	texture_.loadFromFile("ghost.png");
	height_ = texture_.getSize().y / 8;
	width_ = texture_.getSize().x / 12;
	speed_ = sf::Vector2f(0.f, 0.f);
	position_ = sf::Vector2f(200.f, 200.f);
	box_.setFillColor(sf::Color::Red);
	box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
	box_.setSize(sf::Vector2f(width_, height_));
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(
		texture_.getSize().x * 9 / 12, texture_.getSize().y / 8, texture_.getSize().x / 12, texture_.getSize().y / 8));
	sprite_.setPosition(box_.getPosition());
	
	weight_ = 60;
	attack_ =5;
	lifeMax_ = 1;
	life_ = lifeMax_;
	onFloor_ = false;
	attacked_= false;
	movementSpeed_ = sf::Vector2f(2.f, 2.f);

	for (int i = 0; i < 6; i++) {
		sf::RectangleShape rect;
		rect.setPosition(position_.x , position_.y - height_/4);
		rect.setSize(sf::Vector2f(3, 6));
		rect.setOrigin(sf::Vector2f(0, -height_ / 4));
		rect.rotate(60 * i);
		rect.setFillColor(sf::Color::White);
		deadAnimation.push_back(rect);
	}

}

WhiteGhost::~WhiteGhost()
{
}

void WhiteGhost::update(sf::Time elapsed)
{
	if (!dead) {
		Physics::calculPosition(&this->speed_, &this->position_);

		box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
		if (speed_.x < 0) {
			sprite_.setTextureRect(sf::IntRect(
				texture_.getSize().x * 9 / 12, texture_.getSize().y / 8, texture_.getSize().x / 12, texture_.getSize().y / 8));
		}
		if (speed_.x > 0) {
			sprite_.setTextureRect(sf::IntRect(
				texture_.getSize().x * 9 / 12, texture_.getSize().y * 2 / 8, texture_.getSize().x / 12, texture_.getSize().y / 8));
		}
		if (speed_.x == 0) {
			sprite_.setTextureRect(sf::IntRect(
				texture_.getSize().x * 9 / 12, 0, texture_.getSize().x / 12, texture_.getSize().y / 8));
		}
		sprite_.setPosition(box_.getPosition());
	}
}

void WhiteGhost::render(sf::RenderWindow* window)
{
	
	if (this->dead) {
		died();
		for (auto& rect : deadAnimation) {
			rect.setPosition(position_.x, position_.y - height_ / 4);
			window->draw(rect);
		}
	}
	else {
	
		window->draw(sprite_);
	}
}

void WhiteGhost::attack()
{
	
}



void WhiteGhost::move(sf::Vector2f movement)
{
	direction_ = Math::unitVector(movement - position_);

	this->speed_.x = direction_.x * movementSpeed_.x;
	this->speed_.y = direction_.y * movementSpeed_.y;
}
