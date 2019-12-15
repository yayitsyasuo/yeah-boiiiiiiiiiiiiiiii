#include "Snake.h"
#include "Location.h"

Snake::Snake(const Location & in)
{
	seg[0].Init(in);
}

void Snake::Draw(Board & brd)
{
	seg[0].Draw(brd, c);
}

void Snake::Update(const Location & dl)
{
	seg[0].Update(dl);
}

void Snake::Segment::Update(const Location & dl)
{
	loc+=dl;
}


void Snake::Segment::Init(const Location & loc_in)
{
	loc = loc_in;
}

void Snake::Segment::Draw(Board & brd, Color c)
{
	brd.DrawCell(loc, c);
}
