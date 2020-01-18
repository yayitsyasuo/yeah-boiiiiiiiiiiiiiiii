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
	int Columns;
	int Rows;
	int dimension;
	int nPoison;
	int nFruits;
	 //padding is inside Graphics !
	std::vector < Content > Board1D;
	Graphics& gfx;
	std::mt19937 rnd;

};

