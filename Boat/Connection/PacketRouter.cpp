#include "PacketManager.h"
#include "Packets.h"
#include "../Logger/Logger.h"
#include "../Structures/PacketId.h"
#include "IncomingPacket.h"
namespace Packet
{
	void PacketOut(OutgoingPacket& pkt)
	{
		PacketBuffer buf;
		buf.WriteInt8(pkt.pktId);
		pkt.WriteData(&buf);
		PacketDeep::SendPacket(buf, SEND_PACKET_NOW);
	}
	void HandlePacket(char* pkt, size_t sz)
	{
		PacketBuffer packet(pkt, sz);
		packet.index = 4;
		int8_t packetId = packet.ReadInt8();
		Logger::Log("recieved packet with id: " + std::to_string(packetId));
		if (PacketId::NEWTICK)
		{
		Packet::NewTickPacket pkt();
		}
		else if (PacketId::PING)
		{
			Packet::PingPacket pkt();
		}
		else if (PacketId::UPDATE)
		{
			Packet::UpdatePacket pkt();
		}
		else if (PacketId::ALLYSHOOT)
		{
			Packet::AllyShootPacket pkt();
		}
		else if (PacketId::AOE)
		{
			Packet::AoePacket pkt();
		}
		else if (PacketId::DAMAGE)
		{
			Packet::DamagePacket pkt();
		}
		else if (PacketId::ENEMYSHOOT)
		{
			Packet::EnemyShootPacket pkt();
		}
		else if (PacketId::TEXT)
		{
			Packet::TextPacket pkt();
		}
		else if (PacketId::GOTO)
		{
			Packet::GotoPacket pkt();
		}
		else if (PacketId::MAPINFO)
		{
			Packet::MapInfoPacket pkt();
		}
		else if (PacketId::RECONNECT)
		{
			Packet::ReconnectPacket pkt();
		}
		else if (PacketId::REALMHERO_LEFT_MSG)
		{
			Packet::RealmHeroLeftMessage pkt();
		}
		else if (PacketId::TRADEACCEPTED)
		{
			Packet::TradeAcceptedPacket pkt();
		}
		else if (PacketId::TRADECHANGED)
		{
			Packet::TradeChangedPacket pkt();
		}
		else if (PacketId::TRADEDONE)
		{
			Packet::TradeDonePacket pkt();
		}
		else if (PacketId::TRADEREQUESTED)
		{
			Packet::TradeRequestedPacket pkt();
		}
		else if (PacketId::TRADESTART)
		{
			Packet::TradeStartPacket pkt();
		}
		else if (PacketId::ARENADEATH)
		{
			Packet::ArenaDeathPacket p();
		}
		else if (PacketId::IMMINENTARENA_WAVE)
		{
			Packet::ImminentArenaWavePacket();
		}
		else if (PacketId::DELETEPET)
		{
			Packet::DeletePetMessage();
		}
		else if (PacketId::PETCHANGE_FORM_MSG)
		{
			Packet::EvolvedPetMessage();
		}
		else if (PacketId::HATCHPET)
		{
			Packet::HatchPetMessage();
		}
		else if (PacketId::ACCOUNTLIST)
		{
			Packet::AccountListPacket pkt();
		}
		else if (PacketId::BUYRESULT)
		{
			Packet::BuyResultPacket pkt();
		}
		else if (PacketId::CLIENTSTAT)
		{
			Packet::ClientStatPacket pkt();
		}
		else if (PacketId::CREATESUCCESS)
		{
			Packet::CreateSuccessPacket pkt();
		}
		else if (PacketId::DEATH)
		{
			Packet::DeathPacket pkt();
		}
		else if (PacketId::FAILURE)
		{
			Packet::FailurePacket pkt();
		}
		else if (PacketId::GLOBALNOTIFICATION)
		{
			Packet::GlobalNotificationPacket pkt();
		}
		else if (PacketId::GUILDRESULT)
		{
			Packet::GuildResultPacket pkt();
		}
		else if (PacketId::INVRESULT)
		{
			Packet::InviteResultPacket();
		}
		else if (PacketId::INVITEDTOGUILD)
		{
			Packet::InvitedToGuildPacket pkt();
		}
		else if (PacketId::KEYINFO_RESPONSE)
		{
			Packet::KeyInfoResponsePacket pkt();
		}
		else if (PacketId::NAMERESULT)
		{
			Packet::NameResultPacket pkt();
		}
		else if (PacketId::NEWABILITY)
		{
			Packet::NewAbilityMessage pkt();
		}
		else if (PacketId::NOTIFICATION)
		{
			Packet::NotificationPacket pkt();
		}
		else if (PacketId::PASSWORDPROMPT)
		{
			Packet::PasswordPromptPacket pkt();
		}
		else if (PacketId::QUESTOBJID)
		{
			Packet::QuestObjectIdPacket pkt();
		}
		else if (PacketId::QUESTREDEEM_RESPONSE)
		{
			Packet::QuestRedeemResponsePacket pkt();
		}
		else if (PacketId::RESKINUNLOCK)
		{
			Packet::ReskinUnlockPacket pkt();
		}
		else if (PacketId::SERVERPLAYERSHOOT)
		{
			Packet::ServerPlayerShootPacket();
		}
		else if (PacketId::SHOWEFFECT)
		{
			Packet::ShowEffectPacket pkt();
		}
		else if (PacketId::VERIFYEMAIL)
		{
			Packet::VerifyEmailPacket pkt();
		}
	}
}