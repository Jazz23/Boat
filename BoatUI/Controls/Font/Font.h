#pragma once

#include <string>

#include "../../Functional/Surface/Surface.h"
#include "../../Functional/Color.h"

class Font
{
private:
	Surface surface;
public:
	const int glyphWidth;
	const int glyphHeight;
	static constexpr int nColumns = 32;
	static constexpr int nRows = 3;
public:
	Color chroma;
	static constexpr char firstChar = ' ';
	static constexpr char lastChar = '~';
public:
	Font(const std::string_view& filename, const Color& chroma = Colors::White);
	void PutText(const std::string_view &str, int x, int y, const Color &color) const;
};













