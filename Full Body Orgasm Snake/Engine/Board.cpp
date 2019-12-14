#include "Board.h"

Board::Board(Graphics & gfxx)
	:
	gfx(gfxx)
{
}

void Board::DrawCell(Location loc, Color c)
{
	gfx.DrawCell(loc, c, dimension);
}


