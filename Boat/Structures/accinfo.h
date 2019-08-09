#pragma once
#include <string>
#include "proxy.h"
#include <vector>
using std::string;


struct LocalServerSettings
{
	bool enabled;
	int port;
};

struct CharacterInfo
{
	int charId;
	int nextCharId;
	int maxNumChars;
};

struct Account
{
	string alias;
	string guid;
	string password;
	string serverPref;
	CharacterInfo charInfo;
	Proxy proxy;
	bool pathfinder;
};

struct AccountInfo
{
	string buildVersion;
	LocalServerSettings localServer;
	std::vector<Account> accounts;
};