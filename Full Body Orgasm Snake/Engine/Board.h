#pragma once
#include "Location.h"
#include "Graphics.h"
#include <random>
#include "GameSettings.h"
#include <vector>
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
	Board(Graphics& gfx, GameSettings& gt);
	void DrawCells(Color c, Content content);
	void SpawnContent(const Location& loc,const Content content);
	void SpawnFeature(std::mt19937& rnd, const Content content );
	void EmptyContent(const Location& loc);
	Content ContentCheck(const Location & loc);
public:
	int Columns; // 760 / 20; //38
	int Rows; // 560 / 20; //28
	int dimension;
	int nPoison;
	 // static int constexpr SnakeDimension = 19; padding is inside Graphics !
	std::vector < Content > Board1D;
	Graphics& gfx;
	std::mt19937 rnd;

};

