#pragma once
#include <cstring>
#include <mutex>
#include <thread>
#include "../../Connection/Packet/PacketBuffer.h"

typedef unsigned char byte;
#define KEYSIZE 13
constexpr byte INCOMING_KEY[] = { 0xc7, 0x93, 0x32, 0xb1, 0x97, 0xf9, 0x2b, 0xa8, 0x5e, 0xd2, 0x81, 0xa0, 0x23 };
constexpr byte OUTGOING_KEY[] = { 0x6a, 0x39, 0x57, 0x0c, 0xc9, 0xde, 0x4e, 0xc7, 0x1d, 0x64, 0x82, 0x18, 0x94 };
RC4::Encrypt Incoming(true);
RC4::Encrypt Outgoing(false);
std::mutex incoming_mutex, outgoing_mutex;

namespace RC4
{
	void Cipher(Packet::PacketBuffer* pb, bool incoming)
	{
		if (incoming)
		{
			std::lock_guard<std::mutex> g(incoming_mutex);
			Incoming.Cipher(pb);
		}
		else
		{
			std::lock_guard<std::mutex> g(outgoing_mutex);
			Outgoing.Cipher(pb);
		}
	}

	class Encrypt
	{
	public:
		byte state[256];
		byte key[KEYSIZE];
		byte i, j;

		Encrypt(bool incoming)
		{
			i = 0;
			j = 0;

			memcpy(key, incoming ? INCOMING_KEY : OUTGOING_KEY, KEYSIZE);

			for (int i = 0; i < 256; i++)
			{
				state[i] = i;
			}

			for (int i = 0; i < 256; i++)
			{
				j = (j + state[i] + key[i % KEYSIZE]) % 256;
				const byte tmp = state[i];
				state[i] = state[j];
				state[j] = tmp;
			}
		}

		void Cipher(Packet::PacketBuffer* pb)
		{
			for (size_t n; n < pb->size; n++)
			{
				i = (i + 1) % 256;
				j = (j + state[i]) % 256;
				const byte tmp = state[i];
				state[i] = state[j];
				state[j] = tmp;
				const byte k = state[(state[i] + state[j]) % 256];
				pb->buffer[n] ^= k;
			}
		}
	};
}