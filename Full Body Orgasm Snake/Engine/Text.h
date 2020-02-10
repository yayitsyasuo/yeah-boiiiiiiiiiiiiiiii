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
	Text( const std::string& file, Color chroma);
	void Draw(const std::string& text, Graphics& gfx, Vei2 pos );//can't redirect a reference == can't change it????
private:
	Surface text;
	std::vector <RectI> letter;
	Color chroma;
	static constexpr int nColumns = 32;
	static constexpr int nRows = 3;
	int FontWidth;
	int FontHeight;
};

