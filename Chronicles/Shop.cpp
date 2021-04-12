#include "Shop.h"

Shop::Shop()
{
    SaveGame::load();
    start = false;
    gold = SaveGame::getGold();
    textureBackground.loadFromFile("shop_background.png");
    background.setTexture(textureBackground);
    background.setScale(sf::Vector2f(2200/textureBackground.getSize().x, 1200/textureBackground.getSize().y));
  
    font.loadFromFile("Cardinal.ttf");
    back = Bouton(sf::Vector2f(10, 0), sf::Vector2f(130, 100));
    back.setButtonColor(sf::Color::Transparent);
    back.setFont("Cardinal.ttf");
    back.addText("back");
    back.setTextPolice(100);
    back.setTextColor(sf::Color(195, 54, 24, 255));

    goldTxt.setFont(font);
    goldTxt.setCharacterSize(100);
    goldTxt.setFillColor(sf::Color(195, 54, 24, 255));
    goldTxt.setString("Gold: "+std::to_string(gold));
    goldTxt.setPosition(sf::Vector2f(1350, 0));


    items.push_back(new ShopItem());
    items[0]->setFont("Cardinal.ttf");
    items[0]->addItemText("double jump");
    items[0]->setCharacter("Ninja :");
    items[0]->setPrice(10);
    items[0]->setBoxSize(sf::Vector2f(200, 150)); 
    items[0]->setItemPosition(sf::Vector2f(150, 150));
    items[0]->setTextPolice(20);
    items[0]->setTextColor(sf::Color::Black);
    //regarder si deja sold
    if (SaveGame::getjump() > 1) {
        items[0]->setSold(true);
    }

    items.push_back(new ShopItem());
    items[1]->setFont("Cardinal.ttf");
    items[1]->addItemText("increase mov. speed");
    items[1]->setCharacter("Ninja :");
    items[1]->setPrice(10);
    items[1]->setBoxSize(sf::Vector2f(200, 150));
    items[1]->setItemPosition(sf::Vector2f(360, 150));
    items[1]->setTextPolice(20);
    items[1]->setTextColor(sf::Color::Black);
    if (SaveGame::getXSpeed() > 5) {
        items[1]->setSold(true);
    }


    items.push_back(new ShopItem());
    items[2]->setFont("Cardinal.ttf");
    items[2]->addItemText("unlock kunai drop");
    items[2]->setCharacter("Ninja :");
    items[2]->setPrice(10);
    items[2]->setBoxSize(sf::Vector2f(200, 150));
    items[2]->setItemPosition(sf::Vector2f(570, 150));
    items[2]->setTextPolice(20);
    items[2]->setTextColor(sf::Color::Black);
    if (SaveGame::getKunaiDrop()) {
        items[2]->setSold(true);
    }

    items.push_back(new ShopItem());
    items[3]->setFont("Cardinal.ttf");
    items[3]->addItemText("unlock life potion drop");
    items[3]->setCharacter("Survival :");
    items[3]->setPrice(10);
    items[3]->setBoxSize(sf::Vector2f(200, 150));
    items[3]->setItemPosition(sf::Vector2f(780, 150));
    items[3]->setTextPolice(20);
    items[3]->setTextColor(sf::Color::Black);
    if (SaveGame::getPotionDrop()) {
        items[3]->setSold(true);
    }
    /*
    items.push_back(new ShopItem());
    items[4]->setFont("Cardinal.ttf");
    items[4]->addItemText("unlock bomb drop");
    items[4]->setCharacter("Survival :");
    items[4]->setPrice(10);
    items[4]->setBoxSize(sf::Vector2f(200, 150));
    items[4]->setItemPosition(sf::Vector2f(990, 150));
    items[4]->setTextPolice(20);
    items[4]->setTextColor(sf::Color::Black);
    */
}

Shop::~Shop()
{
}

void Shop::update(sf::RenderWindow* window, sf::Time elapsed)
{
    pollEvents(window);
}

void Shop::updateGold()
{
    gold = SaveGame::getGold();
    goldTxt.setString("Gold: " + std::to_string(gold));
}

void Shop::render(sf::RenderWindow* window)
{
    window->draw(background);
    back.render(window);
    window->draw(goldTxt);
    for (int i = 0; i < items.size(); i++) {
            items[i]->render(window);  
    }
}

bool Shop::clickStart()
{
    return start;
}

void Shop::setStart(bool start)
{
    this->start = start;
}



void Shop::pollEvents(sf::RenderWindow* window)
{
    while (window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
            //close game
        case sf::Event::Closed:
            window->close();
            break;

        case sf::Event::MouseButtonPressed:
            this->mousePos = sf::Mouse::getPosition(*window);
            this->mousePosView = window->mapPixelToCoords(this->mousePos);
            checkClickButton();
            break;
        case sf::Event::MouseMoved:
            this->mousePos = sf::Mouse::getPosition(*window);
            this->mousePosView = window->mapPixelToCoords(this->mousePos);
            checkHoverButton();
            break;
        }
    }
}

void Shop::checkClickButton()
{
    if (back.positionOnButton(mousePosView)) {
        start = true;
    }
    for (int i = 0; i < items.size();i++) {
        if (items[i]->onButton(mousePosView)) {
            if (!items[i]->isSold() && gold >=items[i]->getPrice()) {
                items[i]->setSold(true);
                gold -= items[i]->getPrice();
                goldTxt.setString("Gold: " + std::to_string(gold));
                SaveGame::setGold(gold);
                


                switch (i) {
                case 0:
                    SaveGame::setjump(2);
                    break;
                case 1:
                    SaveGame::setXSpeed(8);
                    break;
                case 2:
                    SaveGame::setKunaiDrop(true);
                    break;
                case 3:
                    SaveGame::setPotionDrop(true);
                default:
                    break;
                }
                SaveGame::save();
            }
        }
    }
}

void Shop::checkHoverButton()
{
    if (back.positionOnButton(mousePosView)) {
        back.setTextColor(sf::Color::Black);
    }
    else {
        back.setTextColor(sf::Color(195, 54, 24, 255));
    }

    for (int i = 0; i < items.size(); i++) {
        if (items[i]->onButton(mousePosView)) {
            items[i]->getBouton()->setTextColor(sf::Color(195, 54, 24, 255));
        }
        else {
            items[i]->getBouton()->setTextColor(sf::Color::Black);
        }
    }
}
