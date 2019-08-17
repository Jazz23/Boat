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

#include "../Packet/Packets.h"
#include "../Packet/PacketBuffer.h"
#include "../../Utilities/Logger/Logger.h"

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

namespace Packet
{
	void PacketOut(OutgoingPacket& pkt);
	void HandlePacket(char* pkt, size_t sz);
	class oThread
	{
	public:
		bool stop;
	private:
		bool busy;
		char* pkt;
		size_t sz;
		std::mutex	m;
	public:
		void SetPacket(char* _pkt, size_t _sz)
		{
			std::lock_guard<std::mutex> g(m);
			busy = true;
			sz = _sz;
			pkt = new char[sz];
			memcpy(pkt, _pkt, sz);
		}
		bool getBusy() const { return busy; }
		oThread() : busy(false), stop(false)
		{

		}
		void operator()()
		{
			while (true)
			{
				if (stop) break;
				if (busy && pkt && sz > 0)
				{
					std::lock_guard<std::mutex> g(m);
					Packet::HandlePacket(pkt, sz);
					delete[] pkt;
					pkt = nullptr;
					sz = 0;
					busy = false;
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(5));
			}
		}
	};
	class PacketThreadPool
	{
	private:
		const unsigned short numOfThreads;
		std::vector<oThread> ourThreads;
	public:
		PacketThreadPool() : numOfThreads(std::thread::hardware_concurrency() - 1)
		{
			if (numOfThreads < 1)
			{
				std::cout << "COULD NOT DETECT CPU CORE COUNT BIG ERROR\n";
				system("pause");
			}
			ourThreads.clear();
			for (int i = 0; i < numOfThreads; i++)
				ourThreads.emplace_back();
			for (size_t s = 0; s < ourThreads.size(); s++)
			{
				Logger::Log("starting incomming packet thread" + std::to_string(s));
				std::thread t(ourThreads[s]);
				t.detach();
			}
		}
		~PacketThreadPool()
		{
			for (auto& c : ourThreads)
				c.stop = true;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
		}
		bool AddPacket(char* pkt, size_t sz)
		{
			bool should_stay = true;
			while (should_stay)
			{
				for (auto& c : ourThreads)
				{
					if (!c.getBusy())
					{
						c.SetPacket(pkt, sz);
						should_stay = false;
						break;
					}
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
		}
	};
	inline PacketThreadPool* tPool = nullptr;
}
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
	inline bool shutdownListner = false;

	bool badFlags(unsigned long flags);
	int SendPacket(const Packet::PacketBuffer& pkt, unsigned long flags);
	int SendPacket(unsigned char* pkt, size_t sz, unsigned long flags);
	int SendQueuedPackets();

	int StartWinSock();
	void StopWinSock();
	void SetupHints();
	int Connect(const char* serverIp);
	void Listen();
}