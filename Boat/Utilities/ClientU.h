#pragma once

#include "../Utilities/Logger/Log.h"
#include "../Connection/TCP/PacketManager.h"
#include "../Utilities/Hook/Hook.h"
namespace Boat
{
	void Shutdown()
	{
		PacketDeep::StopClient();

	}
	//calls GenerateCrashFile before shutdown
	//to capture the last executed stuff before error
	void ShutdownWithError()
	{


		//.
		PacketDeep::StopClient();
	}

	void Start()
	{
		PrintAndLog("starting winsock");
		std::cout << "should have printed\n";
		PacketDeep::StartClient();
		PrintAndLog("attempting connection");
		if (PacketDeep::Connect("3.88.196.105") != 0)
		{
			PrintAndLog("faied to connect");
			PacketDeep::StopClient();
		}
		PrintAndLog("starting listener");
		std::thread t(PacketDeep::Listen);
		t.detach();
	}
}