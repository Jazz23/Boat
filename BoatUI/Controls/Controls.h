#pragma once
#include "../Functional/Color.h"
#include "Font/Font.h"
#include <string_view>

namespace C
{
	inline Font* fontContext;
	inline int buttonIndex = 0;
	inline int dropBoxIndex = 0;
	inline int textBoxIndex = 0;

	void SetFontContext(Font* f);
	void StartControls();

	constexpr Color BUTTON_OUTLINE_COLOR_CLICKED		= Color(255, 255, 255);
	constexpr Color BUTTON_TEXT_COLOR_CLICKED			= Color(255, 255, 255);
	constexpr Color BUTTON_BACKGROUND_COLOR_CLICKED		= Color(100, 100, 100);
	constexpr Color BUTTON_OUTLINE_COLOR				= Color(200, 200, 200);
	constexpr Color BUTTON_TEXT_COLOR					= Color(200, 200, 200);
	constexpr Color BUTTON_BACKGROUND_COLOR				= Color(50, 50, 50);
	
	constexpr Color LABEL_TEXT_COLOR					= Color(255, 255, 255);

	constexpr Color DROPBOX_OUTLINE_COLOR				= Color(255, 255, 255);
	constexpr Color DROPBOX_INLINE_COLOR				= Color(30, 30, 30);
	constexpr Color DROPBOX_TEXT_COLOR					= Color(255, 255, 255);

	constexpr Color TEXTBOX_TEXT_COLOR					= Color(255, 255, 255);
	constexpr Color TEXTBOX_OUTLINE_COLOR				= Color(255, 255, 255);
	constexpr Color TEXTBOX_INLINE_COLOR				= Color(30, 30, 30);
	
	constexpr Color CHECKBOX_OUTLINE_COLOR				= Color(255, 255, 255);
	constexpr Color CHECKBOX_CHECKED_COLOR				= Color(0, 255, 0);
	constexpr Color CHECKBOX_NCHECKED_COLOR				= Color(255, 0, 0);
	constexpr Color CHECKBOX_TEXT_COLOR					= Color(255, 255, 255);

	enum TPos { LEFT, RIGHT, NONE };

	bool AreAnyClicked();
	bool Button(int x, int y, int w, int h, const std::string_view& str);
	void Label(int x, int y, const std::string_view& str);
	void TextBox(std::string_view txt, int x, int y, int w, int h, std::string* str, int textpos = LEFT, bool centertext = false, std::string default_Char = "none");
	void Dropbox(int x, int y, int w, int h, size_t array_size, std::string_view* s, int* setting);
	bool AreAnyDropped();
	void CheckBox(int x, int y, const std::string_view& str, bool* setting);
	void SliderFloat(int x, int y, int w, int h, float min, float max, const std::string_view& str, float* f);
	void SliderInt(int x, int y, int w, int h, int min, int max, const std::string_view& str, int* f);
}