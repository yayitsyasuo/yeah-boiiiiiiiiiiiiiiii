#include "Snake.h"


void Snake::SnakeHeadInit(const Location & in)
{
	seg[0].Init(in);
}

void Snake::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

void Snake::Update(Location & dl)
{
	loc+=dl;
}

void Snake::Segment::Init(Location & loc_in)
{
	loc.x = loc_in.x;
	loc.y = loc_in.y;
}
