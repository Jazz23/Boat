#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>

#include "Packets.h"
#include "PacketBuffer.h"
#include "ThreadPool/ThreadPool.h"

//IF WINSOCK DOES NOT WORK USE THIS, ITS A WINSOCK WRAPPER
//https://github.com/pedro-vicente/lib_netsockets

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define QUEUE_PACKET		(1<<0)
#define SEND_PACKET_NOW		(1<<1)
#define SEND_ENTIRE_QUEUE	(1<<2)

#define BAD_FLAGS			1
#define BAD_PACKET_ARRAY	2
#define ASSUMED_FAILURE		3 //for if we dont get any code from tcp
#define ASSUMED_SUCCESS		4

#define MAXIMUM_PACKET_BUFFER	1000000
#define DEFAULT_PORT			"27015"

namespace PacketDeep
{
	inline WSADATA wsaData;
	inline SOCKET conSock = INVALID_SOCKET;
	inline addrinfo* result = nullptr, * ptr = nullptr, hints;
	inline char recvBuf[MAXIMUM_PACKET_BUFFER];
	inline size_t recvBufLen = MAXIMUM_PACKET_BUFFER;
	inline int iResult = 0;
	inline std::mutex packetMutex;

	inline std::vector<std::pair<char*, size_t> > choked_packets;
	inline bool send_packets = true;
	inline PktThreadPool::PacketThreadPool* tPool = nullptr;
	inline bool shutdownListner = false;

	bool badFlags(unsigned long flags);
	int SendPacket(const Packet::PacketBuffer& pkt, unsigned long flags);
	int SendPacket(char* pkt, size_t sz, unsigned long flags);
	int SendQueuedPackets();

	int StartWinSock();
	void StopWinSock();
	void SetupHints();
	int Connect(const char* serverIp);
	void Listen();
}
namespace Packet
{
	void PacketOut(OutgoingPacket& pkt);
	void HandlePacket(char* pkt, size_t sz);
}