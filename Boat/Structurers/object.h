#pragma once
#include <string>
#include "classes.h"
#include <vector>
#include <map>
struct GameObject
{
	int type;
	std::string id;
	bool enemy;
	bool item;
	bool god;
	bool pet;
	int slotType;
	int bagType;
	std::string _class;
	int maxHitPoints;
	int defense;
	int xpMultiplier;
	std::vector<ProjectileInfo> projectiles;
	ProjectileInfo projectile;
	//int statType, int amount
	std::map<int, int> activateOnEquip;
	int rateOfFire;
	int numProjectiles;
	int arcGap;
	int fameBonus;
	int feedPower;
	bool occupySquare;
	bool fullOccupy;
};

struct ProjectileInfo
{
	int id;
	std::string objectId;
	int damage;
	int minDamage;
	int maxDamage;
	int speed;
	int lifetimeMS;
	bool parametric;
	bool wavy;
	bool boomerang;
	bool multihit;
	bool passesCover;
	int amplitude;
	int frequency;
	int magnitude;
	//std::string effectName, int duration
	std::map<std::string, int> conditionEffects;
};