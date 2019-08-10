#include "PacketManager.h"

namespace PacketDeep
{
	bool badFlags(unsigned long flags)
	{
		return !(flags & SEND_PACKET_NOW && flags & QUEUE_PACKET);
	}
	int SendPacket(char* pkt, size_t sz, unsigned long flags)
	{
		std::lock_guard<std::mutex> g(packetMutex);
		if (badFlags(flags))
			return BAD_FLAGS;
		if (!pkt && (flags & SEND_PACKET_NOW || flags & QUEUE_PACKET))
			return BAD_PACKET_ARRAY;
		
		int status = ASSUMED_FAILURE;

		if (flags & SEND_PACKET_NOW)
		{
			if (conSock == INVALID_SOCKET)
				return status;
			iResult = send(conSock, pkt, sz, 0);
			if (iResult == SOCKET_ERROR)
				return SOCKET_ERROR;
			status = ASSUMED_SUCCESS;
		}
		else if (flags & QUEUE_PACKET)
		{
			//make our own copy so original packet buffer can be deleted
			char* npkt = new char[sz]; 
			memcpy(npkt, pkt, sz);
			choked_packets.emplace_back(npkt, sz);
			status = ASSUMED_SUCCESS;
		}

		if (flags & SEND_ENTIRE_QUEUE)
		{
			SendQueuedPackets();
			status = ASSUMED_SUCCESS;
		}

		return status;
	}
	int SendPacket(const Packet::PacketBuffer& pkt, unsigned long flags)
	{
		SendPacket(pkt.buffer, pkt.index+1, flags);
	}
	void SendQueuedPackets()
	{
		if (send_packets)
		{
			for (const auto& pkt : choked_packets)
			{
				//send the packets
				if (conSock == INVALID_SOCKET)
					continue;
				iResult = send(conSock, pkt.first, pkt.second, 0);
				if (iResult == SOCKET_ERROR)
					continue;
				delete[] pkt.first;
			}
			choked_packets.clear();
		}
	}
}