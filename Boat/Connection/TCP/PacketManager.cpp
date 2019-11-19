#include "PacketManager.h"
#include "../../Utilities/Logger/Log.h"

namespace PacketDeep
{
	bool badFlags(unsigned long flags)
	{
		return !(flags & SEND_PACKET_NOW && flags & QUEUE_PACKET);
	}
	int SendPacket(unsigned char* pkt, size_t sz, unsigned long flags)
	{
		if (badFlags(flags))
			return BAD_FLAGS;
		if (!pkt && (flags & SEND_PACKET_NOW || flags & QUEUE_PACKET))
			return BAD_PACKET_ARRAY;
		if (!client)
			return -69;

		std::lock_guard<std::mutex> g(clientMutex);

		int status = ASSUMED_SUCCESS;

		if (flags & SEND_PACKET_NOW)
		{
			if (client->write_all(pkt, sz) > 0)
			{
				PrintAndLog("packet sent");
			}
			else
			{
				status = FAILED_PACKET_SEND;
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
			status = SendQueuedPackets();
			if (status != FAILED_PACKET_SEND)
			{
				PrintAndLog("sent entire packet queue");
			}
			else
			{
				PrintAndLog("sending of queued packets failed");
			}
		}
		return status;
	}
	int SendPacket(const Packet::PacketBuffer& pkt, unsigned long flags)
	{
		return SendPacket(pkt.buffer, pkt.size, flags);
	}
	int SendQueuedPackets()
	{
		int status = ASSUMED_SUCCESS;
		for (const auto& pkt : choked_packets)
		{
			if (pkt.first != NULL || pkt.second > 0)
			{
				if (client->write_all(pkt.first, pkt.second) < 1)
					status = FAILED_PACKET_SEND;
				else
					delete[] pkt.first;
			}
		}
		choked_packets.clear();
		return status;
	}
}