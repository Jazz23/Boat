#pragma once

#include "../Utilities/Logger/Logger.h"
#include "../Connection/TCP/PacketManager.h"
namespace Boat
{
	void Shutdown()
	{
		PacketDeep::StopWinSock();

		Logger::GenerateCrashFile();
	}
	//calls GenerateCrashFile before shutdown
	//to capture the last executed stuff before error
	void ShutdownWithError()
	{
		Logger::GenerateCrashFile();


		//.
		PacketDeep::StopWinSock();
	}
	
	void Start()
	{
		Logger::SetNumToSaveOnCrash(30); //save the last 30 operations before program close
		Logger::Log("starting winsock");
		PacketDeep::StartWinSock();
		Logger::Log("starting listener");
		std::thread t(PacketDeep::Listen);
		t.detach();
	}
}