#include "database.h"


#include <mutex>
#include <vector>

namespace DB
{
	std::mutex dbLock;
	std::vector<PLAYER_PROFILE> players;

	void __fastcall Load(std::string_view filepath)
	{
		std::lock_guard<std::mutex> g(dbLock);
		Packet::PacketBuffer* pb = new Packet::PacketBuffer();
		size_t dbSize = 1000; //<=- Replace with correct value after u load.
	
		players.clear();
		players.resize(dbSize / 28);

		if (players.size() < 1)
			exit(0x3);

		size_t i = 0;
		while (pb->index < pb->size)
		{
			players[i].ReadData(pb);

			if (i++; i > players.size())
				players.resize(players.size() * 1.5);
		}
	}
	void Save()
	{
		std::lock_guard<std::mutex> g(dbLock);
		Packet::PacketBuffer* pb = new Packet::PacketBuffer();
	}
}