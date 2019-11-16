//#include <Windows.h>
//#include <vector>
//
//#include "Pixel.h"
//#include "../Settings.h"
//
//namespace Pixel
//{
//	COLORREF* pixels;
//	bool MustUpdate = false;
//	void SetupArray()
//	{
//		pixels = new COLORREF[WINDOW_WIDTH * WINDOW_HEIGHT];
//	}
//	void __fastcall PutPixel(size_t x, size_t y, COLORREF c)
//	{
//		if (!pixels) return;
//		pixels[y * WINDOW_WIDTH + x] = c;
//		MustUpdate = true;
//	}
//}