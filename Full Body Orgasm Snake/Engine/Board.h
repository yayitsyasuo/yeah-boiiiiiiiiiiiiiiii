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
		Head,
		Obstacle,
		Mixture,
		Wall,
		Poison
	};
public:
	Board(Graphics& gfx);
	void DrawCells(Color c, Content content);
	void SpawnContent(const Location& loc,const Content content);
	void SpawnFeature(std::mt19937& rnd, const Content content );
	void EmptyContent(const Location& loc);
	Content ContentCheck(const Location & loc);
public:
	static int constexpr Columns = 39; // 760 / 20; //38
	static int constexpr Rows = 29; // 560 / 20; //28
	int dimension;
	static int constexpr nPoison = 200;
	 // static int constexpr SnakeDimension = 19; padding is inside Graphics !
	Content Board1D[Columns*Rows] = {Content::Nothing}; //2d array- big guy
	Graphics& gfx;
	std::mt19937 rnd;

};

