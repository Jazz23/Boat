#include "PacketManager.h"

namespace PacketDeep
{
	int StartWinSock()
	{
		for (int i = 0; i < MAXIMUM_PACKET_BUFFER; i++)
			recvBuf[i] = 0;
		return WSAStartup(MAKEWORD(2, 2), &wsaData);
	}
	void SetupHints()
	{
		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
	}
	//call cleanup if result is not 0
	int FillAddrInfo(const char* serverIp)
	{
		return getaddrinfo(serverIp, DEFAULT_PORT, &hints, &result);
	}
	int Connect()
	{
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
			iResult = recv(conSock, recvBuf, recvBufLen, 0);
			if (iResult > 0)
				printf("Bytes received: %d\n", iResult);
			else if (iResult == 0)
				printf("Connection closed\n");
			else
				printf("recv failed with error: %d\n", WSAGetLastError());
		}
	}
}