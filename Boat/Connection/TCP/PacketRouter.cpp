#include "PacketManager.h"
#include "../../Utilities/Logger/Log.h"
#include "../../Structures/PacketId.h"
#include "../../Utilities/Hook/Hook.h"
#include "../Packet/IncomingPacket.h"
#include "../Packet/Packets.h"
#include "../../Utilities/Crypto/rc4.h"

namespace Packet
{
	void PacketOut(Packet::OutgoingPacket& pkt)
	{
		PacketBuffer buf;
		buf.index = 4;
		buf.WriteInt8(pkt.pktId);
		pkt.WriteData(&buf);
		buf.ShrinkToFit();
		buf.index = 0;
		PacketDeep::SendPacket(buf, SEND_PACKET_NOW);
	}

	void PacketIn(PacketBuffer* packet)
	{
		RC4::EncDec(packet->buffer, packet->size, true);
		packet->index = 4;
		int8_t pktId = packet->ReadInt8();
		PrintAndLog("recieved packet with id: " + std::to_string(pktId));

		if (!Hook::IsHooked(pktId))
			return;

		if (pktId == PacketId::NEWTICK)
		{
			Packet::NewTickPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::PING)
		{
			Packet::PingPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::UPDATE)
		{
			Packet::UpdatePacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::ALLYSHOOT)
		{
			Packet::AllyShootPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::AOE)
		{
			Packet::AoePacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::DAMAGE)
		{
			Packet::DamagePacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::ENEMYSHOOT)
		{
			Packet::EnemyShootPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::TEXT)
		{
			Packet::TextPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::GOTO)
		{
			Packet::GotoPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::MAPINFO)
		{
			Packet::MapInfoPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::RECONNECT)
		{
			Packet::ReconnectPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::REALMHERO_LEFT_MSG)
		{
			Packet::RealmHeroLeftMessage pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::TRADEACCEPTED)
		{
			Packet::TradeAcceptedPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::TRADECHANGED)
		{
			Packet::TradeChangedPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::TRADEDONE)
		{
			Packet::TradeDonePacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::TRADEREQUESTED)
		{
			Packet::TradeRequestedPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::TRADESTART)
		{
			Packet::TradeStartPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::ARENADEATH)
		{
			Packet::ArenaDeathPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::IMMINENTARENA_WAVE)
		{
			Packet::ImminentArenaWavePacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::DELETEPET)
		{
			Packet::DeletePetMessage pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::PETCHANGE_FORM_MSG)
		{
			Packet::EvolvedPetMessage pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::HATCHPET)
		{
			Packet::HatchPetMessage pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::ACCOUNTLIST)
		{
			Packet::AccountListPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::BUYRESULT)
		{
			Packet::BuyResultPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::CLIENTSTAT)
		{
			Packet::ClientStatPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::CREATESUCCESS)
		{
			Packet::CreateSuccessPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::DEATH)
		{
			Packet::DeathPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::FAILURE)
		{
			Packet::FailurePacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::GLOBALNOTIFICATION)
		{
			Packet::GlobalNotificationPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::GUILDRESULT)
		{
			Packet::GuildResultPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::INVRESULT)
		{
			Packet::InviteResultPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::INVITEDTOGUILD)
		{
			Packet::InvitedToGuildPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::KEYINFO_RESPONSE)
		{
			Packet::KeyInfoResponsePacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::NAMERESULT)
		{
			Packet::NameResultPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::NEWABILITY)
		{
			Packet::NewAbilityMessage pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::NOTIFICATION)
		{
			Packet::NotificationPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::PASSWORDPROMPT)
		{
			Packet::PasswordPromptPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::QUESTOBJID)
		{
			Packet::QuestObjectIdPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::QUESTREDEEM_RESPONSE)
		{
			Packet::QuestRedeemResponsePacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::RESKINUNLOCK)
		{
			Packet::ReskinUnlockPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::SERVERPLAYERSHOOT)
		{
			Packet::ServerPlayerShootPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::SHOWEFFECT)
		{
			Packet::ShowEffectPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
		else if (pktId == PacketId::VERIFYEMAIL)
		{
			Packet::VerifyEmailPacket pkt;
			pkt.ReadData(packet);
			Hook::Fire(pktId, reinterpret_cast<uintptr_t>(&pkt));
		}
	}
}