#include "Controls.h"
#include "../Functional/Graphics/Graphics.h"
#include "../Functional/Mouse/Mouse.h"

namespace C
{

#pragma warning(push)
#pragma warning(disable : 4244)
	void CheckBox(int x, int y, const std::string_view& str, bool* setting)
	{
		assert(fontContext);
		static bool buttonpress = false;
		G::Rect(x, y, 25, 25, CHECKBOX_OUTLINE_COLOR);
		//G::Rect(x + 2, y + 2, 25 - 4, 25 - 4, CHECKBOX_OUTLINE_COLOR);
		G::FilledRect(x + 4, y + 4, 25 - 8, 25 - 8, *setting ? CHECKBOX_CHECKED_COLOR : CHECKBOX_NCHECKED_COLOR);
		fontContext->PutText(str, x + 25 + 8, y + (25 / 2.0) - (fontContext->glyphHeight / 2.0) + 2, CHECKBOX_TEXT_COLOR);
		if (Mouse::IsDown(1) && !buttonpress)
		{
			size_t cx = 0, cy = 0;
			Mouse::GetPos(cx, cy);
			if (!AreAnyDropped()) //check for dropboxes that are open and overlap
			{
				if ((int)cx <= x + 30 + 8 + (fontContext->glyphWidth * (int)str.length()) && (int)cx >= x && (int)cy <= y + 30 && (int)cy >= y)
				{
					*setting = !*setting;
				}
			}
			buttonpress = true;
		}
		else if (!Mouse::IsDown(1))
			buttonpress = false;

	}
#pragma warning(pop)
}