#include "Ninja.h"
#include "Physics.h"
#include <iostream>

	 
	Ninja::Ninja()
	{
		
		attack_ =5;
		lifeMax_ = 50;
		life_ = lifeMax_;
		jumped_ = 0;
		nbKunai_ = 0;
		onFloor_ = false;
		weight_ = 70;
		speed_ = sf::Vector2f(0.f, 0.f);
		position_ = sf::Vector2f(500.f, 500.f);
		height_ = 80;
		width_ = 40;
		countAttack = 0;
		maxJump_ = 1;
		sword_ = Sword(position_, width_,height_);
		box_.setSize(sf::Vector2f(width_,height_));
		box_.setFillColor(sf::Color::White);
		box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
		initTexture();
		sprite_.setTexture(idleTexture_[0]);
		
		sprite_.setScale(sf::Vector2f(width_/idleTexture_[0].getSize().x, height_ / idleTexture_[0].getSize().y));

	
		kunai_.getSprite()->setOrigin(sf::Vector2f(kunai_.getWidth() / 2, kunai_.getHeight() / 2));
		kunai_.setHeight(10);
		kunai_.setWidth(40);
	


	}
	void Ninja::initTexture()
	{
		countTexture_ = 0;
		for (int i = 0; i < 10; i++) {
			idleTexture_.push_back(*new sf::Texture());
			idleTexture_[i].loadFromFile("Idle/Idle__00" + std::to_string(i) + ".png");
		}
		for (int i = 0; i < 10; i++) {
			jumpTexture_.push_back(*new sf::Texture());
			jumpTexture_[i].loadFromFile("jump/Jump__00" + std::to_string(i) + ".png");
		}
		for (int i = 0; i < 10; i++) {
			attackTexture_.push_back(*new sf::Texture());
			attackTexture_[i].loadFromFile("attack/Attack__00" + std::to_string(i) + ".png");
		}
		for (int i = 0; i < 10; i++) {
			runTexture_.push_back(*new sf::Texture());
			runTexture_[i].loadFromFile("run/Run__00" + std::to_string(i) + ".png");
		}
	}
	
	Ninja::~Ninja() 
	{

	}
	
	
	void Ninja::attack()
	{
		if (attacked_ != true) {
			attacked_ = true;
			countTexture_ = 0;
		}
			}

	void Ninja::update(sf::Time elapsed)
	{
	

		if (!onFloor_) {
			Physics::calculPosition(&this->speed_, &this->position_, this->weight_, elapsed);
		}
		else {
			Physics::calculPosition(&this->speed_, &this->position_);
		}
		box_.setPosition(position_.x - width_ / 2, position_.y - height_ / 2);
	
		
		//Texture
		if (speed_.x > 0) {
			if (sprite_.getScale().x < 0) {
				sprite_.setPosition(sf::Vector2f(box_.getPosition().x + width_, box_.getPosition().y));
				countTexture_ -= 12 * elapsed.asSeconds();
				if (countTexture_ < 0)countTexture_ = 9;
			}
			else {
				sprite_.setPosition(sf::Vector2f(box_.getPosition().x, box_.getPosition().y));
				countTexture_ += 12 * elapsed.asSeconds();
				if (countTexture_ > 10)countTexture_ = 0;
			}
		}
		else {
			if (sprite_.getScale().x < 0) {
				sprite_.setPosition(sf::Vector2f(box_.getPosition().x + width_, box_.getPosition().y));
				countTexture_ += 12 * elapsed.asSeconds();
				if (countTexture_ > 10)countTexture_ = 0;
			}
			else {
				sprite_.setPosition(sf::Vector2f(box_.getPosition().x, box_.getPosition().y));
				countTexture_ -= 12 * elapsed.asSeconds();
				if (countTexture_ < 0)countTexture_ = 9;
			}
		}
		

		if (!attacked_) {
				
			if (speed_.x == 0 && speed_.y == 0) {
				sprite_.setTexture(idleTexture_[(int)countTexture_], true);
				
			}
			else {
				if (speed_.y != 0) {
					sprite_.setTexture(jumpTexture_[(int)countTexture_], true);

				}
				else {
					sprite_.setTexture(runTexture_[(int)countTexture_], true);
	
				}
			}
			
		}
		else {
			sprite_.setTexture(attackTexture_[(int)countAttack], true);
			if (sprite_.getScale().x<0) {
				sword_.setPosition(sf::Vector2f(position_.x - 3*width_/2 , position_.y - height_ / 2));
			}
			else {
				
				sword_.setPosition(sf::Vector2f(position_.x + width_ , position_.y - height_ / 2));
			}
			if (countAttack > 9) {
				attacked_ = false;
				countAttack = 0; 
			}
			else {
				countAttack+= 0.25;
			}
		}
	
	
		
		
	
	
	}
	//afffiche le ninja
	void Ninja::render(sf::RenderWindow* window)
	{
		//window->draw(box_);
		window->draw(sprite_);
		
	}

	void Ninja::ninjaSide(sf::Vector2f mousePos)
	{
		if (mousePos.x < position_.x) {
			sprite_.setScale(-std::abs(sprite_.getScale().x), sprite_.getScale().y);
		}
		
		if (mousePos.x > position_.x) {
			sprite_.setScale(std::abs(sprite_.getScale().x), sprite_.getScale().y);
		}
		
	}


	void Ninja::move(sf::Vector2f movement)
	{
	
		if (movement.y < 0) {
			if (jumped_ < maxJump_) {
				speed_ = movement;
				jumped_++;
				onFloor_ = false;
			}
			else {
				speed_.x = movement.x;
			}
		}
		else {
			speed_ = movement;
		}
	}


	void Ninja::stopX()
	{
		speed_.x = 0;
	}

	void Ninja::stopY()
	{
		speed_.y = 0;
	}


	void Ninja::incrementJumped()
	{
		this->jumped_ ++;
	}

	void Ninja::resetJumped()
	{
		this->jumped_ = 0;
	}


	Sword* Ninja::getSword()
	{
		return &sword_;
	}

	void Ninja::incrementNbKunai()
	{
		nbKunai_++;
	}

	Kunai Ninja::throwKunai()
	{	
		
		
		
		
		kunai_.setPosition(position_);
		
		
		if (sprite_.getScale().x < 0) {
			kunai_.getSprite()->setRotation(-90);
			kunai_.setSpeed(sf::Vector2f(-30,0));
		}
		else {
			kunai_.getSprite()->setRotation(90);
			kunai_.setSpeed(sf::Vector2f(30, 0));
		}
		
		//changerOrientation kunai
		return kunai_;
	}

	int Ninja::getNbkunai()
	{
		return nbKunai_;
	}

	void Ninja::setNbKunai(int nb)
	{
		nbKunai_ = nb;
	}

	void Ninja::setMaxJump(int maxJump)
	{
		maxJump_ = maxJump;
	}

	

	

	



	
	
