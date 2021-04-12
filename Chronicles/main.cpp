
#include <iostream>
#include "UIGestionnaire.h"


int main()
{
    //set up frame
    sf::RenderWindow* window;
    window = new sf::RenderWindow(sf::VideoMode(1800, 920),"");
    window->setFramerateLimit(60);
    UIGestionnaire gestionnaire;
    //set up time
    sf::Time elapsed;
    sf::Clock clock;
    std::srand(static_cast<unsigned>(time(NULL)));
 
 
   //boucle de run

    while (window->isOpen())
    {
        elapsed = clock.restart();
        window->clear();
        
        gestionnaire.update(window, elapsed);
        gestionnaire.render(window);
      
        window->display();
        
        
        
       
    }

    return 0;
}

