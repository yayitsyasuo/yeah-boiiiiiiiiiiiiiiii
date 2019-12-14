#include "Snake.h"

Snake::Snake(const Location & in)
	:
	loc(in)
{
}

void Snake::Draw(Board & brd) const
{
	brd.DrawCell();
}

