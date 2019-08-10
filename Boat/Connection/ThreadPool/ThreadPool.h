#pragma once
#include <thread>
#include <mutex>
#include <chrono>

#include "../PacketBuffer.h"
#include "../PacketManager.h"

namespace PktThreadPool
{
	class oThread
	{
		bool busy;
		std::mutex	m;
		char* pkt;
		size_t sz;
	public:
		void SetPacket(char* _pkt, size_t _sz)
		{
			std::lock_guard<std::mutex> g(m);
			busy = true;
			sz = _sz;
			pkt = new char[sz];
			memcpy(pkt, _pkt, sz);
		}
		bool getBusy() const { return busy; }
		oThread() : busy(false)
		{

		}
		void operator()()
		{
			while (true)
			{
				if (busy && pkt && sz > 0)
				{
					std::lock_guard<std::mutex> g(m);
					Packet::HandlePacket(pkt, sz);
					delete[] pkt;
					pkt = nullptr;
					sz = 0;
					busy = false;
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(4));
			}
		}
	};

	class PacketThreadPool
	{
	private:
		const unsigned short numOfThreads;
		std::vector<oThread> ourThreads;

	public:
		PacketThreadPool() : numOfThreads(std::thread::hardware_concurrency() - 1)
		{
			if (numOfThreads)
			{
				std::cout << "COULD NOT DETECT CPU CORE COUNT BIG ERROR\n";
				system("pause");
			}
			for (int i = 0; i < numOfThreads; i++)
				ourThreads.emplace_back();
			while (ourThreads.size() > numOfThreads)
				ourThreads.pop_back();
			for (const auto& c : ourThreads)
			{
				std::thread t(c);
				t.detach();
			}
		}
		bool AddPacket(char* pkt, size_t sz)
		{
			bool should_stay = true;
			while (should_stay)
			{
				for (auto& c : ourThreads)
				{
					if (!c.getBusy())
					{
						c.SetPacket(pkt, sz);
						should_stay = false;
						break;
					}
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(4));
			}
		}
	};
}