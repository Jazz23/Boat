#pragma once

#define WIN32_LEAN_AND_MEAN

#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>

#include "Socket/socket.hpp"
#include "../Packet/Packets.h"
#include "../Packet/PacketBuffer.h"
#include "../../Utilities/Logger/Log.h"

//https://github.com/pedro-vicente/lib_netsockets


#define QUEUE_PACKET		(1<<0)
#define SEND_PACKET_NOW		(1<<1)
#define SEND_ENTIRE_QUEUE	(1<<2)

#define BAD_FLAGS			1
#define BAD_PACKET_ARRAY	2
#define ASSUMED_FAILURE		3 //for if we dont get any code from tcp
#define ASSUMED_SUCCESS		4
#define FAILED_PACKET_SEND	5

#define MAXIMUM_PACKET_BUFFER	1000000
#define DEFAULT_PORT			2050

namespace Packet
{
	void PacketOut(OutgoingPacket& pkt);
	void PacketIn(PacketBuffer* packet);
}
namespace PacketDeep
{

	inline std::vector<std::pair<char*, size_t> > choked_packets;
	inline bool shutdownListner = false;

	inline std::mutex clientMutex;
	inline tcp_client_t* client = nullptr;

	bool badFlags(unsigned long flags);
	int SendPacket(const Packet::PacketBuffer& pkt, unsigned long flags);
	int SendPacket(unsigned char* pkt, size_t sz, unsigned long flags);
	int SendQueuedPackets();

	int StartClient();
	void StopClient();
	int Connect(const char* serverIp);
	void Listen();
}