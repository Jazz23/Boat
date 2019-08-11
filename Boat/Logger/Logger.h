#pragma once
#include <string_view>
#include <queue>

namespace Logger
{
	void GenerateCrashFile();
	void Log(std::string_view s);
	void SetNumToSaveOnCrash(size_t s);
	std::string_view GetLastString();
}