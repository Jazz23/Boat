#pragma once
#include <algorithm>
#include <fstream>
#include <string>

namespace RC4
{
	#define KEYSIZE 13
	constexpr unsigned char INCOMING_KEY[] = { 0xc7, 0x93, 0x32, 0xb1, 0x97, 0xf9, 0x2b, 0xa8, 0x5e, 0xd2, 0x81, 0xa0, 0x23 };
	constexpr unsigned char OUTGOING_KEY[] = { 0x6a, 0x39, 0x57, 0x0c, 0xc9, 0xde, 0x4e, 0xc7, 0x1d, 0x64, 0x82, 0x18, 0x94 };

	void EncDec(unsigned char* data, size_t length, bool incoming, size_t index = 5)
	{
		unsigned char* key = new unsigned char[13];
		memcpy(key, incoming ? INCOMING_KEY : OUTGOING_KEY, KEYSIZE);

		unsigned char S[256];
		int i = 0, j = 0;
		for (i = 0; i < 256; i++)
			S[i] = i;
		for (i = 0; i < 256; i++)
		{
			j = (j + S[i] + key[i % KEYSIZE]) % 256;
			std::swap(S[i], S[j]);
		}
		char x;
		j = 0;
		i = 0;
		std::string output;
		for (int k = index; k < (int)length; k++)
		{
			x = (char)data[k];
			i = (i + 1) % 256;
			j = (j + S[i]) % 256;
			std::swap(S[i], S[j]);
			char temp = S[(S[i] + S[j]) % 256] ^ x;
			data[k] = temp;
		}

		delete[] key;
	}
}