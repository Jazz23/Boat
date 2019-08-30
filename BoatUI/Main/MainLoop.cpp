#include <thread>
#include <iostream>
#include <Windows.h>
#include <wingdi.h>
#include <chrono>

#pragma comment(lib, "Gdi32.lib")

#include "MainLoop.h"
#include "../Functional/Keyboard/Keyboard.h"
#include "../Functional/Mouse/Mouse.h"
#include "../Functional/Settings.h"
#include "../Functional/Graphics/Graphics.h"
#include "../Functional/Color.h"
#include "../Controls/Controls.h"

namespace BoatMain
{
	constexpr int frameTime = 16;
	bool ContinueLoop = false;
	std::chrono::steady_clock::time_point start_t, end_t;

	void Loop()
	{
		while (ContinueLoop)
		{
			start_t = std::chrono::steady_clock::now();
			G::FrameBegin();
			C::StartControls();
			Render();
			G::FrameEnd();
			end_t = std::chrono::steady_clock::now();
			if (std::chrono::milliseconds dur = std::chrono::duration_cast<std::chrono::milliseconds>
				(end_t - start_t); dur < std::chrono::milliseconds(frameTime))
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(frameTime - dur.count()));
			}
		}
	}
	void StopLoop()
	{
		if (ContinueLoop)
		{
			ContinueLoop = false;
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}
	void StartLoop()
	{
		ContinueLoop = true;
		std::thread t(Loop);
		t.detach();
	}

	bool ContinueUpdate = false;

	void Update()
	{
		while (ContinueUpdate)
		{
			
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}
	void StopUpdate()
	{
		if (ContinueUpdate)
		{
			ContinueUpdate = false;
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}
	void StartUpdate()
	{
		ContinueUpdate = true;
		std::thread t(Update);
		t.detach();
	}
}