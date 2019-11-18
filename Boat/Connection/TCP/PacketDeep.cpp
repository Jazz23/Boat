#include "PacketManager.h"
#include "../../Utilities/Logger/Logger.h"
#include "../Packet/PacketBuffer.h"
#include "Socket/socket.hpp"

namespace PacketDeep
{
	
	int StartClient()
	{
		client = new tcp_client_t("", DEFAULT_PORT);
		return client->connect();
	}
	void StopClient()
	{
		if (client)
		{
			client->close();
			delete client;
		}
	}
	int Connect(const char* serverIp)
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
	void Listen()
	{
		while (!shutdownListner)
		{
			std::lock_guard<std::mutex> g(clientMutex);

			if (!client) continue;
			int pktSize = 0;
			client->read_all(&pktSize, sizeof(int));
			Packet::PacketBuffer packet(pktSize);
			client->read_all(packet.buffer, pktSize);
			Packet::PacketIn(&packet);
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
}