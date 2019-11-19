#include "Log.h"
#include <iostream>

namespace Log
{
	std::string msg;
	void __printmsg(std::string_view s)
	{
		std::cout << s;
	}
	void __savemsg(std::string_view s)
	{
		msg = s;
	}
	[[nodiscard]] std::string_view __getlastmsg()
	{
		return msg;
	}
}