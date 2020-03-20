#pragma once

#include <d3d11.h>
#include <wrl.h>
#include <cassert>
#include <mutex>
#include "../Color.h"

namespace G
{
	void Setup();
	void FrameEnd();
	void FrameBegin();
	inline std::mutex pixelMutex;
	void PutPixel(int x, int y, const Color& c);
	Color GetPixel(int x, int y);


	//basic shapes
	void  HorizontalLine(int x, int y, int w, const Color& c);
	void  VerticalLine(int x, int y, int h, const Color& c);

	void  FilledRect(int x, int y, int w, int h, const Color& c);
	void  Rect(int x, int y, int w, int h, const Color& c);
	void  Circle(int x, int y, int r, const Color& c);
}