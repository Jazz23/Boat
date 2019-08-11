#include "PacketManager.h"
#include "Packets.h"
#include "../Logger/Logger.h"
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
		int8_t packetId = packet.ReadInt8();
		Logger::Log("recieved packet with id: " + std::to_string(packetId));
		switch (packetId)
		{
			//use [[likely]] for stuff like update ping and pong
		}
	}
}