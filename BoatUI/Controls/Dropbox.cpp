#include "Controls.h"

#include "../Functional/Mouse/Mouse.h"
#include "../Functional/Graphics/Graphics.h"

#define MAX_DROPBOX_COUNT 300

namespace C
{
	bool leftDown = false;
	bool dropped[MAX_DROPBOX_COUNT] = { false };

#pragma warning(push)
#pragma warning(disable : 4244)
	
	bool AreAnyDropped()
	{
		for (int i = 0; i < MAX_DROPBOX_COUNT; i++)
			if (dropped[i])
				return true;
		return false;
	}
	void Dropbox(int x, int y, int w, int h, size_t array_size, std::string_view* s, int* setting)
	{
		assert(fontContext);
		dropBoxIndex++;
		if (dropped[dropBoxIndex])
		{
			if (GetAsyncKeyState(VK_ESCAPE))
				dropped[dropBoxIndex] = false;

			if (Mouse::IsDown(1)) leftDown = false;

			G::Rect(x, y, w, h * (array_size + 1) + 4 + array_size, DROPBOX_OUTLINE_COLOR);
			
			int j = 0;
			for (size_t i = 2; i < h * (array_size + 1); i += h + 1, j++)
			{
				G::FilledRect(x + 3, y + i, w - 6, h, DROPBOX_INLINE_COLOR);
				G::Rect(x + 2, y + i, w - 4, h, DROPBOX_OUTLINE_COLOR);
				if (j == 0)
					fontContext->PutText("___",  x + 8, y + i + (h / 2.0) - (fontContext->glyphWidth / 2.0), DROPBOX_TEXT_COLOR);
				else
					fontContext->PutText(s[j - 1], x + 8, y + i + (h / 2.0) - (fontContext->glyphHeight / 2.0), DROPBOX_TEXT_COLOR);
			}
			j = 0;
			if (Mouse::IsDown(1) && !leftDown)
			{
				size_t cx = 0, cy = 0;
				Mouse::GetPos(cx, cy);
				for (size_t i = 2; i < h * (array_size + 1); i += h, j++)
					if ((int)cx <= x + w && (int)cx >= x && (int)cy <= y + h && (int)cy >= y)
						* setting = *setting;
					else if ((int)cx <= x + w && (int)cx >= x && (int)cy <= y + i + h && (int)cy >= y + i)
					{
						dropped[dropBoxIndex] = false;
						*setting = j - 1;
					}
					else
						dropped[dropBoxIndex] = false;
			}
		}
		else
		{
			G::Rect(x, y, w, h, DROPBOX_OUTLINE_COLOR);
			G::Rect(x + 2, y + 2, w - 4, h - 4, DROPBOX_OUTLINE_COLOR);
			G::FilledRect(x + 3, y + 3, w - 6, h - 6, DROPBOX_INLINE_COLOR);
			if (*setting >= (int)array_size)
				return;
			fontContext->PutText(s[*setting], x + 8, y + (h / 2.0) - (fontContext->glyphHeight / 2.0), DROPBOX_TEXT_COLOR);

			if (Mouse::IsDown(1))
			{
				size_t cx = 0, cy = 0;
				Mouse::GetPos(cx, cy);
				if ((int)cx <= x + w && (int)cx >= x && (int)cy <= y + h && (int)cy >= y)
				{
					dropped[dropBoxIndex] = true; leftDown = true;
				}
			}
		}
	}
#pragma warning(pop)
}