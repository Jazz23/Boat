#pragma once
#include <vector>

#include "Packets.h"
#include "PacketBuffer.h"
#include "../../Structures/NetworkData/world_pos_data.h"
#include "../../Structures/NetworkData/slot_object_data.h"
#include "../../Structures/NetworkData/move_record.h"
#include "../../Structures/PacketId.h"
#include "../../Utilities/Hook/Hook.h"
namespace Packet
{
	using namespace PacketId;
	class AcceptTradePacket : OutgoingPacket
	{
	public:
		AcceptTradePacket() { pktId = ACCEPTTRADE; }
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
		AoeAckPacket() { pktId = AOEACK; }
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
		BuyPacket() { pktId = BUY; }
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
		CancelTradePacket() { pktId = CANCELTRADE; }
		int32_t objectId;
		void WriteData(PacketBuffer* pb) const override
		{

		}
	};
	class ChangeGuildRankPacket : OutgoingPacket
	{
	public:
		ChangeGuildRankPacket() { pktId = CHANGEGUILDRANK; }
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
		ChangeTradePacket() { pktId = CHANGETRADE; }
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
		CheckCreditsPacket() { pktId = CHECKCREDITS; }
		void WriteData(PacketBuffer* pb) const override
		{

		}
	};
	class ChooseNamePacket : OutgoingPacket
	{
	public:
		ChooseNamePacket() { pktId = CHOOSENAME; }
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
		ClaimDailyRewardMessage() { pktId = CLAIMDAILY_REWARD_MSG; }
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
		CreateGuildPacket() { pktId = CREATEGUILD; }
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
		CreatePacket() { pktId = CREATE; }
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
		EditAccountListPackket() { pktId = EDITACCOUNTLIST; }
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
		EnemyHitPacket() { pktId = ENEMYHIT; }
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
		EscapePacket() { pktId = ESCAPE; }
		void WriteData(PacketBuffer* pb) const override
		{


		}
	};
	class GotoRequestRoomPacket : OutgoingPacket
	{
	public:
		GotoRequestRoomPacket() { pktId = 0; }
		void WriteData(PacketBuffer* pb) const override
		{

		}
	};
	class GotoAckPacket : OutgoingPacket
	{
	public:
		GotoAckPacket() { pktId = GOTOACK; }
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
		GroundDamagePacket() { pktId = GROUNDDAMAGE; }
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
		GuildInvitePacket() { pktId = GUILDINVITE; }
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
		GuildRemovePacket() { pktId = GUILDREMOVE; }
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
		HelloPacket() { pktId = HELLO; }
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
		InvDropPacket() { pktId = INVDROP; }
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
		InvSwapPacket() { pktId = INVSWAP; }
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
		JoinGuildPacket() { pktId = JOINGUILD; }
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
		KeyInfoRequestPacket() { pktId = KEYINFO_REQUEST; }
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
		LoadPacket() { pktId = LOAD; }
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
		MovePacket() { pktId = MOVE; }
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
		OtherHitPacket() { pktId = OTHERHIT; }
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
		PlayerHitPacket() { pktId = PLAYERHIT; }
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
		PlayerShootPacket() { pktId = PLAYERSHOOT; }
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
		PlayerTextPacket() { pktId = PLAYERTEXT; }
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
		PongPacket() { pktId = PONG; }
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
		RequestTradePacket() { pktId = REQUESTTRADE; }
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
		ReskinPacket() { pktId = RESKIN; }
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
		SetConditionPacket() { pktId = SETCONDITION; }
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
		ShootAckPacket() { pktId = SHOOTACK; }
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
		SquareHitPacket() { pktId = SQUAREHIT; }
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
		TeleportPacket() { pktId = TELEPORT; }
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
		UpdateAckPacket() { pktId = UPDATEACK; }
		void WriteData(PacketBuffer* pb) const override
		{

		}
	};
	class UseItemPacket : OutgoingPacket
	{
	public:
		UseItemPacket() { pktId = USEITEM; }
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
		UsePortalPacket() { pktId = USEPORTAL; }

		int32_t objectId;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(objectId);
		}
	};

	//arena stuff
	class EnterArenaPacket : OutgoingPacket
	{
	public:
		EnterArenaPacket() { pktId = ENTERARENA; }

		int32_t currency;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt32(currency);
		}
	};
	class QuestRedeemPacket : OutgoingPacket
	{
	public:
		QuestRedeemPacket() { pktId = QUESTREDEEM; }

		std::string questId;
		std::vector<SlotObjectData> slots;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteString(questId);
			pb->WriteInt16(slots.size());
			for (const auto& slot : slots)
				slot.WriteData(pb);
		}
	};
	//pet stuff
	class ActivePetUpdateRequestPacket : OutgoingPacket
	{
	public:
		ActivePetUpdateRequestPacket() { pktId = ACTIVEPET_UPDATE_REQUEST; }

		int8_t commandType;
		int32_t instanceId;
		void WriteData(PacketBuffer* pb) const override
		{
			if (!pb) return;
			pb->WriteInt16(commandType);
			pb->WriteInt32(instanceId);
		}
	};
}