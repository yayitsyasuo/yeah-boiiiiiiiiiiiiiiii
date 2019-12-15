#include "Board.h"

Board::Board(Graphics & gfxx)
	:
	gfx(gfxx)
{
}

void Board::DrawCells(Color c)
{
	for (int y = 0; y <= Rows; y++)
	{
		for (int x = 0; x <= Columns; x++)
		{
			if (ContentCheck(x, y) == Content::Snake)
				gfx.DrawCell(x ,y, c, dimension); // skips it
		}
	}
	//gfx.DrawCell(loc, c, dimension);
}

void Board::SpawnContent(const Location& loc)
{
	Board1D[loc.y * Columns + loc.x] = { Content::Snake };
}

Board::Content Board::ContentCheck(int x, int y)
{
	return Board1D[y*Columns + x];
}



