#include <string>
#include <stdint.h>
#include "Hook.h"
#include "../Logger/Logger.h"


namespace Hook
{
	class SingleHook
	{
	private:
		void (*f)(uintptr_t);
	public:
		SingleHook(void (*in_f)(uintptr_t) = nullptr) : f(in_f) { }
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
	};

	class MultiHook
	{
	private:
		std::vector<SingleHook> Hooks;
	public:
		MultiHook()
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
	};

	constexpr size_t setSize = 256;
	MultiHook set[setSize];

	void __fastcall EmplaceHook(size_t pktId, void (*in_f)(uintptr_t))
	{
		if (pktId < setSize && pktId)
			set[pktId].AddFunction(in_f);
		else
			PrintAndLog("could not emplace hook at packet id: " + std::to_string(pktId));
	}
	void __fastcall Fire(size_t pktId, uintptr_t pkt)
	{
		if (pktId < setSize && pkt)
			set[pktId].Run(pkt);
		else
			PrintAndLog("bad packet hook id: " + std::to_string(pktId));
	}
	bool __fastcall IsHooked(size_t pktId)
	{
		if (pktId < setSize)
			return set[pktId].HasAnyFunctions();
	}
}