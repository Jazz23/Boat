#pragma once
#include "../Functional/Color.h"
#include "Font/Font.h"
#include <string_view>

namespace C
{
	inline Font* fontContext;
	void __fastcall SetFontContext(Font* f);

	constexpr Color BUTTON_OUTLINE_COLOR_CLICKED		= Color(255, 255, 255);
	constexpr Color BUTTON_TEXT_COLOR_CLICKED			= Color(255, 255, 255);
	constexpr Color BUTTON_BACKGROUND_COLOR_CLICKED		= Color(100, 100, 100);
	constexpr Color BUTTON_OUTLINE_COLOR				= Color(200, 200, 200);
	constexpr Color BUTTON_TEXT_COLOR					= Color(200, 200, 200);
	constexpr Color BUTTON_BACKGROUND_COLOR				= Color(50, 50, 50);
	

	
	bool Button(int x, int y, int w, int h, const std::string_view& str);
	void Label(int x, int y, const std::string_view& str);
	void Dropbox(int x, int y, size_t array_size, std::string* s, int &setting);
	int DropBoxEx(int x, int y, size_t array_size, std::string* s);
	void CheckBox(int x, int y, const std::string_view& str, bool& setting);
	void SliderFloat(int x, int y, int w, int h, float min, float max, const std::string_view& str, float& f);
	void SliderInt(int x, int y, int w, int h, int min, int max, const std::string_view& str, int& f);
}