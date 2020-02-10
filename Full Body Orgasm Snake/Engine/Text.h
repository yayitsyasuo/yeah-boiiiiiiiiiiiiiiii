#pragma once
#include "Surface.h"
#include <vector>
#include "Rect.h"
#include <string>
#include "Graphics.h"
#include "Vec2.h"

class Text
{
public:
	Text( const std::string& file, int nC, int nR, Color chroma);
	void Draw(const std::string& text, Graphics& gfx, Vei2 pos );//can't redirect a reference == can't change it????
private:
	Surface text;
	std::vector <RectI> letter;
	Color chroma;
	int nColumns;
	int nRows;
	int FontWidth;
	int FontHeight;
};

