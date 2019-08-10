#pragma once
#include <vector>

#include "Packets.h"
#include "PacketBuffer.h"
#include "../Structures/NetworkData/world_pos_data.h"
#include "../Structures/NetworkData/slot_object_data.h"
#include "../Structures/NetworkData/move_record.h"
namespace Packet
{
	class AcceptTradePacket : OutgoingPacket
	{
	public:
		std::vector<bool> clientOffer, partnerOffer;

		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt16(clientOffer.size());
			for (auto c : clientOffer)
				pb->WriteBoolean(c);
			pb->WriteInt16(partnerOffer.size());
			for (auto c : partnerOffer)
				pb->WriteBoolean(c);
		}
	};

	class AoeAckPacket : OutgoingPacket
	{
	public:
		int32_t time;
		WorldPosData pos;

		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(time);
			pos.WriteData(pb);
		}
	};
	class BuyPacket : OutgoingPacket
	{
	public:
		int32_t objectId, quantity;

		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(objectId);
			pb->WriteInt32(quantity);
		}
	};
	class CancelTradePacket : OutgoingPacket
	{
	public:
		int32_t objectId;
		void WriteData(PacketBuffer* pb) const override
		{

		}
	};
	class ChangeGuildRankPacket : OutgoingPacket
	{
	public:
		std::string name;
		int32_t guildRank;

		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteString(name);
			pb->WriteInt32(guildRank);
		}
	};
	class ChangeTradePacket : OutgoingPacket
	{
	public:
		std::vector<bool> offer;
		
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt16(offer.size());
			for (bool c : offer)
				pb->WriteBoolean(c);
		}
	};
	class CheckCreditsPacket : OutgoingPacket
	{
	public:
		void WriteData(PacketBuffer* pb) const override
		{

		}
	};
	class ChooseNamePacket : OutgoingPacket
	{
	public:
		std::string name;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteString(name);
		}
	};
	class ClaimDailyRewardMessage : OutgoingPacket
	{
	public:
		std::string claimKey, claimType;
		
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteString(claimKey);
			pb->WriteString(claimType);
		}
	};
	class CreateGuildPacket : OutgoingPacket
	{
	public:
		std::string name;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteString(name);
		}
	};
	class CreatePacket : OutgoingPacket
	{
	public:
		int16_t classType, skinType;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt16(classType);
			pb->WriteInt16(skinType);
		}
	};
	class EditAccountListPackket : OutgoingPacket
	{
	public:
		int32_t accountListId;
		bool add;
		int32_t ObjectId;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(accountListId);
			pb->WriteBoolean(add);
			pb->WriteInt32(ObjectId);
		}
	};
	class EnemyHitPacket : OutgoingPacket
	{
	public:
		int32_t time;
		int8_t bulletId;
		int32_t targetId;
		bool kill;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(time);
			pb->WriteInt8(bulletId);
			pb->WriteInt32(targetId);
			pb->WriteBoolean(kill);
		}
	};
	class EscapePacket : OutgoingPacket
	{
	public:
		void WriteData(PacketBuffer* pb) const override
		{

		}
	};
	class GotoRequestRoomPacket : OutgoingPacket
	{
	public:
		void WriteData(PacketBuffer* pb) const override
		{

		}
	};
	class GotoAckPacket : OutgoingPacket
	{
	public:
		int32_t time;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(time);
		}
	};
	class GroundDamagePacket : OutgoingPacket
	{
	public:
		int32_t time;
		WorldPosData pos;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(time);
			pos.WriteData(pb);
		}
	};
	class GuildInvitePacket : OutgoingPacket
	{
	public:
		std::string name;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteString(name);
		}
	};
	class GuildRemovePacket : OutgoingPacket
	{
	public:
		std::string name;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteString(name);
		}
	};
	class HelloPacket : OutgoingPacket
	{
	public:
		std::string buildVersion;
		int32_t gameId;
		std::string guid;
		std::string password;
		std::string secret;
		int32_t keyTime;
		std::vector<int8_t> key;
		std::u32string mapJSON;
		std::string entryTag, gameNet, gameNetUserId, playPlatform, platformToken, userToken;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteString(buildVersion);
			pb->WriteInt32(gameId);
			pb->WriteString(guid);
			pb->WriteInt32(floor(rand() * 1000000000));
			pb->WriteString(password);
			pb->WriteInt32(floor(rand() * 1000000000));
			pb->WriteString(secret);
			pb->WriteInt32(keyTime);
			pb->WriteByteArrayEx(key);
			pb->WriteStringUTF32(mapJSON);
			pb->WriteString(entryTag);
			pb->WriteString(gameNet);
			pb->WriteString(gameNetUserId);
			pb->WriteString(playPlatform);
			pb->WriteString(platformToken);
			pb->WriteString(userToken);
		}
	};
	class InvDropPacket : OutgoingPacket
	{
	public:
		SlotObjectData slotObject;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			slotObject.WriteData(pb);
		}
	};
	class InvSwapPacket : OutgoingPacket
	{
	public:
		int32_t time;
		WorldPosData pos;
		SlotObjectData slotObject1, slotObject2;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(time);
			pos.WriteData(pb);
			slotObject1.WriteData(pb);
			slotObject2.WriteData(pb);
		}
	};
	class JoinGuildPacket : OutgoingPacket
	{
	public:
		std::string guildName;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteString(guildName);
		}
	};
	class KeyInfoRequestPacket : OutgoingPacket
	{
	public:
		int32_t itemType;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(itemType);
		}
	};
	class LoadPacket : OutgoingPacket
	{
	public:
		int32_t charId;
		bool isFromArena;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(charId);
			pb->WriteBoolean(isFromArena);
		}
	};
	class MovePacket : OutgoingPacket
	{
	public:
		int32_t tickId, time;
		WorldPosData newPosition;
		std::vector<MoveRecord> records;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(tickId);
			pb->WriteInt32(time);
			newPosition.WriteData(pb);
			pb->WriteInt16(records.size());
			for (const auto& r : records)
				r.WriteData(pb);
		}
	};
	class OtherHitPacket : OutgoingPacket
	{
	public:
		int32_t time;
		int8_t bulletId;
		int32_t objectId, targetId;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(time);
			pb->WriteInt8(bulletId);
			pb->WriteInt32(objectId);
			pb->WriteInt32(targetId);
		}
	};
	class PlayerHitPacket : OutgoingPacket
	{
	public:
		uint8_t bulletId;
		int32_t objectId;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt8(bulletId);
			pb->WriteInt32(objectId);
		}
	};
	class PlayerShootPacket : OutgoingPacket
	{
	public:
		int32_t time;
		int8_t bulletId;
		int16_t containerType;
		WorldPosData startingPos;
		float angle;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(time);
			pb->WriteInt8(bulletId);
			pb->WriteInt16(containerType);
			startingPos.WriteData(pb);
			pb->WriteFloat(angle);
		}
	};
	class PlayerTextPacket : OutgoingPacket
	{
	public:
		std::string text;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteString(text);
		}
	};
	class PongPacket : OutgoingPacket //likely
	{
	public:
		int32_t serial, time;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(serial);
			pb->WriteInt32(time);
		}
	};
	class RequestTradePacket : OutgoingPacket
	{
	public:
		std::string name;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteString(name);
		}
	};
	class ReskinPacket : OutgoingPacket
	{
	public:
		int32_t skinId;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(skinId);
		}
	};
	class SetConditionPacket : OutgoingPacket
	{
	public:
		int8_t effect;
		float duration;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt8(effect);
			pb->WriteFloat(duration);
		}
	};
	class ShootAckPacket : OutgoingPacket
	{
	public:
		int32_t time;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(time);
		}
	};
	class SquareHitPacket : OutgoingPacket
	{
	public:
		int32_t time;
		int8_t bulletId;
		int32_t objectId;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(time);
			pb->WriteInt8(bulletId);
			pb->WriteInt32(objectId);
		}
	};
	class TeleportPacket : OutgoingPacket
	{
	public:
		int32_t objectId;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(objectId);
		}
	};
	class UpdateAckPacket : OutgoingPacket
	{
	public:
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
		}
	};
	class UseItemPacket : OutgoingPacket
	{
	public:
		int32_t time;
		SlotObjectData slotObject;
		WorldPosData itemUsePos;
		int8_t useType;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(time);
			slotObject.WriteData(pb);
			itemUsePos.WriteData(pb);
			pb->WriteInt8(useType);
		}
	};
	class UsePortalPacket : OutgoingPacket
	{
	public:
		int32_t objectId;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(objectId);
		}
	};
}