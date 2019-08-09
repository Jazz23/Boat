#pragma once
#include <vector>
#include <string>

#include "PacketBuffer.h"
#include "../Structurers/world_pos_data.h"
namespace Packet
{
	class BasePacket
	{
	public:
		PacketBuffer *pb;
		BasePacket(size_t size = 1024)
		{
			pb = new PacketBuffer(size);
		}
		BasePacket(char* buf, size_t size)
		{
			pb = new PacketBuffer(buf, size);
		}
		~BasePacket()
		{
			if (pb) delete pb;
		}
		virtual void WriteData() { return; }
		virtual void ReadData() { return; }
	};
	class IncommingPacket
	{
	public:
		PacketBuffer* pb;
		IncommingPacket(size_t size = 1024)
		{
			pb = new PacketBuffer(size);
		}
		IncommingPacket(char* buf, size_t size)
		{
			pb = new PacketBuffer(buf, size);
		}
		~IncommingPacket()
		{
			if (pb) delete pb;
		}
		virtual void ReadData() { return; }
	};
	class OutgoingPacket
	{
	public:
		PacketBuffer* pb;
		OutgoingPacket(size_t size = 1024)
		{
			pb = new PacketBuffer(size);
		}
		OutgoingPacket(char* buf, size_t size)
		{
			pb = new PacketBuffer(buf, size);
		}
		~OutgoingPacket()
		{
			if (pb) delete pb;
		}
		virtual void WriteData() { return; }
	};

