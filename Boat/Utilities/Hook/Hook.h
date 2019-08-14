#pragma once
#include <stdint.h>
#include <cstring>


//legit unsafe to use lol 
/*
usage:

void HookUpdate(uintptr_t pkt)
{
	Update pkt = (Update *)pkt;
	//now you can edit the packet
}
EmplaceHook(UpdatePacketId, &HookUpdate);

now HookUpdate is called every time we recieve an updatePacket

*/
namespace Hook
{
	void __fastcall EmplaceHook(size_t pktId, void (*in_f)(uintptr_t));
	void __fastcall Fire(size_t pktId, uintptr_t pkt);
}