#pragma once
#include <string>

struct Tile
{
	int type;
	std::string id;
	bool sink;
	int speed;
	bool noWalk;
};