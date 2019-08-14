#pragma once
#include "../../Connection/Packet/Packets.h"

class SlotObjectData : Packet::BasePacket
{
public:
	int32_t objectId;
	uint8_t slotId;
	uint32_t objectType;

	void ReadData(Packet::PacketBuffer* pb) override
	{
		if (!pb) return;
		objectId = pb->ReadInt32();
		slotId = pb->ReadUnsignedInt8();
		objectType = pb->ReadUnsignedInt32();
	}

	void WriteData(Packet::PacketBuffer* pb) const override
	{
		if (!pb) return;
		pb->WriteInt32(objectId);
		pb->WriteUnsignedInt8(slotId);
		pb->WriteInt32(objectType);
	}
};