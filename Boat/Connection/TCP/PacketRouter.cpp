#include "PacketManager.h"
#include "../../Utilities/Logger/Logger.h"
#include "../../Structures/PacketId.h"
#include "../Packet/IncomingPacket.h"
#include "../Packet/Packets.h"
#include "../../Utilities/Hook/Hook.h"

namespace Packet
{
	void PacketOut(Packet::OutgoingPacket& pkt)
	{
		PacketBuffer buf;
		buf.WriteInt8(pkt.pktId);
		pkt.WriteData(&buf);
		buf.ShrinkToFit();
		//cipher here
		PacketDeep::SendPacket(buf, SEND_PACKET_NOW);
	}
	void HandlePacket(char* pkt, size_t sz)
	{
		PacketBuffer packet(pkt, sz);
		//cipher here
		packet.index = 4;
		int8_t packetId = packet.ReadInt8();
		Logger::Log("recieved packet with id: " + std::to_string(packetId));
		if (packetId == PacketId::NEWTICK)
		{
			Packet::NewTickPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::PING)
		{
			Packet::PingPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::UPDATE)
		{
			Packet::UpdatePacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::ALLYSHOOT)
		{
			Packet::AllyShootPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::AOE)
		{
			Packet::AoePacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::DAMAGE)
		{
			Packet::DamagePacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::ENEMYSHOOT)
		{
			Packet::EnemyShootPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::TEXT)
		{
			Packet::TextPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::GOTO)
		{
			Packet::GotoPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::MAPINFO)
		{
			Packet::MapInfoPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::RECONNECT)
		{
			Packet::ReconnectPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::REALMHERO_LEFT_MSG)
		{
			Packet::RealmHeroLeftMessage pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::TRADEACCEPTED)
		{
			Packet::TradeAcceptedPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::TRADECHANGED)
		{
			Packet::TradeChangedPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::TRADEDONE)
		{
			Packet::TradeDonePacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::TRADEREQUESTED)
		{
			Packet::TradeRequestedPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::TRADESTART)
		{
			Packet::TradeStartPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::ARENADEATH)
		{
			Packet::ArenaDeathPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::IMMINENTARENA_WAVE)
		{
			Packet::ImminentArenaWavePacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::DELETEPET)
		{
			Packet::DeletePetMessage pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::PETCHANGE_FORM_MSG)
		{
			Packet::EvolvedPetMessage pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::HATCHPET)
		{
			Packet::HatchPetMessage pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::ACCOUNTLIST)
		{
			Packet::AccountListPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::BUYRESULT)
		{
			Packet::BuyResultPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::CLIENTSTAT)
		{
			Packet::ClientStatPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::CREATESUCCESS)
		{
			Packet::CreateSuccessPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::DEATH)
		{
			Packet::DeathPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::FAILURE)
		{
			Packet::FailurePacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::GLOBALNOTIFICATION)
		{
			Packet::GlobalNotificationPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::GUILDRESULT)
		{
			Packet::GuildResultPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::INVRESULT)
		{
			Packet::InviteResultPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::INVITEDTOGUILD)
		{
			Packet::InvitedToGuildPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::KEYINFO_RESPONSE)
		{
			Packet::KeyInfoResponsePacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::NAMERESULT)
		{
			Packet::NameResultPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::NEWABILITY)
		{
			Packet::NewAbilityMessage pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::NOTIFICATION)
		{
			Packet::NotificationPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::PASSWORDPROMPT)
		{
			Packet::PasswordPromptPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::QUESTOBJID)
		{
			Packet::QuestObjectIdPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::QUESTREDEEM_RESPONSE)
		{
			Packet::QuestRedeemResponsePacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::RESKINUNLOCK)
		{
			Packet::ReskinUnlockPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::SERVERPLAYERSHOOT)
		{
			Packet::ServerPlayerShootPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::SHOWEFFECT)
		{
			Packet::ShowEffectPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (packetId == PacketId::VERIFYEMAIL)
		{
			Packet::VerifyEmailPacket pkt;
			pkt.ReadData(&packet);
			Hook::Fire(packetId, reinterpret_cast<uintptr_t>(&pkt));
		}
	}
}