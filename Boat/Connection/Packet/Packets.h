#pragma once
#include <stdint.h>
#include "PacketBuffer.h"
namespace Packet
{
	class BasePacket
	{
	public:
		virtual void WriteData(PacketBuffer* pb) const = 0;
		virtual void ReadData(PacketBuffer* pb) = 0;
	};

	class IncomingPacket
	{
	public:
		virtual void ReadData(PacketBuffer* pb) = 0;
	};

	class OutgoingPacket
	{
	public:
		int8_t pktId = 0;
		virtual void WriteData(PacketBuffer* pb) const = 0;
	};
}