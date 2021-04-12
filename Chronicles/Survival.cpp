#include "Survival.h"

#include <iostream>
Survival::Survival()
    :whiteGhostTimerMax(level.getWhiteGhostTimerMax()),
    numberWhiteSpawn(level.getNumberWhiteSpawn()),
    blackGhostTimerMax (level.getBlackGhostTimerMax()),
    numberBlackSpawn (level.getNumberBlackSpawn())
{
    menu = false;
    this->score = 0;
    
    whiteGhostTimer = sf::seconds(0);
    blackGhostTimer = sf::seconds(0);
    std::vector<Ennemy*> ennemies;
    killedEnnemies = 0;
    textureBackground.loadFromFile("game_background_3_2.png");
    background.setTexture(textureBackground);
    pause = false;
    bufferMusic.loadFromFile("Naruto.wav");
    music.setBuffer(bufferMusic);
    music.setLoop(true);
    kunaiDrop.setPosition(-200, 200);
    lifePotionDrop.setPosition(-200, 200);
    
    if (SaveGame::load()) {
       
        highScore = SaveGame::getHighScore();
        ninjaXSpeed = SaveGame::getXSpeed();
        ninja.setMaxJump(SaveGame::getjump());
        kunaiAvailable = SaveGame::getKunaiDrop();
        potionAvailable = SaveGame ::getPotionDrop();
    }
    else {
        highScore = 0;
        ninjaXSpeed = 5;
        kunaiAvailable = false;
        potionAvailable = false;
    }
    
    initAffichage();
}


Survival::~Survival()
{
	
}

void Survival::initAffichage()
{
    textFont.loadFromFile("Cardinal.ttf");
    displayScore.setFont(textFont);
    displayScore.setString(std::to_string(0));
    displayScore.setCharacterSize(40);
    displayScore.setPosition(sf::Vector2f(40, 0));
    displayScore.setFillColor(sf::Color(187, 88, 47, 255));
    displayLevel.setFont(textFont);
    displayLevel.setString(std::to_string(0));
    displayLevel.setCharacterSize(40);
    displayLevel.setPosition(sf::Vector2f(1650, 0));
    displayLevel.setFillColor(sf::Color(187, 88, 47, 255));
    allLevelClear.setFont(textFont);
    allLevelClear.setString(std::to_string(0));
    allLevelClear.setCharacterSize(100);
    allLevelClear.setPosition(sf::Vector2f(500, 200));
    allLevelClear.setFillColor(sf::Color(187, 88, 47, 255));
    displayLife.setFont(textFont);
    displayLife.setString("life: " + std::to_string((int)ninja.getLife()));
    displayLife.setCharacterSize(40);
    displayLife.setPosition(sf::Vector2f(1650, 850));
    displayLife.setFillColor(sf::Color(187, 88, 47, 255));
    displayNbKunai.setFont(textFont);
    displayNbKunai.setPosition(sf::Vector2f(0, 850));
    displayNbKunai.setFillColor(sf::Color(187, 88, 47, 255));
    displayNbKunai.setCharacterSize(40);
    displayNbKunai.setString(" number kunai: " + std::to_string(ninja.getNbkunai()));
    displayHighScore.setFont(textFont);
    displayHighScore.setString(std::to_string(0));
    displayHighScore.setCharacterSize(40);
    displayHighScore.setPosition(sf::Vector2f(750, 550));
    displayHighScore.setString("High Score: " + std::to_string(highScore));
    displayHighScore.setFillColor(sf::Color(187, 88, 47, 255));
    displayGold.setFont(textFont);
    displayGold.setString(std::to_string(0));
    displayGold.setFillColor(sf::Color(187, 88, 47, 255));
    buttonRetry = Bouton(sf::Vector2f(700, 375), sf::Vector2f(450, 100));
    buttonRetry.setButtonColor(sf::Color::Transparent);
    buttonRetry.setFont("Cardinal.ttf");
    buttonRetry.addText("try again");
    buttonRetry.setTextPolice(100);
    buttonRetry.setTextColor(sf::Color(195, 54, 24, 255));
    buttonMenu = Bouton(sf::Vector2f(10, 0), sf::Vector2f(450, 100));
    buttonMenu.setButtonColor(sf::Color::Transparent);
    buttonMenu.setFont("Cardinal.ttf");
    buttonMenu.addText("menu");
    buttonMenu.setTextPolice(100);
    buttonMenu.setTextColor(sf::Color(195, 54, 24, 255));
    displayTimer.setFont(textFont);
    displayTimer.setPosition(sf::Vector2f(700, 850));
    displayTimer.setFillColor(sf::Color(187, 88, 47, 255));
    displayTimer.setCharacterSize(40);
    displayTimer.setString(" remaining Time: " + std::to_string(levelTime.getElapsedTime().asSeconds()));
    ennemiesToKill.setFont(textFont);
    ennemiesToKill.setPosition(sf::Vector2f(700, 0));
    ennemiesToKill.setFillColor(sf::Color(195, 54, 24, 255));
    ennemiesToKill.setCharacterSize(40);
    ennemiesToKill.setString("ennemies to kill:");
}


