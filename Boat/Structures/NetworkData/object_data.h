#pragma once

#include "../../Connection/Packet/Packets.h"
#include "object_status_data.h"

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

	void WriteData(Packet::PacketBuffer* pb) const override
	{
		if (!pb) return;
		status.WriteData(pb);
	}
};