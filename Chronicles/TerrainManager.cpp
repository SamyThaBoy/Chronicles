#include "TerrainManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
TerrainManager::TerrainManager()
{
	texture.loadFromFile("grass.png");
	texture.setRepeated(true);
	//set le terrain du jeu
	listTerrains.push_back(*new Terrain(sf::Vector2f(900.f, 900.f), 2000, 120,texture));//ground
	//listeTerrains.push_back(*new Terrain(sf::Vector2f(1000.f, 550.f), 400, 40,texture));
	listTerrains.push_back(*new Terrain(sf::Vector2f(1300.f, 725.f), 400, 40,texture));
	listTerrains.push_back(*new Terrain(sf::Vector2f(1000.f, 650.f), 40, 10, texture));
	listTerrains.push_back(*new Terrain(sf::Vector2f(900.f, 550.f), 40, 10, texture));
	listTerrains.push_back(*new Terrain(sf::Vector2f(800.f, 450.f), 40, 10, texture));
	listTerrains.push_back(*new Terrain(sf::Vector2f(700.f, 350.f), 40, 10, texture));
	listTerrains.push_back(*new Terrain(sf::Vector2f(550.f, 225.f), 200, 40, texture));
	listTerrains.push_back(*new Terrain(sf::Vector2f(850.f, 225.f), 200, 40, texture));
	listTerrains.push_back(*new Terrain(sf::Vector2f(-8, 0), 10, 1700, texture)); //mur cote
	listTerrains.push_back(*new Terrain(sf::Vector2f(1808, 0), 10, 1700, texture));//mur cote
}

TerrainManager::~TerrainManager()
{
}

void TerrainManager::update()
{
}

void TerrainManager::render(sf::RenderWindow* window)
{
	for (Terrain ter : listTerrains) {
		ter.render(window);
	}
}

std::list<Terrain>* TerrainManager::getTerrainList()
{
	return &listTerrains;
}
