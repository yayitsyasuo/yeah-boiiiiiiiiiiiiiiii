#pragma once
#include "Location.h"
#include "Graphics.h"
#include <random>
class Board
{
public:
	enum class Content
	{
		Nothing,
		Snake,
		Fruit,
		Head
	};
public:
	Board(Graphics& gfx);
	void DrawCells(Color c, Content content);
	void SpawnContent(const Location& loc,const Content content);
	void SpawnFeature(std::mt19937& rnd, const Content content );
	void EmptyContent(const Location& loc);
	Content ContentCheck(int x, int y);
public:
	static int constexpr Columns = 39; // 760 / 20; //38
	static int constexpr Rows = 29; // 560 / 20; //28
	static int constexpr dimension = 20;
	 // static int constexpr SnakeDimension = 19; padding is inside Graphics !
	Content Board1D[Columns*Rows] = {Content::Nothing};
	Graphics& gfx;

};

