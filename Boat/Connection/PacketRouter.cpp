#include "PacketManager.h"
#include "Packets.h"

namespace Packet
{
	void PacketOut(OutgoingPacket& pkt)
	{
		PacketBuffer buf;
		pkt.WriteData(&buf);
		PacketDeep::SendPacket(buf, SEND_PACKET_NOW);
	}
	void HandlePacket(char* pkt, size_t sz)
	{
		PacketBuffer packet(pkt, sz);
		packet.index = 4;
		switch (packet.ReadInt8())
		{
			//use [[likely]] for stuff like update ping and pong
		}
	}
}