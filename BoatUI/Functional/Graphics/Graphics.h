#pragma once

#include <d3d11.h>
#include <wrl.h>
#include <cassert>
#include "../Color.h"

namespace G
{
	void Setup();
	void FrameEnd();
	void FrameBegin();
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y);


	//basic shapes
	void __fastcall HorizontalLine(int x, int y, int w, const Color& c);
	void __fastcall VerticalLine(int x, int y, int h, const Color& c);

	void __fastcall FilledRect(int x, int y, int w, int h, const Color& c);
	void __fastcall Rect(int x, int y, int w, int h, const Color& c);
	void __fastcall Circle(int x, int y, int r, const Color& c);
}