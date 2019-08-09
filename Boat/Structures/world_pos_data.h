#pragma once
#include <math.h>
#include "../Connection/PacketBuffer.h"
class WorldPosData
{
public:
	float x, y;

	WorldPosData(int x = 0, int y = 0) : x(x), y(y) {}

	int squareDistanceTo(WorldPosData location)
	{
		return pow(pow((double)(location.x) - x, 2) + pow((double)(location.y) - y, 2), 0.5); //vs wanted me to cast it to a double before subtracting for some reason...
	}
	void Read(Packet::PacketBuffer* pb)
	{
		if (!pb) return;
		x = pb->ReadFloat();
		y = pb->ReadFloat();
	}
	void Write(Packet::PacketBuffer* pb)
	{
		if (!pb) return;
		pb->WriteFloat(x);
		pb->WriteFloat(y);
	}
};