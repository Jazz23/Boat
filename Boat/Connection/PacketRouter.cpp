#include "PacketManager.h"
#include "Packets.h"

namespace Packet
{
	void HandlePacket(char* pkt, size_t sz)
	{
		PacketBuffer packet(pkt, sz);
		switch (packet.ReadInt8())
		{
			//use [[likely]] for stuff like update ping and pong
		}
	}


	void PacketOut(OutgoingPacket& pkt)
	{
		PacketBuffer buf;
		pkt.WriteData(&buf);
	}
}