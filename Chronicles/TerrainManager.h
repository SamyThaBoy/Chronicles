#pragma once
#include <list>
#include "Terrain.h"
class TerrainManager
{
public:
	TerrainManager();
	~TerrainManager();
	void update();
	void render(sf::RenderWindow* window);
	std::list<Terrain>* getTerrainList();
private:
  std::list<Terrain> listTerrains;
  sf::Texture texture;
};

