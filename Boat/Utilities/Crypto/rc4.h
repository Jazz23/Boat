#pragma once
#include <vector>
#include "../Connection/PacketBuffer.h"


namespace RC4
{
	void SetupRC4(const std::vector<byte>& key);
	void Cipher(Packet::PacketBuffer* pb);
	void NewKey(const std::vector<byte>& ikey);
}
