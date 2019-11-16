#pragma once
#include "../../Boat/Connection/Packet/PacketBuffer.h"


#include <string>
#include <string_view>


namespace DB
{
	typedef struct _PLAYER_PROFILE
	{
		struct _realm
		{
			std::string name;
			int fame;
		} realm;
		struct _discord
		{
			std::string name;
			int number;
		} discord;
		void ReadData(Packet::PacketBuffer* pb)
		{
			realm.name = pb->ReadString();		//10
			realm.fame = pb->ReadInt32();		//4
			discord.name = pb->ReadString();	//10
			discord.number = pb->ReadInt32();	//4		= 28
		}
		void WriteData(Packet::PacketBuffer* pb)
		{
			pb->WriteString(realm.name);
			pb->WriteInt32(realm.fame);
			pb->WriteString(discord.name);
			pb->WriteInt32(discord.number);
		}
	}PLAYER_PROFILE, *pPLAYER_PROFILE;

	void __fastcall Load(std::string_view filepath);
	void			Save();
}
