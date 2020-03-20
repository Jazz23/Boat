#include "PacketManager.h"
#include "../../Utilities/Logger/Log.h"

namespace Client
{
	bool __CLIENT::BadFlags(unsigned long flags)
	{
		return (flags & SEND_PACKET_NOW && flags & QUEUE_PACKET);
	}
	void __CLIENT::SendPacket(unsigned char* pkt, size_t sz, unsigned long flags)
	{
		if (BadFlags(flags) || !pkt || !client)
			return;

		std::lock_guard<std::mutex> g(clientMutex);

		if (flags & SEND_PACKET_NOW)
		{
			if (client->write_all(pkt, sz) > 0)
			{
				PrintAndLog("packet sent");
			}
			else
			{
				PrintAndLog("packet send failed!");
			}
		}
		else if (flags & QUEUE_PACKET)
		{
			char* npkt = new char[sz]; 
			memcpy(npkt, pkt, sz);
			choked_packets.emplace_back(npkt, sz);
			PrintAndLog("queued packet for sending");
		}

		if (flags & SEND_ENTIRE_QUEUE)
		{
			SendQueuedPackets();
		}
	}
	void __CLIENT::SendPacket(const Packet::PacketBuffer& pkt, unsigned long flags)
	{
		return SendPacket(pkt.buffer, pkt.size, flags);
	}
	void __CLIENT::SendQueuedPackets()
	{
		for (const auto& pkt : choked_packets)
		{
			if (pkt.first != nullptr || pkt.second > 0)
			{
				if (client->write_all(pkt.first, pkt.second) < 1)
					PrintAndLog("failed when sending packet queue");
				delete[] pkt.first;
			}
		}
		choked_packets.clear();
	}
}