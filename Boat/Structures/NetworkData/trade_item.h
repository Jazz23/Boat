#pragma once
#include "../../Connection/Packets.h"

class TradeItem : Packet::BasePacket
{
public:
	int32_t item, slotType;
	bool tradeable, included;

	void ReadData(Packet::PacketBuffer* pb) override
	{
		if (!pb) return;
		item = pb->ReadInt32();
		slotType = pb->ReadInt32();
		tradeable = pb->ReadBoolean();
		included = pb->ReadBoolean();
	}

	void WriteData(Packet::PacketBuffer* pb) override
	{
		if (!pb) return;
		pb->WriteInt32(item);
		pb->WriteInt32(slotType);
		pb->WriteBoolean(tradeable);
		pb->WriteBoolean(included);
	}
};