#pragma once

namespace Env
{
	void Init();
	void Start();
	void Tick();
	void Ping();
	int32_t GetLastTickDelta();
	int32_t GetMsSinceLastTick();
	int32_t GetLastPingDelta();
	int32_t GetMsSinceLastPing();
	int32_t GetMsSinceStart();
}