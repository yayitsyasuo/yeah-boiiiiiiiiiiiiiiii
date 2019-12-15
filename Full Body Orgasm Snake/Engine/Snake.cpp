#include "Snake.h"


Snake::Snake(const Location & in)
	:
	loc(in)
{
}

void Snake::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

void Snake::Update(Location & dl)
{
	loc += dl;
}

