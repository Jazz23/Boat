#include "Logger.h"
#include <iostream>
#define DEBUG_MODE

namespace Logger
{
	size_t numToSaveOnCrash;
	std::queue<std::string_view> saved;
	void Log(std::string_view str)
	{
#ifdef DEBUG_MODE
		saved.push(str);
		while (saved.size() > numToSaveOnCrash)
			saved.pop();
		std::cout << str << "\n";
#endif
	}
	void GenerateCrashFile()
	{

	}
	void SetNumToSaveOnCrash(size_t s)
	{
		numToSaveOnCrash = s;
	}
	[[nodiscard]] std::string_view GetLastString()
	{
		return saved.back();
	}
}