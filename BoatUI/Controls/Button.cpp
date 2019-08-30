#include "Controls.h"
#include "../Functional/Graphics/Graphics.h"
#include "../Functional/Mouse/Mouse.h"

#define MAX_BUTTON_COUNT 300

namespace C
{
	bool bPressed[300] = { false };

#pragma warning(push)
#pragma warning(disable : 4244)
	bool Button(int x, int y, int w, int h, const std::string_view& str)
	{
		assert(fontContext);
		buttonIndex++;
		assert(buttonIndex < MAX_BUTTON_COUNT);
		size_t mx, my;
		Mouse::GetPos(mx, my);
		bool clicked = (Mouse::IsDown(1) && !AreAnyDropped() && (int)mx > x && (int)mx < x + w && (int)my > y && (int)my < y + h);
		if (clicked)
		{
			G::FilledRect(x, y, w, h, BUTTON_BACKGROUND_COLOR_CLICKED);
			G::Rect(x, y, w, h, BUTTON_OUTLINE_COLOR_CLICKED);
			fontContext->PutText(str,
				x + (w / 2.0 - (((double)fontContext->glyphWidth * str.length()) / 2.0)),
				y + (h / 2.0 - fontContext->glyphHeight / 2.0), BUTTON_TEXT_COLOR_CLICKED);
			bPressed[buttonIndex] = true;
		}
		else
		{
			G::FilledRect(x, y, w, h, BUTTON_BACKGROUND_COLOR);
			G::Rect(x, y, w, h, BUTTON_OUTLINE_COLOR);
			fontContext->PutText(str,
				x + (w / 2.0 - (((double)fontContext->glyphWidth * str.length()) / 2.0)),
				y + (h / 2.0 - fontContext->glyphHeight / 2.0), BUTTON_TEXT_COLOR);
			if (bPressed[buttonIndex])
			{
				bPressed[buttonIndex] = false;
				return true;
			}
		}
		return false;
	}
#pragma warning(pop)
}