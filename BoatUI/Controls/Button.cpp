#include "Controls.h"
#include "../Functional/Graphics/Graphics.h"
#include "../Functional/Mouse/Mouse.h"

namespace C
{
	void __fastcall SetFontContext(Font* f) { fontContext = f; }


	bool Button(int x, int y, int w, int h, const std::string_view& str)
	{
		if (!fontContext) assert(0);

		size_t mx, my;
		Mouse::GetPos(mx, my);
		bool clicked = (Mouse::IsDown(1) && mx > x && mx < x + w && my > y && my < y + h); \
		if (clicked)
		{
			G::FilledRect(x, y, w, h, BUTTON_OUTLINE_COLOR_CLICKED);
			G::Rect(x, y, w, h, BUTTON_OUTLINE_COLOR_CLICKED);
			fontContext->PutText(str,
				x + (w / 2.0 - (((double)fontContext->glyphWidth * str.length()) / 2.0)),
				y + (h / 2.0 - fontContext->glyphHeight / 2.0), BUTTON_TEXT_COLOR_CLICKED);
		}
		else
		{
			G::FilledRect(x, y, w, h, BUTTON_OUTLINE_COLOR);
			G::Rect(x, y, w, h, BUTTON_OUTLINE_COLOR);
			fontContext->PutText(str,
				x + (w / 2.0 - (((double)fontContext->glyphWidth * str.length()) / 2.0)),
				y + (h / 2.0 - fontContext->glyphHeight / 2.0), BUTTON_TEXT_COLOR);
		}
		return clicked;
	}
}