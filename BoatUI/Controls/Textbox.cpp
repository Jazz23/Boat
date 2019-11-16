#include "Controls.h"
#include "../Functional/Graphics/Graphics.h"
#include "../Functional/Mouse/Mouse.h"
#include "../Functional/Keyboard/Keyboard.h"

#define MAX_TEXTBOX_COUNT 300

namespace C
{
	bool clickedOn[MAX_TEXTBOX_COUNT] = { false };
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 26451)
	bool AreAnyClicked()
	{
		for (int i = 0; i < MAX_TEXTBOX_COUNT; i++)
			if (clickedOn[i])
				return true;
		return false;
	}
	void TextBox(std::string_view txt, int x, int y, int w, int h, std::string* str, int textpos, bool centertext, std::string default_Char)
	{
		assert(fontContext);
		static std::string rtext[100];
		int txtW = 0;
		if (textpos == 0)
		{
			fontContext->PutText(txt, x, y + (h / 2.0) - (fontContext->glyphHeight / 2.0), TEXTBOX_TEXT_COLOR);
			txtW = txt.length() * fontContext->glyphWidth + 5;
		}
		else if (textpos == 1)
		{
			fontContext->PutText(txt, x + w + 5, y + (h / 2.0) - (fontContext->glyphHeight / 2.0), TEXTBOX_TEXT_COLOR);
			txtW = 0;
		}
		else
			txtW = 0;
		G::Rect(x + txtW, y, w, h, TEXTBOX_OUTLINE_COLOR);
		G::FilledRect(x + 1 + txtW, y + 1, w - 2, h - 2, TEXTBOX_INLINE_COLOR);

		if (Mouse::IsDown(1))
		{
			size_t cx = 0, cy = 0;
			Mouse::GetPos(cx, cy);
			if ((int)cx <= x + txtW + w && (int)cx >= x + txtW && (int)cy <= y + h && (int)cy >= y)
				clickedOn[textBoxIndex] = true;
			else
				clickedOn[textBoxIndex] = false;
		}

		if (clickedOn[textBoxIndex])
		{
			char c = Keyboard::ReadChar();
			if (c != 0)
			{
				if (c == 8)
				{
					if (str->length() > 0)
						str->pop_back();
				}
				else
					*str += c;
			}

			std::string drawstring = *str + "_";
			if (default_Char != "none")
			{
				int len = drawstring.length();
				std::string tnew;
				for (int i = 0; i < len - 1; i++)
					tnew.push_back(default_Char[0]);
				drawstring = tnew;
				drawstring += "_";
			}
			while ((int)drawstring.length() * fontContext->glyphWidth > w - fontContext->glyphWidth)
				drawstring.pop_back();
			if (centertext)
				fontContext->PutText(drawstring, x + (w / 2.0) - ((fontContext->glyphWidth * (int)drawstring.length()) / 2.0) + txtW, y + (h / 2.0) - (fontContext->glyphHeight / 2.0), TEXTBOX_TEXT_COLOR);
			else
				fontContext->PutText(drawstring, x + 8 + txtW, y + (h / 2.0) - (fontContext->glyphHeight / 2.0), TEXTBOX_TEXT_COLOR);
		}
		else
		{
			std::string drawstring = *str;
			if (drawstring == "" && textpos == TPos::NONE)
			{
				drawstring = txt;
				if (centertext)
					fontContext->PutText(drawstring, x + (w / 2.0) - ((fontContext->glyphWidth * (int)drawstring.length()) / 2.0) + txtW, y + (h / 2.0) - (fontContext->glyphHeight / 2.0), TEXTBOX_TEXT_COLOR);
				else
					fontContext->PutText(drawstring, x + 8 + txtW, y + (h / 2.0) - (fontContext->glyphHeight / 2.0), TEXTBOX_TEXT_COLOR);
			}
			else
			{
				if (default_Char != "none")
				{
					int len = drawstring.length();
					std::string tnew;
					for (int i = 0; i < len; i++)
						tnew.push_back(default_Char[0]);
					drawstring = tnew;
				}
				while (int(drawstring.length() * fontContext->glyphWidth) > w - fontContext->glyphWidth)
					drawstring.pop_back();
				if (centertext)
					fontContext->PutText(drawstring, x + (w / 2.0) - ((fontContext->glyphWidth * (int)drawstring.length()) / 2.0) + txtW, y + (h / 2.0) - (fontContext->glyphHeight / 2.0), TEXTBOX_TEXT_COLOR);
				else
					fontContext->PutText(drawstring, x + 8 + txtW, y + (h / 2.0) - (fontContext->glyphHeight / 2.0), TEXTBOX_TEXT_COLOR);
			}
		}

		textBoxIndex++;
	}
#pragma warning(pop)
}