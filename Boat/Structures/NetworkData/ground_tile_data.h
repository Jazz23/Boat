#pragma once
#include "../../Connection/Packets.h"

class GroundTileData : Packet::BasePacket
{
public:
	int16_t x, y;
	uint16_t type;

	void ReadData(Packet::PacketBuffer* pb) override
	{
		if (!pb) return;
		x = pb->ReadInt16();
		y = pb->ReadInt16();
		type = pb->ReadUnsignedInt16();
	}

	void WriteData(Packet::PacketBuffer* pb) override
	{
		if (!pb) return;
		pb->WriteInt16(x);
		pb->WriteInt16(y);
		pb->WriteUnsignedInt16(type);
	}
};