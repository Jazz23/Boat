#pragma once
/*
usage:

void HookUpdate(uintptr_t pkt)
{
	Update *pkt = (Update*)pkt;
	//now you can edit the packet
}
EmplaceHook(UpdatePacketId, &HookUpdate);

now HookUpdate is called every time we recieve an updatePacket

NOTE: the order of which packet hooks are called is not to be relied on in any way. as it may change
*/
namespace Hook
{

	void __fastcall EmplaceHook(size_t pktId, void (*in_f)(uintptr_t));
	void __fastcall Fire(size_t pktId, uintptr_t pkt);
	bool __fastcall IsHooked(size_t pktId);
}