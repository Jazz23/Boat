#include "PacketManager.h"

namespace PacketDeep
{
	int StartWinSock()
	{
		for (int i = 0; i < MAXIMUM_PACKET_BUFFER; i++)
			recvBuf[i] = 0;
		tPool = new PktThreadPool::PacketThreadPool();
		return WSAStartup(MAKEWORD(2, 2), &wsaData);
	}
	void StopWinSock()
	{
		delete tPool;
		shutdownListner = true;
		if (conSock != INVALID_SOCKET)
			closesocket(conSock);
		WSACleanup();
	}
	void SetupHints()
	{
		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
	}
	//call cleanup if result is not 0

	int Connect(const char* serverIp)
	{
		closesocket(conSock);
		conSock = INVALID_SOCKET;
		if (getaddrinfo(serverIp, DEFAULT_PORT, &hints, &result) != 0)
			return SOCKET_ERROR;
		for (auto ptr = result; ptr != nullptr; ptr = ptr->ai_next)
		{
			conSock = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
			if (conSock == INVALID_SOCKET)
				return INVALID_SOCKET;

			iResult = connect(conSock, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (iResult == SOCKET_ERROR)
			{
				closesocket(conSock);
				conSock = INVALID_SOCKET;
				continue;
			}
			break;
		}

		freeaddrinfo(result);
		if (conSock == INVALID_SOCKET)
			return INVALID_SOCKET;
	}
	void Listen()
	{
		while (true)
		{
			if (shutdownListner)
				return;
			if (conSock == INVALID_SOCKET) //postpone listner while our socket is invalid
				continue;
			iResult = recv(conSock, recvBuf, recvBufLen, 0);
			if (iResult > 0)
			{
				tPool->AddPacket(recvBuf, iResult);
			}
			else if (iResult == 0)
				std::cout << "Connection closed\n";
			else
				std::cout << "recv failed with error " << WSAGetLastError() << "\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
}