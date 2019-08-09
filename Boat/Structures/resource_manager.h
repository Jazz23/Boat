#pragma once
#include<map>
#include "tile.h"
#include "object.h"

class ResourceManager
{
public:
	static std::map<int, Tile> Tiles;
	static std::map<int, GameObject> Objects;
	static std::map<int, GameObject> Items;
	static std::map<int, GameObject> Enemies;
	static std::map<int, GameObject> Pets;

	static void loadAllResources()
	{
		//Insert thread stuff here cause it'll take a while to load all this junk
		loadTileInfo();
		loadObjects();
	}

private:
	static void loadTileInfo()
	{

	}

	static void loadObjects()
	{

	}
};