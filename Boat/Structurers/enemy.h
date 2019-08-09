#pragma once
#include "playerdata.h"
#include "object.h"

class Enemy
{
public:
	PlayerData objectData;
	GameObject properties;
	bool dead;
	int lastUpdate;
	WorldPosData tickPos;
	WorldPosData posAtTick;
	WorldPosData moveVector;
	int lastTickId;
	WorldPosData currentPos;

	Enemy(GameObject properties, ObjectSta)
};