#pragma once
#include "../Connection/Packets.h"

class ObjectData : Packet::BasePacket
{
public:
	int objectType;
	ObjectStatusData status;

	void read(Packet::PacketBuffer* pb)
	{
		if (!pb) return;
	}

	void write(Packet::PacketBuffer* pb)
	{
		if (!pb) return;
		pb->Write
	}
};