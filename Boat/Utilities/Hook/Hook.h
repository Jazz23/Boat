#pragma once
#include "../Logger/Log.h"
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

#include "../../Connection/Packet/Packets.h"

namespace Hook
{
	typedef class __SINGLEHOOK
	{
	private:
		void (*f)(Packet::IncomingPacket*);
	public:
		__SINGLEHOOK(void (*in_f)(Packet::IncomingPacket*) = nullptr) : f(in_f) { }
		void SetFunction(void (*in_f)(Packet::IncomingPacket*) = nullptr)
		{
			f = in_f;
		}
		void inline Run(Packet::IncomingPacket* pkt)
		{
			if (HasFunction())
			{
				if (pkt != nullptr)
					f(pkt);
				else
					PrintAndLog("null packet pointer passed to hook");
			}
		}
		inline bool HasFunction()
		{
			return (f != nullptr);
		}
	}SINGLEHOOK, *PSINGLEHOOK;

	typedef class __MULTIHOOK
	{
	private:
		std::vector<SINGLEHOOK> Hooks;
	public:
		__MULTIHOOK()
		{
			Hooks.clear();
		}
		void AddFunction(void (*in_f)(Packet::IncomingPacket*))
		{
			Hooks.emplace_back(in_f);
		}
		void Run(Packet::IncomingPacket* pkt)
		{
			for (auto hk : Hooks)
				hk.Run(pkt);
		}
		bool HasAnyFunctions()
		{
			return (Hooks.size() > 0);
		}
	}MULTIHOOK, *PMULTIHOOK;

	typedef class __HOOKS
	{
	private:
		const size_t setSize;
		PMULTIHOOK set;
	public:

		__HOOKS(size_t ss = 256) : setSize(ss)
		{
			set = new MULTIHOOK[setSize];
		}
		~__HOOKS()
		{
			if (set) delete[] set;
		}
		void EmplaceHook(size_t pktId, void (*in_f)(Packet::IncomingPacket*));
		void Fire(size_t pktId, Packet::IncomingPacket* pkt);
		bool IsHooked(size_t pktId);

	}HOOKS, *PHOOKS;
}