#pragma once
#include "Colors.h"
#include <string>
#include <fstream>
#include "ChiliWin.h"
#include "Rect.h"

class Surface
{
public:
	Surface(const std::string& file);
	Surface(const Surface & sur);
	Surface(int width, int height);
	~Surface();
	Surface &operator= (const Surface& sur);
	void PutPixel(const int x, const int y, const Color c); // that's the boi controling colors
	Color GetPixelC(const int x, const int y) const;
	Color GetPixelC_swapped(const int x, const int y, Color chroma, Color swap_to) const;
	RectI GetRect() const; 
	int GetWidth() const;
	int GetHeight() const;
private:
	Color *pPixColor = nullptr;
	int width;
	int height;
};

