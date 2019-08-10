#pragma once
#include "../../Connection/Packets.h"
#include "../enumerations.h"
class StatData : Packet::BasePacket
{
public:
	int8_t statType;
	int32_t statValue;
	std::string stringStatValue;

	void ReadData(Packet::PacketBuffer* pb) override
	{
		statType = pb->ReadInt8();
		if (isStringStat())
			stringStatValue = pb->ReadString();
		else
			statValue = pb->ReadInt32();
	}
	void WriteData(Packet::PacketBuffer* pb) const override
	{
		pb->WriteInt8(statType);
		if (isStringStat())
			pb->WriteString(stringStatValue);
		else
			pb->WriteInt32(statValue);
	}
	bool isStringStat()
	{
		if (statType == NAME_STAT || statType ==
			GUILD_NAME_STAT || statType ==
			PET_NAME_STAT || statType ==
			ACCOUNT_Id_STAT || statType ==
			OWNER_ACCOUNT_Id_STAT)
			return true;
		else
			return false;
	}
};