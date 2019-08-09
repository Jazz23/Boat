#pragma once

#include "PacketBuffer.h"
namespace Packet
{
	class BasePacket
	{
	public:
		virtual void WriteData(PacketBuffer *pb) { return; }
		virtual void ReadData(PacketBuffer *pb) { return; }
	};

	class IncomingPacket
	{
	public:
		virtual void ReadData(PacketBuffer* pb) { return; }
	};

	class OutgoingPacket
	{
	public:
		virtual void WriteData(PacketBuffer* pb) { return; }
	};
}