#include "rc4.h"

typedef unsigned char byte;

namespace RC4
{
	byte state[256];
	std::vector<byte> key;
	byte i, j;

	void SetupRC4(const std::vector<byte>& ikey)
	{
		i = j = 0;
		size_t sz = ikey.size();
		key.resize(sz);
		key.clear();
		for (size_t i = 0; i < sz; i++)
			key[i] = ikey[i];
	}
	void SetDefaultKey() //set the key = to the default rotmg key you will use this alot
	{

	}
	void NewKey(const std::vector<byte>& ikey)
	{
		size_t sz = ikey.size();
		key.resize(sz);
		key.clear();
		for (size_t i = 0; i < sz; i++)
			key[i] = ikey[i];
	}
	void Cipher(Packet::PacketBuffer* pb)
	{
		for (size_t i = 0; i < pb->index + 1; i++)
		{
			byte& b = pb->buffer[i];

		}
	}
}