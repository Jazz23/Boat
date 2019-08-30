#include "Graphics.h"
#include <cmath>

namespace G
{
	void __fastcall HorizontalLine(int x, int y, int w, const Color& c)
	{
		std::lock_guard<std::mutex> g(pixelMutex);
		for (int i = x; i < x + w; i++)
			PutPixel(i, y, c);
	}
	void __fastcall VerticalLine(int x, int y, int h, const Color& c)
	{
		std::lock_guard<std::mutex> g(pixelMutex);
		for (int i = y; i < y + h; i++)
			PutPixel(x, i, c);
	}
	void __fastcall FilledRect(int x, int y, int w, int h, const Color& c)
	{
		std::lock_guard<std::mutex> g(pixelMutex);
		for (int i = y; i < y + h; i++)
			for (int j = x; j < x + w; j++)
				PutPixel(j, i, c);
	}
	void __fastcall Rect(int x, int y, int w, int h, const Color& c)
	{
		HorizontalLine(x, y, w, c);
		HorizontalLine(x, y + h, w, c);
		VerticalLine(x, y, h, c);
		VerticalLine(x + w, y, h, c);
	}
	void __fastcall Circle(int x, int y, int r, const Color& c)
	{
		//std::lock_guard<std::mutex> g(pixelMutex);
		//for (int i = y - r; i < y + r; i++)
		//	for (int j = x - r; j < x + r; j++)
		//	{
		//		if (float dist = (sqrt(pow((x - r + i) - x, 2) + pow((y - r + j) - y, 2))) < r)
		//			PutPixel(x - r + i, y - r + j, c);
		//	}
	}
}