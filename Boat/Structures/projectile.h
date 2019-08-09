#pragma once
#include "world-pos-data.h"
#include "object.h"
#include "resource-manager.h"
#include <algorithm>

class Projectile
{
	int containerType;
	int bulletType;
	int ownerObjectId;
	int bulletId;
	int startAngle;
	int startTime;
	WorldPosData startPosition;
	GameObject containerProperties;
	ProjectileInfo* projectileProperties;
	bool damagePlayers;
	bool damageEnemies;
	int damage;
	WorldPosData currentPosition;

	Projectile(int containerType, int bulletType, int ownerObjectId, int bulletId, int startAngle, int startTime, WorldPosData startPosition) :
		containerType(containerType), bulletType(bulletType), ownerObjectId(ownerObjectId), bulletId(bulletId), startAngle(startAngle),
		startTime(startTime), startPosition(startPosition), containerProperties(ResourceManager::Objects[containerType]),
		projectileProperties(std::find_if(containerProperties.projectiles.begin(), containerProperties.projectiles.end(), [&](const ProjectileInfo& x) {return x.id == bulletType; })._Ptr),
		damagePlayers(containerProperties.enemy), damageEnemies(!damagePlayers), damage(0) {}
};