void Survival::pollEvents(sf::RenderWindow* window)
{
    while (window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
            //close game
        case sf::Event::Closed:
                window->close();
                break;
             //avancer joueur
        case sf::Event::KeyPressed:

            if (this->event.key.code == sf::Keyboard::D) {
                this->ninja.move(sf::Vector2f(ninjaXSpeed, ninja.getSpeed()->y));

            }
            if (this->event.key.code == sf::Keyboard::A) {
                this->ninja.move(sf::Vector2f(-ninjaXSpeed, ninja.getSpeed()->y));

            }
            if (this->event.key.code == sf::Keyboard::W) {
                this->ninja.move(sf::Vector2f(ninja.getSpeed()->x, -8));

            }
            if (this->event.key.code == sf::Keyboard::S) {
                this->ninja.move(sf::Vector2f(ninja.getSpeed()->x, 10));

            }
          //  if (this->event.key.code == sf::Keyboard::Space) {
             //  pause = true;

           // }
          
            break;
        case sf::Event::MouseButtonPressed:
            if (this->event.key.code == sf::Mouse::Button::Left) {
                ninja.attack();
                if (pause && buttonRetry.positionOnButton(mousePosView)) {
                    retry();
                } 
                if (pause && buttonMenu.positionOnButton(mousePosView)) {
                    menu = true;
                }
            }
            if (this->event.key.code == sf::Mouse::Button::Right) {

                if (ninja.getNbkunai() > 0) {
                    throwedKunai.push_back(ninja.throwKunai());
                    ninja.setNbKunai(ninja.getNbkunai() - 1);
                    displayNbKunai.setString(" nombre kunai: " + std::to_string(ninja.getNbkunai()));
                }
            }

            break;

            //arreter de bouger
        case sf::Event::KeyReleased:
            if ((this->event.key.code == sf::Keyboard::D) && ninja.getSpeed()->x > 0) {
                this->ninja.stopX();
            }
            if ((this->event.key.code == sf::Keyboard::A) && ninja.getSpeed()->x < 0) {
                this->ninja.stopX();
            }
            
            if ((this->event.key.code == sf::Keyboard::S) && ninja.getSpeed()->y > 0) {
                this->ninja.stopY();
            }
            if ((this->event.key.code == sf::Keyboard::W) && ninja.getSpeed()->y < 0) {
                this->ninja.stopY();
            }
            break;
        }
    }
}


void Survival::updateEnnemies(sf::RenderWindow* window,  sf::Time elapsed)
{
     
        whiteGhostTimer += elapsed;
        blackGhostTimer += elapsed;
        //compteur spwan ennemi
        if (this->whiteGhostTimer >= this->whiteGhostTimerMax)
        {
            this->whiteGhostTimer = sf::seconds(0.f);

            for (int i = 0; i < numberWhiteSpawn; i++) {
                this->spawnWhiteEnnemy(window);
            }            
        }

        if (this->blackGhostTimer >= this->blackGhostTimerMax)
        {
            this->blackGhostTimer = sf::seconds(0.f);

            for (int i = 0; i < numberBlackSpawn; i++) {
                this->spawnBlackEnnemy(window);
            }
        }

    //bouge l'ennemi
    for(int i = 0 ; i<ennemies.size();i++ )
    {
         ennemies.at(i)->move(*ninja.getPosition());
        if (ennemies.at(i)->getPosition()->y > 920){
            ennemies.erase(ennemies.begin() + i);
        }
        else {
            ennemies.at(i)->update(elapsed);
        }
    }  

    //cheker si niveaux fini
    if (levelTime.getElapsedTime() > level.getTimeRestriction()) {
        allLevelClear.setString("");
        endGame();
    }
    
    if (killedEnnemies >= level.getEnnemiesObjectives()) {
        if (level.getLevel() == level.getLevelmax()) {
            allLevelClear.setString("You have cleared all level");
            endGame();
        }
        level.levelClear();
        killedEnnemies = 0;
       
       
        whiteGhostTimerMax = level.getWhiteGhostTimerMax();
        whiteGhostTimer = whiteGhostTimerMax;
        numberWhiteSpawn = level.getNumberWhiteSpawn();
        blackGhostTimerMax = level.getBlackGhostTimerMax();
        blackGhostTimer = blackGhostTimerMax;
        numberBlackSpawn = level.getNumberBlackSpawn();
        levelTime.restart();
    }
}

