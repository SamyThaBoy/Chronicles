#include "ShopItem.h"


ShopItem::ShopItem()
{
    sold = false;
    itemBoundary.setFillColor(sf::Color(229, 193, 153));
    itemBoundary.setOutlineThickness(1);
    itemBoundary.setOutlineColor(sf::Color::Black);
    button.setTextColor(sf::Color::Black);
    button.setButtonColor(sf::Color::White);
    button.setButtonSize(sf::Vector2f(0, 60));
    width = 0;
    height = 0;
}

ShopItem::~ShopItem()
{
}

bool ShopItem::addItemText(std::string txt)
{
    if (itemDescription.getFont() != nullptr) {
        itemDescription.setString(txt);
        return true;
    }
    return false;
    
}

void ShopItem::setFont(std::string fontLocation)
{
    font.loadFromFile(fontLocation);
    button.setFont(fontLocation);
    itemDescription.setFont(font);
    character.setFont(font);
}

void ShopItem::setTextColor(sf::Color color)
{
    character.setFillColor(color);
    itemDescription.setFillColor(color);
    button.setTextColor(color);
}

void ShopItem::setTextPolice(int police)
{
    character.setCharacterSize(police);
    itemDescription.setCharacterSize(police);
    button.setTextPolice(police);
}

void ShopItem::setBoxSize(sf::Vector2f size)
{
    width = size.x;
    height = size.y;
    itemBoundary.setSize(size);
    button.setButtonSize(sf::Vector2f(width-10, height / 5));
}

void ShopItem::setItemPosition(sf::Vector2f position)
{
    itemBoundary.setPosition(position);
    itemDescription.setPosition(position.x, position.y + height / 3);
    character.setPosition(position.x, position.y + 10);
    button.setButtonPosition(sf::Vector2f(position.x+5, position.y + height -40));
    button.setTextPosition(sf::Vector2f(position.x + width/4, position.y + height - 40));
}

bool ShopItem::setCharacter(std::string txt)
{
    if (character.getFont() != nullptr) {
        character.setString(txt);
        return true;
    }
    return false;
}

bool ShopItem::setPrice(int price)
{
    this->price = price;
    if (button.addText(std::to_string(price)+ " golds")) {
        
        return true;
    }
    return false;
}

void ShopItem::render(sf::RenderWindow* window)
{
    window->draw(itemBoundary);
    window->draw(itemDescription);
    window->draw(character);
    button.render(window);
}

bool ShopItem::onButton(sf::Vector2f pos)
{
    return button.positionOnButton(pos);
}

Bouton* ShopItem::getBouton()
{
	return &button;
}

int ShopItem::getPrice()
{
    return price;
}

void ShopItem::setSold(bool sold)
{
    this->sold = sold;
    button.addText("sold");
}

bool ShopItem::isSold()
{
    return sold;
}
