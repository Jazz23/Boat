#include "PacketManager.h"


namespace Packet
{
	void HandlePacket(char* pkt, size_t sz)
	{
		switch (pkt[0])
		{
			//use [[likely]] for stuff like update ping and pong
		}
	}
}