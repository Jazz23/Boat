#include "PacketManager.h"
#include "Packets.h"
#include "../Logger/Logger.h"
#include "../Structures/PacketId.h"
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
		switch (packetId)
		{
			//use [[likely]] for stuff like update ping and pong
		case PacketId::ARENADEATH:
			packet = new ArenaDeathPacket();
			break;
		case PacketId::IMMINENTARENA_WAVE:
			packet = new ImminentArenaWavePacket();
			break;
		case PacketId::DELETEPET:
			packet = new DeletePetMessage();
			break;
		case PacketId::PETCHANGE_FORM_MSG:
			packet = new EvolvedPetMessage();
			break;
		case PacketId::HATCHPET:
			packet = new HatchPetMessage();
			break;
		case PacketId::ACCOUNTLIST:
			packet = new AccountListPacket();
			break;
		case PacketId::ALLYSHOOT:
			packet = new AllyShootPacket();
			break;
		case PacketId::AOE:
			packet = new AoePacket();
			break;
		case PacketId::BUYRESULT:
			packet = new BuyResultPacket();
			break;
		case PacketId::CLIENTSTAT:
			packet = new ClientStatPacket();
			break;
		case PacketId::CREATESUCCESS:
			packet = new CreateSuccessPacket();
			break;
		case PacketId::DAMAGE:
			packet = new DamagePacket();
			break;
		case PacketId::DEATH:
			packet = new DeathPacket();
			break;
		case PacketId::ENEMYSHOOT:
			packet = new EnemyShootPacket();
			break;
		case PacketId::FAILURE:
			packet = new FailurePacket();
			break;
		case PacketId::GLOBALNOTIFICATION:
			packet = new GlobalNotificationPacket();
			break;
		case PacketId::GOTO:
			packet = new GotoPacket();
			break;
		case PacketId::GUILDRESULT:
			packet = new GuildResultPacket();
			break;
		case PacketId::INVRESULT:
			packet = new InvResultPacket();
			break;
		case PacketId::INVITEDTOGUILD:
			packet = new InvitedToGuildPacket();
			break;
		case PacketId::KEYINFO_RESPONSE:
			packet = new KeyInfoResponsePacket();
			break;
		case PacketId::MAPINFO:
			packet = new MapInfoPacket();
			break;
		case PacketId::NAMERESULT:
			packet = new NameResultPacket();
			break;
		case PacketId::NEWABILITY:
			packet = new NewAbilityMessage();
			break;
		case PacketId::NEWTICK:
			packet = new NewTickPacket();
			break;
		case PacketId::NOTIFICATION:
			packet = new NotificationPacket();
			break;
		case PacketId::PASSWORDPROMPT:
			packet = new PasswordPromptPacket();
			break;
		case PacketId::PING:
			packet = new PingPacket();
			break;
		case PacketId::QUESTOBJID:
			packet = new QuestObjectIdPacket();
			break;
		case PacketId::QUESTREDEEM_RESPONSE:
			packet = new QuestRedeemResponsePacket();
			break;
		case PacketId::RECONNECT:
			packet = new ReconnectPacket();
			break;
		case PacketId::RESKINUNLOCK:
			packet = new ReskinUnlockPacket();
			break;
		case PacketId::SERVERPLAYERSHOOT:
			packet = new ServerPlayerShootPacket();
			break;
		case PacketId::SHOWEFFECT:
			packet = new ShowEffectPacket();
			break;
		case PacketId::TEXT:
			packet = new TextPacket();
			break;
		case PacketId::TRADEACCEPTED:
			packet = new TradeAcceptedPacket();
			break;
		case PacketId::TRADECHANGED:
			packet = new TradeChangedPacket();
			break;
		case PacketId::TRADEDONE:
			packet = new TradeDonePacket();
			break;
		case PacketId::TRADEREQUESTED:
			packet = new TradeRequestedPacket();
			break;
		case PacketId::TRADESTART:
			packet = new TradeStartPacket();
			break;
		case PacketId::UPDATE:
			packet = new UpdatePacket();
			break;
		case PacketId::VERIFYEMAIL:
			packet = new VerifyEmailPacket();
			break;
		case PacketId::REALMHERO_LEFT_MSG:
			packet = new RealmHeroLeftMessage();
			break;
		}
	}
}