#include "PacketManager.h"


namespace Packet
{
	void SendPacket(char* pkt, size_t sz)
	{
		char* npkt = new char[sz];
		memcpy(npkt, pkt, sz);
		choked_packets.push_back({ npkt, sz });
		Send();
	}
	void SendPacket(const PacketBuffer& pkt)
	{
		char* npkt = new char[pkt.index]; //maybe -1 idk
		memcpy(npkt, pkt.buffer, pkt.index + 1);
		choked_packets.push_back({ npkt, pkt.index });
		Send();
	}
	void Send()
	{
		if (send_packets)
		{
			for (const auto& pkt : choked_packets)
			{
				//send the packets
			}
			choked_packets.clear();
		}
	}
}