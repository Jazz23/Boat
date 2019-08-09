#pragma once
#include "../Connection/Packets.h"

class ObjectData : Packet::BasePacket
{
public:
	uint32_t objectType;
	ObjectStatusData status;

	void ReadData(Packet::PacketBuffer* pb) override
	{
		if (!pb) return;
		objectType = pb->ReadUnsignedInt16();
		status.ReadData(pb);
	}

	void WriteData(Packet::PacketBuffer* pb) override
	{
		if (!pb) return;
		status.WriteData(pb);
	}
};