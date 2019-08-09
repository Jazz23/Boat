#include <vector>
#include <string>

#include "Packets.h"
#include "PacketBuffer.h"
#include "../Structures/NetworkData/world_pos_data.h"
#include "../Structures/NetworkData/object_status_data.h"


namespace Packet
{

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
		uint8_t bulletId;
		int32_t ownerId;
		int16_t containerType;
		float angle;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			bulletId = pb->ReadUnsignedInt8();
			ownerId = pb->ReadInt32();
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
			pos.ReadData(pb);
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
		int32_t itemId;
		int32_t quantity;
		int32_t gold;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			itemId = pb->ReadInt32();
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
		int32_t objectId;
		int32_t charId;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			objectId = pb->ReadInt32();
			charId = pb->ReadInt32();
		}
	};
	class DamagePacket : IncomingPacket
	{
	public:
		int32_t targetId;
		std::vector<uint8_t> effects;
		uint16_t damageAmount;
		bool kill, armorPierce;
		uint8_t bulletId;
		int32_t objectId;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			targetId = pb->ReadInt32();
			size_t effectsLen = pb->ReadUnsignedInt8();
			effects.resize(effectsLen);
			for (int i = 0; i < effectsLen; i++)
				effects.push_back(pb->ReadUnsignedInt8());
			damageAmount = pb->ReadUnsignedInt16();
			kill = pb->ReadBoolean();
			armorPierce = pb->ReadBoolean();
			bulletId = pb->ReadUnsignedInt8();
			objectId = pb->ReadInt32();
		}
	};
	class EnemyShootPacket : IncomingPacket
	{
	public:
		uint8_t bulletId;
		int32_t ownerId;
		uint8_t bulletType;
		WorldPosData startingPos;
		float angle;
		uint16_t damage;
		uint8_t numShots;
		float angleInc;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			bulletId = pb->ReadUnsignedInt8();
			ownerId = pb->ReadInt32();
			bulletType = pb->ReadUnsignedInt8();
			startingPos.ReadData(pb);
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
		int32_t errorId;
		std::string errorDesc;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			errorId = pb->ReadInt32();
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
		int32_t objectId;
		WorldPosData pos;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			pb->ReadInt32();
			pos.ReadData(pb);
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

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			success = pb->ReadBoolean();
			errorText = pb->ReadString();
		}
	};

	class NewAbilityMessage : IncomingPacket
	{
	public:
		int32_t abilityType;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			abilityType = pb->ReadInt32();
		}
	};

	class NewTickPacket : IncomingPacket
	{
	public:
		int32_t tickId;
		int32_t tickTime;
		std::vector<ObjectStatusData> statuses;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			tickId = pb->ReadInt32();
			tickTime = pb->ReadInt32();
			const size_t statusesLen = pb->ReadInt16();
			statuses.resize(statusesLen);
			for (int i = 0; i < statusesLen; i++)
			{
				ObjectStatusData osd;
				osd.ReadData(pb);
				statuses.push_back(osd);
			}
		}
	};

	class NotificationPacket : IncomingPacket
	{
	public:
		int32_t objectId;
		std::string message;
		int32_t color;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			objectId = pb->ReadInt32();
			message = pb->ReadString();
			color = pb->ReadInt32();
		}
	};

	class PasswordPromptPacket : IncomingPacket
	{
		int32_t cleanPasswordStatus;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			cleanPasswordStatus = pb->ReadInt32();
		}
	};

	class PingPacket : IncomingPacket
	{
		int32_t serial;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			serial = pb->ReadInt32();
		}
	};

	class QuestObjectIdPacket : IncomingPacket
	{
		int32_t objectId;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			objectId = pb->ReadInt32();
		}
	};

	class QuestRedeemResponsePacket : IncomingPacket
	{
		bool ok;
		std::string message;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			ok = pb->ReadBoolean();
			message = pb->ReadString();
		}
	};

	class RealmHeroLeftMessage : IncomingPacket
	{
		int32_t realmHeroesLeft;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			realmHeroesLeft = pb->ReadInt32();
		}
	};

	class ReconnectPacket : IncomingPacket
	{
		std::string name, host, stats;
		int32_t port, gameId, keyTime;
		std::vector<int32_t> key;
		bool isFromArena;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			name = pb->ReadString();
			host = pb->ReadString();
			stats = pb->ReadString();
			port = pb->ReadInt32();
			gameId = pb->ReadInt32();
			keyTime = pb->ReadInt32();
			isFromArena = pb->ReadBoolean();
			key = pb->ReadByteArray();
		}
	};

	class ReskinUnlockPacket : IncomingPacket
	{
		int32_t skinId;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			skinId = pb->ReadInt32();
		}
	};

	class ServerPlayerShootPacket : IncomingPacket
	{
		int32_t bulletId, ownerId, containerType;
		WorldPosData startingPos;
		int32_t angle, damage;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			bulletId = pb->ReadUnsignedInt8();
			ownerId = pb->ReadInt32();
			containerType = pb->ReadInt32();
			WorldPosData startingPos;

	};
}