	//incomming packets
	class AccountListPacket : IncommingPacket
	{
	public:
		int32_t accountListId;
		std::vector<std::string> accountIds;
		int32_t lookAction;
		AccountListPacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8(); //skip the packet id;
			accountListId = pb->ReadInt32();
			auto accountIdsLen = pb->ReadInt16();
			accountIds.resize(accountIdsLen);
			for (size_t i = 0; i < accountIdsLen; i++)
				accountIds.push_back(pb->ReadString());
			lookAction = pb->ReadInt32;
		}
	};
	class AllyShootPacket : IncommingPacket
	{
	public:
		uint8_t bulletID;
		int32_t ownerID;
		int16_t containerType;
		float angle;
		AllyShootPacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			bulletID = pb->ReadUnsignedInt8();
			ownerID = pb->ReadInt32();
			containerType = pb->ReadInt16();
			angle = pb->ReadFloat();
		}
	};
	class AoePacket : IncommingPacket
	{
	public:
		WorldPosData pos;
		float radius;
		uint16_t damage;
		uint8_t effect;
		float duration;
		uint16_t origType;
		int32_t color;
		AoePacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }

		void ReadData() override
		{
			pb->ReadInt8();
			pos.Read(pb);
			radius = pb->ReadFloat();
			damage = pb->ReadUnsignedInt16();
			effect = pb->ReadUnsignedInt8();
			duration = pb->ReadFloat();
			origType = pb->ReadUnsignedInt16();
			color == pb->ReadInt32();
		}
	};
	class BuyResultPacket : IncommingPacket
	{
	public:
		int32_t result;
		std::string resultString;
		BuyResultPacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }

		void ReadData() override
		{
			pb->ReadInt8();
			result = pb->ReadInt32();
			resultString = pb->ReadString();
		}
	};
	class ClaimDailyRewardResponse : IncommingPacket
	{
	public:
		int32_t itemID;
		int32_t quantity;
		int32_t gold; 
		ClaimDailyRewardResponse(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			itemID = pb->ReadInt32();
			quantity = pb->ReadInt32();
			gold = pb->ReadInt32();
		}
	};
	class ClientStatPacket : IncommingPacket
	{
	public:
		std::string name;
		int32_t value;
		ClientStatPacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			name = pb->ReadString();
			value = pb->ReadInt32();
		}
	};
	class CreateSuccessPacket : IncommingPacket
	{
	public:
		int32_t objectID;
		int32_t charID;
		CreateSuccessPacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			objectID = pb->ReadInt32();
			charID = pb->ReadInt32();
		}
	};
	class DamagePacket : IncommingPacket
	{
	public:
		int32_t targetID;
		std::vector<uint8_t> effects;
		uint16_t damageAmount;
		bool kill, armorPierce;
		uint8_t bulletID;
		int32_t objectID;
		DamagePacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			targetID = pb->ReadInt32();
			size_t effectsLen = pb->ReadUnsignedInt8();
			effects.resize(effectsLen);
			for (int i = 0; i < effectsLen; i++)
				effects.push_back(pb->ReadUnsignedInt8());
			damageAmount = pb->ReadUnsignedInt16();
			kill = pb->ReadBoolean();
			armorPierce = pb->ReadBoolean();
			bulletID = pb->ReadUnsignedInt8();
			objectID = pb->ReadInt32();
		}
	};
	class EnemyShootPacket : IncommingPacket
	{
	public:
		uint8_t bulletID;
		int32_t ownerID;
		uint8_t bulletType;
		WorldPosData startingPos;
		float angle;
		uint16_t damage;
		uint8_t numShots;
		float angleInc;
		EnemyShootPacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			bulletID = pb->ReadUnsignedInt8();
			ownerID = pb->ReadInt32();
			bulletType = pb->ReadUnsignedInt8();
			startingPos.Read(pb);
			angle = pb->ReadFloat();
			damage = pb->ReadInt16();
			if (pb->index < pb->size)
			{
				numShots = pb->ReadUnsignedInt8();
				angleInc = pb->ReadFloat();
			}
			else
			{
				numShots = 1;
				angle = 0;
			}
		}
	};
	class FailurePacket : IncommingPacket
	{
	public:
		int32_t errorID;
		std::string errorDesc;
		FailurePacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			errorID = pb->ReadInt32();
			errorDesc = pb->ReadString();
		}
	};
	class GlobalNotificationPacket : IncommingPacket
	{
	public:
		int32_t notificationType;
		std::string text;
		GlobalNotificationPacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			notificationType = pb->ReadInt32();
			text = pb->ReadString();
		}
	};
	class GotoPacket : IncommingPacket
	{
	public:
		int32_t objectID;
		WorldPosData pos;
		GotoPacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			pb->ReadInt32();
			pos.Read(pb);
		}
	};
	class GuildResultPacket : IncommingPacket
	{
	public:
		bool success;
		std::string lineBuilderJSON;
		GuildResultPacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			success = pb->ReadBoolean();
			lineBuilderJSON = pb->ReadString();
		}
	};
	class InviteResultPacket : IncommingPacket
	{
	public:
		int32_t result;
		InviteResultPacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			result = pb->ReadInt32();
		}
	};
	class InvitedToGuildPacket : IncommingPacket
	{
	public:
		std::string name, guildName;
		InvitedToGuildPacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			name = pb->ReadString();
			guildName = pb->ReadString();
		}
	};
	class KeyInfoResponsePacket : IncommingPacket
	{
	public:
		std::string name, desc, creator;
		KeyInfoResponsePacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			name = pb->ReadString();
			desc = pb->ReadString();
			creator = pb->ReadString();
		}
	};
	class MapInfoPacket : IncommingPacket
	{
	public:
		int32_t width, height;
		std::string name, displayName;
		uint32_t fp;
		int32_t background, difficulty;
		bool allowPlayerTeleport;
		bool showDisplays;
		std::vector<std::u32string> clientXML;
		std::vector<std::u32string> extraXML;
		MapInfoPacket(char* pkt, size_t size) : IncommingPacket(pkt, size) { }
		void ReadData() override
		{
			pb->ReadInt8();
			width = pb->ReadInt32();
			height = pb->ReadInt32();
			name = pb->ReadString();
			displayName = pb->ReadString();
			fp = pb->ReadUnsignedInt32();
			background = pb->ReadInt32();
			difficulty = pb->ReadInt32();
			allowPlayerTeleport = pb->ReadBoolean();
			showDisplays = pb->ReadBoolean();
			size_t sz = pb->ReadInt16();
			clientXML.resize(sz);
			for (size_t i = 0; i < sz; i++)
				clientXML.push_back(pb->ReadStringUTF32());
			sz = pb->ReadInt16();
			extraXML.resize(sz);
			for (size_t i = 0; i < sz; i++)
				extraXML.push_back(pb->ReadStringUTF32());
		}
	};


}