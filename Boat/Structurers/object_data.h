#pragma once
#include "../Connection/Packets.h"

class ObjectData : BasePacket
{
public:
	int objectType;
	ObjectStatusData status;

	void read(PacketBuffer* pb)
	{
		if (!pb) return;
	}

	void write(PacketBuffer* pb)
	{
		if (!pb) return;
		pb->Write
	}
};