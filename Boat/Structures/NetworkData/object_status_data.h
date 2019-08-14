#pragma once
#include "../../Connection/Packet/Packets.h"
#include "../playerdata.h"
#include "../object.h"
#include "object_data.h"
#include "stat_data.h"
#include "../../Connection/Packet/PacketBuffer.h"

class ObjectStatusData : Packet::BasePacket
{
public:
	int objectId;
	WorldPosData pos;
	std::vector<StatData> stats;

	static PlayerData processObject(ObjectData data)
	{
		const auto playerData = processObjectStatus(data.status);
	}

	static PlayerData processObjectStatus(ObjectStatusData data, PlayerData* currentData = nullptr)
	{
		const auto playerData = processStatData(data.stats, currentData);
	}

	static PlayerData processStatData(std::vector<StatData> stats, PlayerData* currentData = nullptr)
	{
		PlayerData playerData = !currentData ? PlayerData() : *currentData;

		for (const auto stat : stats) {
			switch (stat.statType) {
			case NAME_STAT:
				playerData.name = stat.stringStatValue;
				continue;
			case LEVEL_STAT:
				playerData.level = stat.statValue;
				continue;
			case EXP_STAT:
				playerData.exp = stat.statValue;
				continue;
			case CURR_FAME_STAT:
				playerData.currentFame = stat.statValue;
				continue;
			case NUM_STARS_STAT:
				playerData.stars = stat.statValue;
				continue;
			case ACCOUNT_Id_STAT:
				playerData.accountId = stat.stringStatValue;
				continue;
			case FAME_STAT:
				playerData.accountFame = stat.statValue;
				continue;
			case CREDITS_STAT:
				playerData.gold = stat.statValue;
				continue;
			case MAX_HP_STAT:
				playerData.maxHP = stat.statValue;
				continue;
			case MAX_HP_BOOST_STAT:
				playerData.maxHPBoost = stat.statValue;
				continue;
			case MAX_MP_STAT:
				playerData.maxMP = stat.statValue;
				continue;
			case MAX_MP_BOOST_STAT:
				playerData.maxMPBoost = stat.statValue;
				continue;
			case HP_STAT:
				playerData.hp = stat.statValue;
				continue;
			case MP_STAT:
				playerData.mp = stat.statValue;
				continue;
			case ATTACK_STAT:
				playerData.atk = stat.statValue;
				continue;
			case ATTACK_BOOST_STAT:
				playerData.atkBoost = stat.statValue;
				continue;
			case DEFENSE_STAT:
				playerData.def = stat.statValue;
				continue;
			case DEFENSE_BOOST_STAT:
				playerData.defBoost = stat.statValue;
				continue;
			case SPEED_STAT:
				playerData.spd = stat.statValue;
				continue;
			case SPEED_BOOST_STAT:
				playerData.spdBoost = stat.statValue;
				continue;
			case DEXTERITY_STAT:
				playerData.dex = stat.statValue;
				continue;
			case DEXTERITY_BOOST_STAT:
				playerData.dexBoost = stat.statValue;
				continue;
			case VITALITY_STAT:
				playerData.vit = stat.statValue;
				continue;
			case VITALITY_BOOST_STAT:
				playerData.vitBoost = stat.statValue;
				continue;
			case CONDITION_STAT:
				playerData.condition = stat.statValue;
				continue;
			case WISDOM_STAT:
				playerData.wis = stat.statValue;
				continue;
			case WISDOM_BOOST_STAT:
				playerData.wisBoost = stat.statValue;
				continue;
			case HEALTH_POTION_STACK_STAT:
				playerData.hpPots = stat.statValue;
				continue;
			case MAGIC_POTION_STACK_STAT:
				playerData.mpPots = stat.statValue;
				continue;
			case HASBACKPACK_STAT:
				playerData.hasBackpack = !!stat.statValue;
				continue;
			case NAME_CHOSEN_STAT:
				playerData.nameChosen = !!stat.statValue;
				continue;
			case GUILD_NAME_STAT:
				playerData.guildName = stat.stringStatValue;
				continue;
			case GUILD_RANK_STAT:
				playerData.guildRank = (GuildRank)stat.statValue;
				continue;
			default:
				if (stat.statType >= INVENTORY_0_STAT && stat.statType <= INVENTORY_11_STAT) {
					playerData.inventory[stat.statType - 8] = stat.statValue;
				}
				else if (stat.statType >= BACKPACK_0_STAT && stat.statType <= BACKPACK_7_STAT) {
					playerData.inventory[stat.statType - 59] = stat.statValue;
				}
			}
		}
		return playerData;
	}

	void ReadData(Packet::PacketBuffer* pb) override
	{
		if (!pb) return;
		objectId = pb->ReadInt32();
		pos.ReadData(pb);
		const size_t statLen = pb->ReadInt16();
		stats.resize(statLen);
		for (int i = 0; i < statLen; i++) {
			StatData sd;
			sd.ReadData(pb);
			stats.push_back(sd);
		}
	}

	void WriteData(Packet::PacketBuffer* pb) const override
	{
		if (!pb) return;
		pb->WriteInt32(objectId);
		pos.WriteData(pb);
		pb->WriteInt16(stats.size());
		for (auto &stat : stats)
		{
			stat.WriteData(pb);
		}
	}
};



//static processStatData(stats: StatData[], currentData?: PlayerData): PlayerData {