#include <string>

#include "Hook.h"
#include "../Logger/Logger.h"
namespace Hook
{
	class pHook
	{
	private:
		void (*f)(uintptr_t);
	public:
		pHook(void (*in_f)(uintptr_t) = nullptr) : f(in_f) { }
		void __fastcall SetFunction(void (*in_f)(uintptr_t) = nullptr)
		{
			f = in_f;
		}
		void inline __fastcall Run(uintptr_t pkt)
		{
			if (f != nullptr)
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

	pHook* set = new pHook[255];
	size_t setSize;

	void __fastcall EmplaceHook(size_t pktId, void (*in_f)(uintptr_t))
	{
		if (pktId < setSize && pktId)
			set[pktId].SetFunction = in_f;
		else
			Logger::Log("could not emplace hook at packet id: " + std::to_string(pktId));
	}
	void __fastcall Fire(size_t pktId, uintptr_t pkt)
	{
		if (pktId < setSize && pktId)
		{
			if (set[pktId].HasFunction())
				set[pktId].Run(pkt);
			else
				Logger::Log("hook: " + std::to_string(pktId) + " has no function");
		}
		else
			Logger::Log("bad packet hook id: " + std::to_string(pktId));
	}
}