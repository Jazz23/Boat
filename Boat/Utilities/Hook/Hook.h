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

namespace Hook
{
	typedef class __SINGLEHOOK
	{
	private:
		void (*f)(uintptr_t);
	public:
		__SINGLEHOOK(void (*in_f)(uintptr_t) = nullptr) : f(in_f) { }
		void __fastcall SetFunction(void (*in_f)(uintptr_t) = nullptr)
		{
			f = in_f;
		}
		void inline __fastcall Run(uintptr_t pkt)
		{
			if (HasFunction())
			{
				if (pkt != 0)
					f(pkt);
				else
					PrintAndLog("null packet pointer passed to hook");
			}
		}
		inline bool HasFunction()
		{
			return (f != nullptr);
		}
	}SingleHook, *pSingleHook;

	typedef class __MULTIHOOK
	{
	private:
		std::vector<SingleHook> Hooks;
	public:
		__MULTIHOOK()
		{
			Hooks.clear();
		}
		void AddFunction(void (*in_f)(uintptr_t))
		{
			Hooks.emplace_back(in_f);
		}
		void Run(uintptr_t pkt)
		{
			for (auto hk : Hooks)
				hk.Run(pkt);
		}
		bool HasAnyFunctions()
		{
			return Hooks.size() > 0;
		}
	}MultiHook, *pMultiHook;

	typedef class __HOOKS
	{
	private:
		const size_t setSize = 256;
		pMultiHook set;
	public:

		__HOOKS(size_t ss = 256) : setSize(ss)
		{
			set = new MultiHook[setSize];
		}
		~__HOOKS()
		{
			if (set) delete[] set;
		}
		void __fastcall EmplaceHook(size_t pktId, void (*in_f)(uintptr_t));
		void __fastcall Fire(size_t pktId, uintptr_t pkt);
		bool __fastcall IsHooked(size_t pktId);

	}Hooks, *pHooks;
}