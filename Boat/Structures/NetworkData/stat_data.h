#pragma once
#include "../../Connection/Packets.h"
#include "../enumerations.h"
class StatData : Packet::BasePacket
{
	int8_t statType;
	int32_t statValue;
	std::string statStringValue;

	void ReadData(Packet::PacketBuffer* pb) override
	{
		statType = pb->ReadInt8();
		if (isStringStat())
			statStringValue = pb->ReadString();
		else
			statValue = pb->ReadInt32();
	}
	void WriteData(Packet::PacketBuffer* pb) override
	{
		pb->WriteInt8(statType);
		if (isStringStat())
			pb->WriteString(statStringValue);
		else
			pb->WriteInt32(statValue);
	}
	bool isStringStat()
	{
		if (statType == Packet::StatType::NAME_STAT || statType ==
			Packet::StatType::GUILD_NAME_STAT || statType ==
			Packet::StatType::PET_NAME_STAT || statType ==
			Packet::StatType::ACCOUNT_ID_STAT || statType ==
			Packet::StatType::OWNER_ACCOUNT_ID_STAT)
			return true;
		else
			return false;
	}
};