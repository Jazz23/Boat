
#include <Windows.h>
#include <wingdi.h>
#include <windowsx.h>
#include <stdio.h>
#include <iostream>

#include "Functional/Keyboard/Keyboard.h"
#include "Functional/Mouse/Mouse.h"
#include "Functional/Settings.h"
#include "Main/MainLoop.h"
#include "Functional/Pixels/Pixel.h"
#include "Functional/Graphics/Graphics.h"
#include "Controls/Font/Font.h"
#include "Controls/Controls.h"




LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow) 
{
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);
	printf("Debugging Window:\n");

	const wchar_t *wndClassName = L"BoatWindowClass";

	WNDCLASS wc { };
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = (LPCSTR)wndClassName;
	RegisterClass(&wc);

	unsigned long styling = (WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE | WS_MINIMIZE);

	HWND hWnd = CreateWindowEx(0, (LPCSTR)wndClassName, "The Boat", WS_OVERLAPPED,
		CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

	if (hWnd == NULL)
		return 0;

	ShowWindow(hWnd, nCmdShow);

	Font f("C:\\Users\\Lizerd\\AppData\\Roaming\\small.bmp", Colors::Black);
	
	C::SetFontContext(&f);

	Settings::hWnd = hWnd;
	Settings::hdc = GetDC(hWnd);

	G::Setup();

	BoatMain::StartUpdate();
	BoatMain::StartLoop();

	MSG msg { };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	BoatMain::StopLoop();
	BoatMain::StopUpdate();
	return 1;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_MOUSEMOVE:
		Mouse::SetPos(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		break;
	case WM_LBUTTONDOWN:
		Mouse::LeftDown();
		break;
	case WM_LBUTTONUP:
		Mouse::LeftUp();
		break;
	case WM_RBUTTONDOWN:
		Mouse::RightDown();
		break;
	case WM_RBUTTONUP:
		Mouse::RightUp();
		break;
	case WM_KEYDOWN:
	{	//must use { } when initializing varaibles inside of a case
		char c = static_cast<unsigned char>(wParam);
		Keyboard::ReportCharacter(c);
		Keyboard::KeyDown(c);
		break;
	}
	case WM_KEYUP:
		Keyboard::KeyUp(static_cast<unsigned char>(wParam));
		break;
	case WM_CLOSE:
		BoatMain::StopLoop();
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		BoatMain::StopLoop();
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}