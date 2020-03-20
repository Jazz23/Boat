#include "PacketManager.h"
#include "../../Utilities/Logger/Log.h"
#include "../Packet/PacketBuffer.h"
#include "Socket/socket.hpp"

namespace Client
{
	int __CLIENT::StartClient()
	{

	}
	void __CLIENT::Disconnect()
	{
		std::lock_guard<std::mutex> g(clientMutex);
		if (client)
		{
			client->close();
			delete client;
		}
	}
	int __CLIENT::Connect(const char* serverIp)
	{
		std::lock_guard<std::mutex> g(clientMutex);
		if (client)
		{
			client->close();
			delete client;
			client = new tcp_client_t(serverIp, DEFAULT_PORT);
			return client->connect();
		}
		return -1;
	}
	[[noreturn]] void __CLIENT::operator()()
	{
		while (!shutdownListner)
		{
			std::lock_guard<std::mutex> g(clientMutex);

			if (!client) continue;
			int pktSize = 0;
			client->read_all(&pktSize, sizeof(int));
			Packet::PacketBuffer packet(pktSize);
			client->read_all(packet.buffer, pktSize);
			PacketIn(&packet);
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
}