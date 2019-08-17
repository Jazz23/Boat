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
					Logger::Log("null packet pointer passed to hook");
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

	};

	MultiHook* set = new MultiHook[256];
	size_t setSize = 256;

	void __fastcall EmplaceHook(size_t pktId, void (*in_f)(uintptr_t))
	{
		if (pktId < setSize && pktId)
			set[pktId].AddFunction(in_f);
		else
			Logger::Log("could not emplace hook at packet id: " + std::to_string(pktId));
	}
	void __fastcall Fire(size_t pktId, uintptr_t pkt)
	{
		if (pktId < setSize && pkt)
			set[pktId].Run(pkt);
		else
			Logger::Log("bad packet hook id: " + std::to_string(pktId));
	}
}