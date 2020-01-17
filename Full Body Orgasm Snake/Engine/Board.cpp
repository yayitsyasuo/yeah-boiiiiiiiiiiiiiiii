#include "Board.h"
#include <assert.h>
#include <random>

Board::Board(Graphics& gfx, GameSettings& gt)
	:
	Columns(gt.GetBoardSizeX()),
	Rows(gt.GetBoardSizeY()),
	dimension(gt.GetTileSize()),
	Board1D(Rows*Columns, Content::Nothing),
	gfx(gfx),
	rnd(std::random_device()())

{
	for(int i = 0 ; i < nPoison ; i++)
	SpawnFeature(rnd, Content::Poison);
}

void Board::DrawCells(Color c, Content content)
{
	for (int y = 0; y < Rows; y++)
	{
		for (int x = 0; x < Columns; x++) // <= made an error nice
		{
			if (ContentCheck(Location(x,y)) == content)
			{
				gfx.DrawCell(x, y, c, dimension); // padding is inside Graphics
			}
		}
	}
	//gfx.DrawCell(loc, c, dimension);
}

void Board::SpawnContent(const Location& loc, const Content content)
{
	Board1D[loc.y * Columns + loc.x] =  content ;
}

void Board::SpawnFeature(std::mt19937& rnd, const Content content)
{
	std::uniform_int_distribution<int> Xdist(2, Columns-3);
	std::uniform_int_distribution<int> Ydist(2, Rows-3);
	Location newLoc(Xdist(rnd), Ydist(rnd));
	
	while (ContentCheck(newLoc) != Content::Nothing)
	{
		newLoc = Location (Xdist(rnd), Ydist(rnd));
	} 
	SpawnContent(newLoc, content);
}

void Board::EmptyContent(const Location & loc)
{
	Board1D[loc.y * Columns + loc.x] = Content::Nothing;
}

Board::Content Board::ContentCheck(const Location & loc)
{
	assert(loc.x >= 0);
	assert(loc.y >= 0);
	return Board1D[loc.y * Columns + loc.x];
}



