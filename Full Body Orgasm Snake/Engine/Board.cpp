#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCells(Color c, Content content)
{
	for (int y = 0; y < Rows; y++)
	{
		for (int x = 0; x < Columns; x++) // <= made an error nice
		{
			if (ContentCheck(x, y) == content)
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
	std::uniform_int_distribution<int> Xdist(1, Columns-1);
	std::uniform_int_distribution<int> Ydist(1, Rows-1);

	Location newLoc(Xdist(rnd), Ydist(rnd));
	Board1D[newLoc.y * Columns + newLoc.x] = content;
}

void Board::EmptyContent(const Location & loc)
{
	Board1D[loc.y * Columns + loc.x] = Content::Nothing;
}

Board::Content Board::ContentCheck(int x, int y)
{
	//assert(y >= 0);
	assert(x >= 0);
	return Board1D[y*Columns + x];
}



