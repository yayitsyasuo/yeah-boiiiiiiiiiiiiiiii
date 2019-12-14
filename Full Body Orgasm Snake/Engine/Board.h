#pragma once
#include "Location.h"
#include "Graphics.h"
class Board
{
public:
	enum class Content
	{
		Nothing,
		Snake
	};
public:
	Board(Graphics&gfx);
	void DrawCell(Location &loc);
public:
	static int constexpr Columns = 760 / 20;
	static int constexpr Rows = 560 / 20;
	static int constexpr dimension = 20;
	Content Board1D[Columns*Rows] = {Content::Nothing};
	Graphics &gfx;

};

