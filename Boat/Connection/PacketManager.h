#pragma once
#include <chrono>
#include <vector>

#include "PacketBuffer.h"
namespace Packet
{
	std::chrono::time_point tick_start, tick_end;
	float tick_time;
	constexpr int tick_delay = 5;
	std::vector<std::pair<char*, size_t> > choked_packets;
	bool send_packets = true;
	void SendPacket(char* pkt, size_t sz);
	void SendPacket(const PacketBuffer& pkt);
	void Send();
	void HandlePacket(char* pkt, size_t sz);
}