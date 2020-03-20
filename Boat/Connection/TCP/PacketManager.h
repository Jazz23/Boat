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
#include "../../Utilities/Hook/Hook.h"

//https://github.com/pedro-vicente/lib_netsockets


#define QUEUE_PACKET		(1<<0)
#define SEND_PACKET_NOW		(1<<1)
#define SEND_ENTIRE_QUEUE	(1<<2)

#define SEND_FAILURE		-1
#define SEND_SUCCESS		1

#define MAXIMUM_PACKET_BUFFER	1000000
#define DEFAULT_PORT			2050

namespace Client
{
	typedef class __CLIENT
	{
	private:
		std::vector<std::pair<char*, size_t> > choked_packets;
		bool shutdownListner = false;

		std::mutex clientMutex;
		tcp_client_t* client;
		Hook::PHOOKS hookContext;
	public:
		__CLIENT()
		{
			choked_packets.clear();
			client = nullptr;
			hookContext = new Hook::HOOKS();
		}
		~__CLIENT()
		{
			if (hookContext) delete hookContext;
		}

		bool BadFlags(unsigned long flags);
		void SendPacket(const Packet::PacketBuffer& pkt, unsigned long flags);
		void SendPacket(unsigned char* pkt, size_t sz, unsigned long flags);
		void SendQueuedPackets();

		int StartClient();
		void Disconnect();
		int Connect(const char* serverIp);
		[[noreturn]] void operator()();	//listener


		void PacketOut(Packet::OutgoingPacket& pkt);
		void PacketIn(Packet::PacketBuffer* packet);

	}Client, * pClient;
}