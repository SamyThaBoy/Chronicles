#include "Start.h"

Start::Start()
{

    play = false;
    shop = false;
    textureBackground.loadFromFile("game_background_4.png");
    background.setTexture(textureBackground);
    font.loadFromFile("Cardinal.ttf");
    playButton = Bouton(sf::Vector2f(850, 375), sf::Vector2f(130, 100));
    playButton.setButtonColor(sf::Color::Transparent);
    playButton.setFont("Cardinal.ttf");
    playButton.addText("play");
    playButton.setTextPolice(100);
    playButton.setTextColor(sf::Color(195, 54, 24, 255));

    shopButton = Bouton(sf::Vector2f(825, 525), sf::Vector2f(130, 100));
    shopButton.setButtonColor(sf::Color::Transparent);
    shopButton.setFont("Cardinal.ttf");
    shopButton.addText("shop");
    shopButton.setTextPolice(100);
    shopButton.setTextColor(sf::Color(195, 54, 24, 255));

    title.setFont(font);
    title.setString("Chronicles");
    title.setPosition(550, 100);
    title.setFillColor(sf::Color(187, 88, 47, 255));
    title.setCharacterSize(200);
    
   

}

Start::~Start()
{
}

void Start::update(sf::RenderWindow* window, sf::Time elapsed)
{
    pollEvents(window);

}


void Start::render(sf::RenderWindow* window)
{
	
	window->draw(background);
    playButton.render(window);
    shopButton.render(window);
    window->draw(title);
}

bool Start::clickPlay()
{
    return play;
}

void Start::setPlay(bool play)
{
    this->play = play;
}

bool Start::clickShop()
{
    return shop;
}

void Start::setShop(bool shop)
{
    this->shop = shop;
}

void Start::pollEvents(sf::RenderWindow* window)
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
       }
    }
}

void Start::checkClickButton()
{
    
    if (playButton.positionOnButton(mousePosView)) {
        play = true;
    }

    if (shopButton.positionOnButton(mousePosView)) {
        shop = true;
    }
   
}

void Start::checkHoverButton()
{
    if (playButton.positionOnButton(mousePosView)) {
        playButton.setTextColor(sf::Color::Black);
    }
    else {
        playButton.setTextColor(sf::Color(195, 54, 24, 255));
    }

    if (shopButton.positionOnButton(mousePosView)) {
        shopButton.setTextColor(sf::Color::Black);
    }
    else {
        shopButton.setTextColor(sf::Color(195, 54, 24, 255));
    }
}
