#pragma once
#include <string_view>
#include <queue>

#define DEBUGLOGGER
#ifdef DEBUGLOGGER
#define DbgPrint(x) std::cout << x;
#define DbgPrintEx(format, ...) printf(format, __VA_ARGS__)

#define PrintAndLog(x) Logger::__printmsg(x); Logger::__savemsg(x)
#define PrintOnly(x) Logger::__printmsg(x);
#else
#define DbgPrint(x)
#define DbgPrintEx(format, ...)

#define PrintAndLog(x)
#define PrintOnly(x)
#endif

namespace Logger
{
	void __printmsg(std::string_view s);
	void __savemsg(std::string_view s);
	[[nodiscard]] std::string_view __getlastmsg();
}