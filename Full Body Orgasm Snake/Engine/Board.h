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
	Board(Graphics& gfx);
	void DrawCells(Color c);
	void SpawnContent(const Location& loc);
	void EmptyContent(const Location& loc);
	Content ContentCheck(int x, int y);
public:
	static int constexpr Columns = 40; // 760 / 20; //38
	static int constexpr Rows = 30; // 560 / 20; //28
	static int constexpr dimension = 20;
	Content Board1D[Columns*Rows] = {Content::Nothing};
	Graphics& gfx;

};

