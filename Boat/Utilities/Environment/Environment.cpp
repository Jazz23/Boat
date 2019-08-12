#include "Environment.h"
#include <chrono>
namespace Env
{
	using clock = std::chrono::steady_clock;

	clock::duration lastTickDelta, lastPingDelta;
	clock::time_point start, lastTickTime, lastPingTime;
	void Init()
	{
		lastTickDelta = lastPingDelta = std::chrono::milliseconds(0);
		start = lastTickTime = lastPingTime = clock::now();
	}
	void Start()
	{
		start = clock::now();
	}
	void Tick()
	{
		auto now = clock::now();
		lastTickDelta = std::chrono::duration_cast<std::chrono::milliseconds>
					(now - lastTickTime);
		lastTickTime = now;
	}
	void Ping()
	{
		auto now = clock::now();
		lastPingDelta = std::chrono::duration_cast<std::chrono::milliseconds>
			(now - lastPingTime);
		lastPingTime = now;
	}
	int32_t GetMsSinceLastTick()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(clock::now() - lastTickTime).count();
	}
	int32_t GetMsSinceLastPing()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(clock::now() - lastPingTime).count();
	}
	int32_t GetLastPingDelta()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(lastPingDelta).count();
	}
	int32_t GetLastTickDelta()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(lastTickDelta).count();
	}
	int32_t GetMsSinceStart()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(clock::now() - start).count();
	}
}