#pragma once
#include <vector>
#include "../Connection/PacketBuffer.h"
typedef unsigned char byte;


namespace RC4
{
	byte state[256];
	std::vector<byte> key;
	byte i, j;

	void SetupRC4(const std::vector<byte> &key)
	{
		i = j = 0;
	}
	void cipher(Packet::PacketBuffer* pb)
	{
		for (size_t i = 0; i < pb->index + 1; i++)
		{
			byte& b = pb->buffer[i];

		}
	}
}
class RC4
{
public:

	RC4(std::vector<byte> key) : key(key), i(0), j(0)
	{

	}

	void cipher(Packet::PacketBuffer *pb)
	{
		for (size_t i = 0; i < pb->index + 1; i++)
		{
			byte &b = pb->buffer[i];

		}
	}
private:
	byte state[256];
	std::vector<byte> key;
	byte i, j;

	void memes()
	{

	}
};