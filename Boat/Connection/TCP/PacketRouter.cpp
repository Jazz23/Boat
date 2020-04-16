#include "PacketManager.h"
#include "../../Utilities/Logger/Log.h"
#include "../../Structures/PacketId.h"
#include "../../Utilities/Hook/Hook.h"
#include "../Packet/IncomingPacket.h"
#include "../Packet/Packets.h"
#include "../../Utilities/Crypto/rc4.h"

namespace Client
{
	void __CLIENT::PacketOut(Packet::OutgoingPacket& pkt)
	{
		Packet::PacketBuffer buf;
		buf.index = 4;
		buf.WriteInt8(pkt.pktId);
		pkt.WriteData(&buf);
		buf.ShrinkToFit();
		buf.index = 0;
		SendPacket(buf, SEND_PACKET_NOW);
	}

	void __CLIENT::PacketIn(Packet::PacketBuffer* packet)
	{
		RC4::EncDec(packet->buffer, packet->size, true);
		packet->index = 4;
		int8_t pktId = packet->ReadInt8();
		PrintAndLog("recieved packet with id: " + std::to_string(pktId));

		if (hookContext && !hookContext->IsHooked(pktId))
			return;

		Packet::IncomingPacket* pkt = nullptr;

		if (pktId == PacketId::NEWTICK)
			pkt = new Packet::NewTickPacket();
		else if (pktId == PacketId::PING)
			pkt = new Packet::PingPacket();
		else if (pktId == PacketId::UPDATE)
			pkt = new Packet::UpdatePacket();
		else if (pktId == PacketId::ALLYSHOOT)
			pkt = new Packet::AllyShootPacket();
		else if (pktId == PacketId::AOE)
			pkt = new Packet::AoePacket();
		else if (pktId == PacketId::DAMAGE)
			pkt = new Packet::DamagePacket();
		else if (pktId == PacketId::ENEMYSHOOT)
			pkt = new Packet::EnemyShootPacket();
		else if (pktId == PacketId::TEXT)
			pkt = new Packet::TextPacket();
		else if (pktId == PacketId::GOTO)
			pkt = new Packet::GotoPacket();
		else if (pktId == PacketId::MAPINFO)
			pkt = new Packet::MapInfoPacket();
		else if (pktId == PacketId::RECONNECT)
			pkt = new Packet::ReconnectPacket();
		else if (pktId == PacketId::REALMHERO_LEFT_MSG)
			pkt = new Packet::RealmHeroLeftMessage();
		else if (pktId == PacketId::TRADEACCEPTED)
			pkt = new Packet::TradeAcceptedPacket();
		else if (pktId == PacketId::TRADECHANGED)
			pkt = new Packet::TradeChangedPacket();
		else if (pktId == PacketId::TRADEDONE)
			pkt = new Packet::TradeDonePacket();
		else if (pktId == PacketId::TRADEREQUESTED)
			pkt = new Packet::TradeRequestedPacket();
		else if (pktId == PacketId::TRADESTART)
			pkt = new Packet::TradeStartPacket();
		else if (pktId == PacketId::ARENADEATH)
			pkt = new Packet::ArenaDeathPacket();
		else if (pktId == PacketId::IMMINENTARENA_WAVE)
			pkt = new Packet::ImminentArenaWavePacket();
		else if (pktId == PacketId::DELETEPET)
			pkt = new Packet::DeletePetMessage();
		else if (pktId == PacketId::PETCHANGE_FORM_MSG)
			pkt = new Packet::EvolvedPetMessage();
		else if (pktId == PacketId::HATCHPET)
			pkt = new Packet::HatchPetMessage();
		else if (pktId == PacketId::ACCOUNTLIST)
			pkt = new Packet::AccountListPacket();
		else if (pktId == PacketId::BUYRESULT)
			pkt = new Packet::BuyResultPacket();
		else if (pktId == PacketId::CLIENTSTAT)
			pkt = new Packet::ClientStatPacket();
		else if (pktId == PacketId::CREATESUCCESS)
			pkt = new Packet::CreateSuccessPacket();
		else if (pktId == PacketId::DEATH)
			pkt = new Packet::DeathPacket();
		else if (pktId == PacketId::FAILURE)
			pkt = new Packet::FailurePacket();
		else if (pktId == PacketId::GLOBALNOTIFICATION)
			pkt = new Packet::GlobalNotificationPacket();
		else if (pktId == PacketId::GUILDRESULT)
			pkt = new Packet::GuildResultPacket();
		else if (pktId == PacketId::INVRESULT)
			pkt = new Packet::InviteResultPacket();
		else if (pktId == PacketId::INVITEDTOGUILD)
			pkt = new Packet::InvitedToGuildPacket();
		else if (pktId == PacketId::KEYINFO_RESPONSE)
			pkt = new Packet::KeyInfoResponsePacket();
		else if (pktId == PacketId::NAMERESULT)
			pkt = new Packet::NameResultPacket();
		else if (pktId == PacketId::NEWABILITY)
			pkt = new Packet::NewAbilityMessage();
		else if (pktId == PacketId::NOTIFICATION)
			pkt = new Packet::NotificationPacket();
		else if (pktId == PacketId::PASSWORDPROMPT)
			pkt = new Packet::PasswordPromptPacket();
		else if (pktId == PacketId::QUESTOBJID)
			pkt = new Packet::QuestObjectIdPacket();
		else if (pktId == PacketId::QUESTREDEEM_RESPONSE)
			pkt = new Packet::QuestRedeemResponsePacket();
		else if (pktId == PacketId::RESKINUNLOCK)
			pkt = new Packet::ReskinUnlockPacket();
		else if (pktId == PacketId::SERVERPLAYERSHOOT)
			pkt = new Packet::ServerPlayerShootPacket();
		else if (pktId == PacketId::SHOWEFFECT)
			pkt = new Packet::ShowEffectPacket();
		else if (pktId == PacketId::VERIFYEMAIL)
			pkt = new Packet::VerifyEmailPacket();


		if (pkt)
		{
			pkt->ReadData(packet);
			hookContext->Fire(pktId, pkt);
			delete pkt;
		}
	}
}