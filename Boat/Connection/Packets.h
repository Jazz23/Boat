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
		virtual void WriteData(PacketBuffer *pb) { return; }
		virtual void ReadData(PacketBuffer *pb) { return; }
	};

	class IncomingPacket
	{
	public:
		virtual void ReadData(PacketBuffer* pb) { return; }
	};

	class OutgoingPacket
	{
	public:
		virtual void WriteData(PacketBuffer* pb) { return; }
	};

#pragma region incomming
	class AccountListPacket : IncomingPacket
	{
	public:
		int32_t accountListId;
		std::vector<std::string> accountIds;
		int32_t lookAction;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			accountListId = pb->ReadInt32();
			auto accountIdsLen = pb->ReadInt16();
			accountIds.resize(accountIdsLen);
			for (size_t i = 0; i < accountIdsLen; i++)
				accountIds.push_back(pb->ReadString());
			lookAction = pb->ReadInt32;
		}
	};
	class AllyShootPacket : IncomingPacket
	{
	public:
		uint8_t bulletID;
		int32_t ownerID;
		int16_t containerType;
		float angle;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			bulletID = pb->ReadUnsignedInt8();
			ownerID = pb->ReadInt32();
			containerType = pb->ReadInt16();
			angle = pb->ReadFloat();
		}
	};
	class AoePacket : IncomingPacket
	{
	public:
		WorldPosData pos;
		float radius;
		uint16_t damage;
		uint8_t effect;
		float duration;
		uint16_t origType;
		int32_t color;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			pos.Read(pb);
			radius = pb->ReadFloat();
			damage = pb->ReadUnsignedInt16();
			effect = pb->ReadUnsignedInt8();
			duration = pb->ReadFloat();
			origType = pb->ReadUnsignedInt16();
			color == pb->ReadInt32();
		}
	};
	class BuyResultPacket : IncomingPacket
	{
	public:
		int32_t result;
		std::string resultString;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			result = pb->ReadInt32();
			resultString = pb->ReadString();
		}
	};
	class ClaimDailyRewardResponse : IncomingPacket
	{
	public:
		int32_t itemID;
		int32_t quantity;
		int32_t gold;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			itemID = pb->ReadInt32();
			quantity = pb->ReadInt32();
			gold = pb->ReadInt32();
		}
	};
	class ClientStatPacket : IncomingPacket
	{
	public:
		std::string name;
		int32_t value;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			name = pb->ReadString();
			value = pb->ReadInt32();
		}
	};
	class CreateSuccessPacket : IncomingPacket
	{
	public:
		int32_t objectID;
		int32_t charID;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			objectID = pb->ReadInt32();
			charID = pb->ReadInt32();
		}
	};
	class DamagePacket : IncomingPacket
	{
	public:
		int32_t targetID;
		std::vector<uint8_t> effects;
		uint16_t damageAmount;
		bool kill, armorPierce;
		uint8_t bulletID;
		int32_t objectID;

		void ReadData(PacketBuffer *pb) override
		{
			if (!pb) return;
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
	class EnemyShootPacket : IncomingPacket
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

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
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
	class FailurePacket : IncomingPacket
	{
	public:
		int32_t errorID;
		std::string errorDesc;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			errorID = pb->ReadInt32();
			errorDesc = pb->ReadString();
		}
	};
	class GlobalNotificationPacket : IncomingPacket
	{
	public:
		int32_t notificationType;
		std::string text;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			notificationType = pb->ReadInt32();
			text = pb->ReadString();
		}
	};
	class GotoPacket : IncomingPacket
	{
	public:
		int32_t objectID;
		WorldPosData pos;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			pb->ReadInt32();
			pos.Read(pb);
		}
	};
	class GuildResultPacket : IncomingPacket
	{
	public:
		bool success;
		std::string lineBuilderJSON;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			success = pb->ReadBoolean();
			lineBuilderJSON = pb->ReadString();
		}
	};
	class InviteResultPacket : IncomingPacket
	{
	public:
		int32_t result;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			result = pb->ReadInt32();
		}
	};
	class InvitedToGuildPacket : IncomingPacket
	{
	public:
		std::string name, guildName;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			name = pb->ReadString();
			guildName = pb->ReadString();
		}
	};
	class KeyInfoResponsePacket : IncomingPacket
	{
	public:
		std::string name, desc, creator;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			name = pb->ReadString();
			desc = pb->ReadString();
			creator = pb->ReadString();
		}
	};
	class MapInfoPacket : IncomingPacket
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

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
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
	class NameResultPacket : IncomingPacket
	{
	public:
		bool success;
		std::string errorText;

		void ReadData(PacketBuffer *pb) override
		{
			if (!pb) return;
			success = pb->ReadBoolean();
			errorText = pb->ReadString();
		}
	};

	class NewAbilityMessage : IncomingPacket
	{
	public:
		int abilityType;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			abilityType = pb->ReadInt32();
		}
	};

	class NewTickPacket : IncomingPacket
	{
		int tickId;
		int tickTime;
		ObjectStatusData statuses;
	};

#pragma endregion

#pragma region outgoingpackets

	class AcceptTradePacket : OutgoingPacket
	{
		std::vector<bool> partnerOffer, clientOffer;
		void WriteData(PacketBuffer* pb) override
		{
			pb->WriteInt16(clientOffer.size());
			for (auto c : clientOffer)
				pb->WriteBoolean(c);
			pb->WriteInt16(partnerOffer.size());
			for (auto c : partnerOffer)
				pb->WriteBoolean(c);
		}
	};

#pragma endregion
}