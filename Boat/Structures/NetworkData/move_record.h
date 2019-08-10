#pragma once

#include "../../Connection/Packets.h"

class MoveRecord : Packet::BasePacket
{
public:
	int32_t time;
	float x, y;

	void WriteData(Packet::PacketBuffer* pb) const override
	{
		if (!pb) return;
		pb->WriteInt32(time);
		pb->WriteFloat(x);
		pb->WriteFloat(y);
	}
	void ReadData(Packet::PacketBuffer* pb) override
	{
		if (!pb) return;
		time = pb->ReadInt32();
		x = pb->ReadFloat();
		y = pb->ReadFloat();
	}
	void operator=(const MoveRecord& mr)
	{
		time = mr.time;
		x = mr.x;
		y = mr.y;
	}
	bool operator==(const MoveRecord& mr)
	{
		return (time == mr.time && x == mr.x && y == mr.y);
	}
};