void Survival::spawnWhiteEnnemy(sf::RenderWindow* window)
{
    //position de lennemi
    this->ennemies.push_back(new WhiteGhost());

    this->ennemies.at(ennemies.size() - 1)->setPosition(sf::Vector2<float>(
        static_cast<float>(rand() % static_cast<int>(window->getSize().x)),
        static_cast<float>(rand() % static_cast<int>(window->getSize().y))));
    while (

        ennemies.at(ennemies.size() - 1)->getPosition()->x > ninja.getPosition()->x - 100 &&
        ennemies.at(ennemies.size() - 1)->getPosition()->x < ninja.getPosition()->x + 100 &&
        ennemies.at(ennemies.size() - 1)->getPosition()->y < ninja.getPosition()->y + 100 &&
        ennemies.at(ennemies.size() - 1)->getPosition()->y > ninja.getPosition()->y - 100
        ) {

        this->ennemies.at(ennemies.size() - 1)->setPosition(sf::Vector2<float>(
            static_cast<float>(rand() % static_cast<int>(window->getSize().x)),
            static_cast<float>(rand() % static_cast<int>(window->getSize().y))));
    }

 
}

void Survival::spawnBlackEnnemy(sf::RenderWindow* window)
{
    //position de lennemi
    this->ennemies.push_back(new BlackGhost());
   
    ennemies.at(ennemies.size() - 1)->setPosition(sf::Vector2<float>(
        static_cast<float>(rand() % static_cast<int>(window->getSize().x)),
        static_cast<float>(rand() % static_cast<int>(window->getSize().y))));
    while (

        ennemies.at(ennemies.size() - 1)->getPosition()->x > ninja.getPosition()->x - 300 &&
        ennemies.at(ennemies.size() - 1)->getPosition()->x < ninja.getPosition()->x + 300 &&
        ennemies.at(ennemies.size() - 1)->getPosition()->y < ninja.getPosition()->y + 300 &&
        ennemies.at(ennemies.size() - 1)->getPosition()->y > ninja.getPosition()->y - 300
        ) {

        ennemies.at(ennemies.size() - 1)->setPosition(sf::Vector2<float>(
            static_cast<float>(rand() % static_cast<int>(window->getSize().x)),
            static_cast<float>(rand() % static_cast<int>(window->getSize().y))));
    }

    
}

void Survival::updateKunai(sf::RenderWindow* window, sf::Time elapsed)
{
    if (kunaiAvailable) {
        //kunai drop
        spawnKunai(window);
        kunaiDrop.update(elapsed);
    }
    //throwed kunai
    for (int i = 0; i < throwedKunai.size(); i++)
    {
       
        if (throwedKunai[i].getPosition()->y > window->getSize().y) { //tomber dans le vide
            throwedKunai.erase(throwedKunai.begin() + i);
        }
        else {
            throwedKunai[i].update(elapsed);
        }
    }

}

void Survival::spawnKunai(sf::RenderWindow* window)
{
   
    if (timerKunai.getElapsedTime() > sf::seconds(10)) {
        kunaiDrop.setPosition(sf::Vector2<float>(
            static_cast<float>(rand() % static_cast<int>(window->getSize().x)),
            0));
        timerKunai.restart();
        kunaiDrop.setSpeed(0, 8);
        kunaiDrop.setOnFloor(false);

    }

}

