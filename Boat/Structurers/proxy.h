#pragma once
#include <string>
struct Proxy
{
	std::string host;
	int port;
	std::string  userId;
	std::string password;
	int type;
};