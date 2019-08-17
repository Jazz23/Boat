#pragma once
#include <thread>
#include <mutex>
#include <chrono>

#include "../TCP/PacketManager.h"
#include "../../Utilities/Logger/Logger.h"

namespace PktThreadPool
{
	class oThread
	{
	public:
		bool stop;
	private:
		bool busy;
		char* pkt;
		size_t sz;
		std::mutex	m;
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
		oThread() : busy(false), stop(false)
		{

		}
		void operator()()
		{
			while (true)
			{
				if (stop) break;
				if (busy && pkt && sz > 0)
				{
					std::lock_guard<std::mutex> g(m);
					Packet::HandlePacket(pkt, sz);
					delete[] pkt;
					pkt = nullptr;
					sz = 0;
					busy = false;
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(5));
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
			if (numOfThreads < 1)
			{
				std::cout << "COULD NOT DETECT CPU CORE COUNT BIG ERROR\n";
				system("pause");
			}
			ourThreads.clear();
			for (int i = 0; i < numOfThreads; i++)
				ourThreads.emplace_back();
			for (size_t s = 0; s < ourThreads.size(); s++)
			{
				Logger::Log("starting incomming packet thread" + std::to_string(s));
				std::thread t(ourThreads[s]);
				t.detach();
			}
		}
		~PacketThreadPool()
		{
			for (auto& c : ourThreads)
				c.stop = true;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
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
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
		}
	};
}