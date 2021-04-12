#include "Bouton.h"

Bouton::Bouton()
{
    buttonText.setFillColor(sf::Color::Black);
    button.setFillColor(sf::Color::White);
    button.setSize(sf::Vector2f(0, 60));
    button.setPosition(sf::Vector2f(0,0));
    buttonText.setPosition(sf::Vector2f(20, 40));
}

Bouton::Bouton(sf::Vector2f position, sf::Vector2f size)
{
    buttonText.setFillColor(sf::Color::Black);
    button.setFillColor(sf::Color::White);
    button.setSize(size);
    button.setPosition(position.x-20, position.y+20); 
    buttonText.setPosition(position);
    

}

Bouton::~Bouton()
{
}

bool Bouton::addText(std::string txt)
{
    if (buttonText.getFont() != nullptr) {
        buttonText.setString(txt);
        return true;
    }
    return false;
}

void Bouton::setFont(std::string fontLocation)
{
    font.loadFromFile(fontLocation);
    buttonText.setFont(font);
}

void Bouton::setTextColor(sf::Color color)
{
    buttonText.setFillColor(color);
}

void Bouton::setButtonColor(sf::Color color)
{
    button.setFillColor(color);
}

void Bouton::setTextPolice(int police)
{
    buttonText.setCharacterSize(police);
}

void Bouton::setButtonSize(sf::Vector2f size)
{
    button.setSize(size);
}

void Bouton::setButtonPosition(sf::Vector2f position)
{
    button.setPosition(position);
}

void Bouton::setTextPosition(sf::Vector2f position)
{
    buttonText.setPosition(position);
}

void Bouton::render(sf::RenderWindow* window)
{
    window->draw(button);
    window->draw(buttonText);
}

bool Bouton::positionOnButton(sf::Vector2f pos)
{
    if (pos.x>button.getPosition().x
        && pos.x < button.getPosition().x + button.getSize().x
        && pos.y>button.getPosition().y
        && pos.y < button.getPosition().y + button.getSize().y)
        return true;
    return false;
}
