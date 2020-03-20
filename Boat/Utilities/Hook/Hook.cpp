#include <string>
#include <stdint.h>
#include "Hook.h"
#include "../Logger/Log.h"


namespace Hook
{
	void __HOOKS::EmplaceHook(size_t pktId, void (*in_f)(uintptr_t))
	{
		if (pktId < setSize && pktId)
			set[pktId].AddFunction(in_f);
		else
			PrintAndLog("could not emplace hook at packet id: " + std::to_string(pktId));
	}
	void __HOOKS::Fire(size_t pktId, uintptr_t pkt)
	{
		if (pktId < setSize && pkt)
			set[pktId].Run(pkt);
		else
			PrintAndLog("bad packet hook id: " + std::to_string(pktId));
	}
	bool __HOOKS::IsHooked(size_t pktId)
	{
		if (pktId < setSize)
			return set[pktId].HasAnyFunctions();
	}
}