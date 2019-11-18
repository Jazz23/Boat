#pragma once

#include "../Utilities/Logger/Logger.h"
#include "../Connection/TCP/PacketManager.h"
#include "../Utilities/Hook/Hook.h"
namespace Boat
{
	void Shutdown()
	{
		PacketDeep::StopClient();

		Logger::GenerateCrashFile();
	}
	//calls GenerateCrashFile before shutdown
	//to capture the last executed stuff before error
	void ShutdownWithError()
	{
		Logger::GenerateCrashFile();


		//.
		PacketDeep::StopClient();
	}

	void Start()
	{
		Logger::SetNumToSaveOnCrash(30); //save the last 30 operations before program close
		Logger::Log("starting winsock");
		PacketDeep::StartClient();
		Logger::Log("attempting connection");
		if (PacketDeep::Connect("3.88.196.105") != 0)
		{
			Logger::Log("faied to connect");
			PacketDeep::StopClient();
		}
		Logger::Log("starting listener");
		std::thread t(PacketDeep::Listen);
		t.detach();
	}
}