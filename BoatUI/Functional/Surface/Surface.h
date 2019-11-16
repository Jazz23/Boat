#pragma once

#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <Windows.h>


#include "Surface.h"
#include "../Color.h"

class Surface
{
private:
	std::vector<Color> pixels;
	int width = 0;
	int height = 0;
public:
	Surface(const std::string_view& filename)
	{
		std::ifstream file(filename.data(), std::ios::binary);
		assert(file);

		BITMAPFILEHEADER bmFileHeader;
		file.read(reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader));

		BITMAPINFOHEADER bmInfoHeader;
		file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));

		assert(bmInfoHeader.biBitCount == 24 || bmInfoHeader.biBitCount == 32);
		assert(bmInfoHeader.biCompression == BI_RGB);

		const bool is32b = bmInfoHeader.biBitCount == 32;

		width = bmInfoHeader.biWidth;

		// test for reverse row order and control
		// y loop accordingly
		int yStart;
		int yEnd;
		int dy;
		if (bmInfoHeader.biHeight < 0)
		{
			height = -bmInfoHeader.biHeight;
			yStart = 0;
			yEnd = height;
			dy = 1;
		}
		else
		{
			height = bmInfoHeader.biHeight;
			yStart = height - 1;
			yEnd = -1;
			dy = -1;
		}

		pixels.resize(width * height);

		file.seekg(bmFileHeader.bfOffBits);
		// padding is for the case of of 24 bit depth only
		const int padding = (4 - (width * 3) % 4) % 4;

		for (int y = yStart; y != yEnd; y += dy)
		{
			for (int x = 0; x < width; x++)
			{
				PutPixel(x, y, Color(file.get(), file.get(), file.get()));
				if (is32b)
				{
					file.seekg(1, std::ios::cur);
				}
			}
			if (!is32b)
			{
				file.seekg(padding, std::ios::cur);
			}
		}
	}
	Surface(int width, int height)
		:
		width(width),
		height(height),
		pixels(width* height)
	{}
	Surface(const Surface&) = default;

	Surface& operator=(const Surface&) = default;
	Surface() = default;
	void PutPixel(int x, int y, const Color& c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;
	void Fill(Color c);
	const Color* Data() const;
};