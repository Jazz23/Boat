#include "PacketManager.h"
#include "../../Utilities/Logger/Logger.h"

namespace PacketDeep
{
	bool badFlags(unsigned long flags)
	{
		return !(flags & SEND_PACKET_NOW && flags & QUEUE_PACKET);
	}
	int SendPacket(unsigned char* pkt, size_t sz, unsigned long flags)
	{
		std::lock_guard<std::mutex> g(packetMutex);
		if (badFlags(flags))
			return BAD_FLAGS;
		if (!pkt && (flags & SEND_PACKET_NOW || flags & QUEUE_PACKET))
			return BAD_PACKET_ARRAY;

		if (flags & SEND_PACKET_NOW)
		{
			if (conSock != INVALID_SOCKET)
			{
				if (send(conSock, (char*)pkt, sz, 0) != SOCKET_ERROR)
					Logger::Log("packet sent");
				else
					Logger::Log("packet send failed!");
			}
		}
		else if (flags & QUEUE_PACKET)
		{
			char* npkt = new char[sz]; 
			memcpy(npkt, pkt, sz);
			choked_packets.emplace_back(npkt, sz);
			Logger::Log("queued packet for sending");
		}

		if (flags & SEND_ENTIRE_QUEUE)
		{
			if (SendQueuedPackets() != SOCKET_ERROR)
				Logger::Log("sent entire packet queue");
			else
				Logger::Log("sending of queued packets failed");
		}
		return ASSUMED_SUCCESS;
	}
	int SendPacket(const Packet::PacketBuffer& pkt, unsigned long flags)
	{
		return SendPacket(pkt.buffer, pkt.index+1, flags);
	}
	int SendQueuedPackets()
	{
		if (send_packets)
		{
			for (const auto& pkt : choked_packets)
			{
				if (conSock == INVALID_SOCKET)
					return SOCKET_ERROR;
				if (send(conSock, pkt.first, pkt.second, 0) == SOCKET_ERROR)
					return SOCKET_ERROR;
				delete[] pkt.first;
			}
			choked_packets.clear();
		}
		return ASSUMED_SUCCESS;
	}
}