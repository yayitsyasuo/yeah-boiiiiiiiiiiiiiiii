#include "Snake.h"
#include "Location.h"

Snake::Snake(const Location & in, Board& brd)
{
	// brd.SpawnContent(in); //gives it place in the grid based on that loc
	seg[0].Init(in); // gives it location
	brd.SpawnContent(in); // Location l=(in + Location(0, brd.dimension));
	// seg[1].Init(l);
}

void Snake::Draw(Board & brd)
{
	seg[0].Draw(brd, c);
}

void Snake::Update(const Location & dl)
{
	seg[0].Update(dl);
}

void Snake::SpawnSegment(Board & brd)
{
	seg[0].SpawnSeg(brd);
}

void Snake::Segment::Update(const Location & dl)
{
	loc+=dl;
}

void Snake::Segment::SpawnSeg(Board & brd)
{
	brd.SpawnContent(loc);
}

void Snake::Segment::Init(const Location & loc_in)
{
	loc = loc_in;
}

void Snake::Segment::Draw(Board & brd, Color c)
{
	brd.DrawCells(c);
}
