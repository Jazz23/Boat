#include <cassert>

#include "Font.h"
#include "../../Functional/Graphics/Graphics.h"
#include "../../Functional/Settings.h"


Font::Font(const std::string_view& filename, const Color& chroma)
	:
	surface(filename),
	glyphWidth(surface.GetWidth() / nColumns),
	glyphHeight(surface.GetHeight() / nRows),
	chroma(chroma)
{
	assert(glyphWidth * nColumns == surface.GetWidth());
	assert(glyphHeight * nRows == surface.GetHeight());
}

void Font::PutText(const std::string_view& str, int ox, int oy, const Color& color) const
{
	int curX = ox, curY = oy;
	for (auto c : str)
	{
		if (c == '\n')
		{
			curX = ox;
			curY += glyphHeight;
			continue;
		}
		else if (c >= firstChar + 1 && c <= lastChar)
		{
			const int glyphIndex = c - ' ';
			const int yGlyph = (glyphIndex / nColumns) * glyphHeight;
			const int xGlyph = (glyphIndex % nColumns) * glyphWidth;

			for (int y = 0; y < glyphHeight; y++)
				for (int x = 0; x < glyphWidth; x++)
				{
					if (curX + x > 0 && curX + x < WINDOW_WIDTH && curY + y > 0 && curY + y < WINDOW_HEIGHT)
					{
						if (Color col = surface.GetPixel(xGlyph + x, yGlyph + y); col == chroma)
							G::PutPixel(curX + x, curY + y, color);
					}
				}
		}
		curX += glyphWidth;
	}
}



