void Survival::updatePotion(sf::RenderWindow* window, sf::Time elapsed)
{
    if (potionAvailable) {
        spawnPotion(window);
        lifePotionDrop.update(elapsed);
    }
}

void Survival::spawnPotion(sf::RenderWindow* window)
{
   
    if (timerPotion.getElapsedTime() > sf::seconds(25)) {
        lifePotionDrop.setPosition(sf::Vector2<float>(
            static_cast<float>(rand() % static_cast<int>(window->getSize().x)),
            0));
        timerPotion.restart();
         lifePotionDrop.setSpeed(0, 5);
        lifePotionDrop.setOnFloor(false);

    }

}

//position de la souris
void Survival::updateMousePos(sf::RenderWindow* window)
{
    this->mousePos = sf::Mouse::getPosition(*window);
    this->mousePosView = window->mapPixelToCoords(this->mousePos);
   
}

//update toute en appellant les autres methodes
void Survival::update(sf::RenderWindow* window, sf::Time elapsed)
{
    if (music.getStatus() != sf::Sound::Status::Playing) music.play();
    if (pause) {
        updateRecommencer(window);
    }
    else {
        this->pollEvents(window);
        this->updateMousePos(window);
        this->updateEnnemies(window, elapsed);
        this->ninja.ninjaSide(mousePosView);
        this->ninja.update(elapsed);
     
        this->updateKunai(window,elapsed);
        this->updatePotion(window, elapsed);
        this->manageColision();
        displayScore.setString("Points: "+std::to_string(score));
        displayLevel.setString("Level: "+std::to_string(level.getLevel()));
        displayTimer.setString(" remaining Time: " + 
            std::to_string((int)(level.getTimeRestriction().asSeconds()
                -levelTime.getElapsedTime().asSeconds())));
        ennemiesToKill.setString("ennemies to kill:"+std::to_string(level.getEnnemiesObjectives()-killedEnnemies));
        //fin game
        if (ninja.getLife() <= 0) {
            allLevelClear.setString("");
            endGame();
        }
    }

 

    
}

// render les ennemis 
void Survival::renderEnnemies(sf::RenderWindow* window)
{
    for (auto& en : this->ennemies)
    {
       
        en->render(window);
    }
}

void Survival::renderKunai(sf::RenderWindow* window)
{
    kunaiDrop.render(window);
    for (auto& kunai : this->throwedKunai)
    {
        kunai.render(window);
    }
}

//render les joueurs, terrains,
void Survival::render(sf::RenderWindow* window)
{
    if (pause) {
        renderRecommencer( window);
    }
    else {
        window->draw(background);
        this->renderEnnemies(window);
        this->terrainManager.render(window);
        this->ninja.render(window);
        this->renderKunai(window);
        this->lifePotionDrop.render(window);
        window->draw(displayScore);
        window->draw(displayLife);
        window->draw(displayNbKunai);
        window->draw(displayTimer);
        window->draw(ennemiesToKill);
        window->draw(displayLevel);
        
    }
   
 


}

void Survival::reloadSave()
{
    highScore = SaveGame::getHighScore();
    ninjaXSpeed = SaveGame::getXSpeed();
    ninja.setMaxJump(SaveGame::getjump());
    kunaiAvailable = SaveGame::getKunaiDrop();
    potionAvailable = SaveGame::getPotionDrop();
}

