#include <vector>
#include <string>

#include "Packets.h"
#include "PacketBuffer.h"
#include "../../Structures/NetworkData/world_pos_data.h"
#include "../../Structures/NetworkData/object_status_data.h"
#include "../../Structures/trade_result.h"
#include "../../Structures/NetworkData/trade_item.h"
#include "../../Structures/NetworkData/ground_tile_data.h"


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
			for (int16_t i = 0; i < accountIdsLen; i++)
				accountIds.push_back(pb->ReadString());
			lookAction = pb->ReadInt32();
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
			color = pb->ReadInt32();
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
			for (size_t i = 0; i < effectsLen; i++)
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
			objectId = pb->ReadInt32();
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
			for (size_t i = 0; i < statusesLen; i++)
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
	public:
		int32_t cleanPasswordStatus;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			cleanPasswordStatus = pb->ReadInt32();
		}
	};

	class PingPacket : IncomingPacket
	{
	public:
		int32_t serial;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			serial = pb->ReadInt32();
		}
	};

	class QuestObjectIdPacket : IncomingPacket
	{
	public:
		int32_t objectId;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			objectId = pb->ReadInt32();
		}
	};

	class QuestRedeemResponsePacket : IncomingPacket
	{
	public:
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
	public:
		int32_t realmHeroesLeft;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			realmHeroesLeft = pb->ReadInt32();
		}
	};

	class ReconnectPacket : IncomingPacket
	{
	public:
		std::string name, host, stats;
		int32_t port, gameId, keyTime;
		std::vector<unsigned char> key;
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
			pb->ReadByteArrayEx(key);
		}
	};

	class ReskinUnlockPacket : IncomingPacket
	{
	public:
		int32_t skinId;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			skinId = pb->ReadInt32();
		}
	};

	class ServerPlayerShootPacket : IncomingPacket
	{
	public:
		uint8_t bulletId;
		int32_t ownerId, containerType;
		WorldPosData startingPos;
		int32_t angle, damage;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			bulletId = pb->ReadUnsignedInt8();
			ownerId = pb->ReadInt32();
			containerType = pb->ReadInt32();
			WorldPosData startingPos;
			startingPos.ReadData(pb);
		}
	};

	class ShowEffectPacket : IncomingPacket
	{
	public:
		uint8_t effectType;
		int32_t targetObjectId;
		WorldPosData pos1, pos2;
		int32_t color;
		float_t duration;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			effectType = pb->ReadUnsignedInt8();
			targetObjectId = pb->ReadInt32();
			WorldPosData pos1, pos2;
			pos1.ReadData(pb);
			pos2.ReadData(pb);
			color = pb->ReadInt32();
			duration = pb->ReadFloat();
		}
	};

	class TextPacket : IncomingPacket
	{
	public:
		std::string name;
		int32_t objectId, numStars;
		uint8_t bubbleTime;
		std::string recipient, text, cleanText;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			name = pb->ReadString();
			objectId = pb->ReadInt32();
			numStars = pb->ReadInt32();
			bubbleTime = pb->ReadUnsignedInt8();
			recipient = pb->ReadString();
			text = pb->ReadString();
			cleanText = pb->ReadString();
		}
	};
	class DeathPacket : IncomingPacket
	{
	public:
		std::string accountId;
		int32_t charId;
		std::string killedBy;
		int32_t zombieType, zombieId;
		bool isZombie;
		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			accountId = pb->ReadString();
			charId = pb->ReadInt32();
			killedBy = pb->ReadString();
			zombieType = pb->ReadInt32();
			zombieId = pb->ReadInt32();
			isZombie = !!(zombieId != -1);
		}
	};
	class TradeAcceptedPacket : IncomingPacket
	{
	public:
		std::vector<bool> clientOffer, partnerOffer;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			const size_t clientOfferLen = pb->ReadInt16();
			clientOffer.resize(clientOfferLen);
			for (size_t i = 0; i < clientOfferLen; i++)
				clientOffer.push_back(pb->ReadBoolean());
			const size_t partnerOfferLen = pb->ReadInt16();
			partnerOffer.resize(partnerOfferLen);
			for (size_t i = 0; i < partnerOfferLen; i++)
				partnerOffer.push_back(pb->ReadBoolean());
		}
	};

	class TradeChangedPacket : IncomingPacket
	{
	public:
		std::vector<bool> offer;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			const size_t offerLen = pb->ReadInt16();
			offer.resize(offerLen);
			for (size_t i = 0; i < offerLen; i++)
				offer.push_back(pb->ReadBoolean());
		}
	};

	class TradeDonePacket : IncomingPacket
	{
	public:
		TradeResult code;
		std::string description;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			code = (TradeResult)pb->ReadInt32();
			description = pb->ReadString();
		}
	};

	class TradeRequestedPacket : IncomingPacket
	{
	public:
		std::string name;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			name = pb->ReadString();
		}
	};

	class TradeStartPacket : IncomingPacket
	{
	public:
		std::vector<TradeItem> clientItems;
		std::string partnerName;
		std::vector<TradeItem> partnerItems;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			const size_t clientItemsLen = pb->ReadInt16();
			clientItems.resize(clientItemsLen);
			for (size_t i = 0; i < clientItemsLen; i++)
			{
				TradeItem item;
				item.ReadData(pb);
				clientItems.push_back(item);
			}
			partnerName = pb->ReadString();
			const size_t partnerItemsLen = pb->ReadInt16();
			for (size_t i = 0; i < partnerItemsLen; i++)
			{
				TradeItem item;
				item.ReadData(pb);
				partnerItems.push_back(item);
			}
		}
	};

	class UpdatePacket : IncomingPacket
	{
	public:
		std::vector<GroundTileData> tiles;
		std::vector<ObjectData> newObjects;
		std::vector<int32_t> drops;

		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			const size_t tilesLen = pb->ReadInt16();
			tiles.resize(tilesLen);
			for (size_t i = 0; i < tilesLen; i++)
			{
				GroundTileData gd;
				gd.ReadData(pb);
				tiles.push_back(gd);
			}

			const size_t newObjectsLen = pb->ReadInt16();
			newObjects.resize(newObjectsLen);
			for (size_t i = 0; i < newObjectsLen; i++)
			{
				ObjectData od;
				od.ReadData(pb);
				newObjects.push_back(od);
			}

			const size_t dropsLen = pb->ReadInt16();
			drops.resize(dropsLen);
			for (size_t i = 0; i < dropsLen; i++)
			{
				drops.push_back(pb->ReadInt32());
			}
		}
	};

	class VerifyEmailPacket : IncomingPacket
	{
	public:
		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
		}
	};
	class DeletePetMessage : IncomingPacket
	{
	public:
		int32_t petId;
		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			petId = pb->ReadInt32();
		}
	};
	class EvolvedPetMessage : IncomingPacket
	{
	public:
		int32_t petId, initialSkin, finalSkin;
		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			petId = pb->ReadInt32();
			initialSkin = pb->ReadInt32();
			finalSkin = pb->ReadInt32();
		}
	};
	class HatchPetMessage : IncomingPacket
	{
	public:
		std::string petName;
		int32_t petSkin;
		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			petName = pb->ReadString();
			petSkin = pb->ReadInt32();
		}
	};
	class ArenaDeathPacket : IncomingPacket
	{
	public:
		int32_t cost;
		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			cost = pb->ReadInt32();
		}
	};
	class ImminentArenaWavePacket : IncomingPacket
	{
	public:
		int32_t currentRunTime;
		void ReadData(PacketBuffer* pb) override
		{
			if (!pb) return;
			currentRunTime = pb->ReadInt32();
		}
	};
}