void Survival::manageColision()
{

    
   int counterColFloorNinja =0;
   for (Terrain ter : *terrainManager.getTerrainList()) {

       //Terrain et ninja
       if (Physics::collision(this->ninja, ter))
       {
           if (Physics::adjustPosition(this->ninja, ter)) counterColFloorNinja++;
       }

       //kunai drop et terrain
       if (Physics::collision(kunaiDrop, ter)) {
           Physics::adjustPosition(kunaiDrop, ter);
           kunaiDrop.setOnFloor(true);
       }

       //potion drop et terrain
       if (Physics::collision(lifePotionDrop, ter)) {
           Physics::adjustPosition(lifePotionDrop, ter);
           lifePotionDrop.setOnFloor(true);
       }
       //kunai lance et terrain
       for (auto& kunai : this->throwedKunai) {
           if (Physics::collision(kunai, ter)) {
               kunai.setPosition(0, 5000);
           }
       }
   }
   this->ninja.setOnFloor(false);
   if (counterColFloorNinja != 0) {
       this->ninja.resetJumped();
       this->ninja.setOnFloor(true);
   }


   //ninja et kunai drop
   if (Physics::collision(this->ninja, kunaiDrop)) {
       ninja.incrementNbKunai();
       kunaiDrop.setPosition(-100, 200);
       displayNbKunai.setString(" nombre kunai: " + std::to_string(ninja.getNbkunai()));

   }

   //ninja et potion
   if (Physics::collision(this->ninja, lifePotionDrop)) {
       ninja.setLife(ninja.getLife() + 5);
       lifePotionDrop.setPosition(-100, 200);
       displayLife.setString("life: " + std::to_string((int)ninja.getLife()));
      

   }

   //ghost et terrain
   int counterMidAir=0;
   for (auto& en : this->ennemies){
        for (Terrain ter : *terrainManager.getTerrainList()) {
        
            
            if (Physics::collision(*en, ter))
            {
               
                Physics::adjustPosition(*en, ter); 
            }

           
        }
        //kunai lance et ghost
        for (auto& kunai : this->throwedKunai) {
            if (Physics::collision(kunai, *en)) {
                en->enleverLife(ninja.getAttack());
                score += 10;
                killedEnnemies++;
            }
        }

        //ghost et ninja
        if (Physics::collision(*en, ninja) && !en->isDead()) {
            ninja.enleverLife(en->getAttack());
            displayLife.setString("life: "+std::to_string((int)ninja.getLife()));
            en->setPosition(sf::Vector2f(0, 5000));
        }
        if (ninja.asAttack()) {
            if (Physics::collision(*en, *ninja.getSword())&& !en->isDead()) {
                
                en->enleverLife(ninja.getAttack());
                score += 10;
                killedEnnemies++;
            }
        }
     
   }
      
    
    

  
}

void Survival::retry()
{
   
    this->score = 0;
    begin();
    timerKunai.restart();
    ninja.setNbKunai(0);
    pause = false;
    displayScore.setString(std::to_string(0));
    ninja.setLife(50);
    displayLife.setString("life:"+ std::to_string(ninja.getLife()));
    displayNbKunai.setString(" nombre kunai: " + std::to_string(ninja.getNbkunai()));
    ennemies.clear();
}

void Survival::endGame()
{
    if (score > highScore) {
        highScore = score;
        SaveGame::setHighScore(highScore);
        displayHighScore.setString("High Score: " + std::to_string(highScore));    
    }
    displayGold.setString("Gold: " + std::to_string(level.getLevel()));
    SaveGame::setGold(SaveGame::getGold() + level.getLevel());
    SaveGame::save();
    pause = true;
}

void Survival::updateRecommencer(sf::RenderWindow* window)
{
    this->pollEvents(window);
    this->updateMousePos(window);
    checkHoverBouton();
    
  
}

void Survival::renderRecommencer(sf::RenderWindow* window)
{
    window->draw(background);
    buttonRetry.render(window);
    buttonMenu.render(window);
    window->draw(displayHighScore);
    window->draw(displayGold);
    window->draw(allLevelClear);
}

void Survival::checkHoverBouton()
{
    if (buttonRetry.positionOnButton(mousePosView)) {
        buttonRetry.setTextColor(sf::Color::Black);
    }
    else {
        buttonRetry.setTextColor(sf::Color(195, 54, 24, 255));
    }
    if (buttonMenu.positionOnButton(mousePosView)) {
        buttonMenu.setTextColor(sf::Color::Black);
    }
    else {
        buttonMenu.setTextColor(sf::Color(195, 54, 24, 255));
    }
}

bool Survival::goMenu()
{
    return menu;
}

void Survival::setGoMenu(bool go)
{
    menu = go;
}

void Survival::begin()
{
   
    level.play();
    killedEnnemies = 0;
    whiteGhostTimer = sf::seconds(0);
    blackGhostTimer = sf::seconds(0);
    whiteGhostTimerMax = level.getWhiteGhostTimerMax();
    numberWhiteSpawn = level.getNumberWhiteSpawn();
    blackGhostTimerMax = level.getBlackGhostTimerMax();
    numberBlackSpawn = level.getNumberBlackSpawn();
    levelTime.restart();
}
