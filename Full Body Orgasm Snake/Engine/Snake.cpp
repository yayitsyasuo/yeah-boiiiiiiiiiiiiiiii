#include "Snake.h"
#include "Location.h"

Snake::Snake(const Location & in, Board& brd)
{
	// brd.SpawnContent(in); //gives it place in the grid based on that loc
	seg[0].Init(in); // gives it location
	seg[1].Init(in+Location(-1,0));
	// Location l=(in + Location(0, brd.dimension));
	// seg[1].Init(l);
}

void Snake::Draw(Board & brd)
{
	// for(Segment&s : seg)
	for(int i=0; i<=nSegments; i++)
	seg[i].Draw(brd, c);
}

void Snake::Update(Board& brd, const Location & dl)
{
	seg[0].ControltheHead( brd, dl);
	for (int i = 1; i <= nSegments; i++)
		Follow(brd);
}

void Snake::SpawnSegment(Board & brd)
{
	for (int i = 0; i <= nSegments; i++)
	seg[i].SpawnSeg(brd);
}

void Snake::Follow(Board& brd)
{
	seg[1].Follow(brd, seg[0].GetLoc());
}

void Snake::Segment::Update(Board& brd, const Location & newLoc)
{
	brd.EmptyContent(loc);
	brd.SpawnContent(newLoc);
}

void Snake::Segment::SpawnSeg(Board & brd)
{
	brd.SpawnContent(loc);
}

void Snake::Segment::Follow(Board& brd, const Location & l)
{
	Location dl = l;
	Update(brd, loc);
}

void Snake::Segment::ControltheHead(Board & brd, const Location & dl)
{
	Location newLoc = loc + dl;
	Update(brd, newLoc);
}

const Location & Snake::Segment::GetLoc() const
{
	return loc;
}

void Snake::Segment::Init(const Location & loc_in)
{
	loc = loc_in;
}

void Snake::Segment::Draw(Board & brd, Color c)
{
	brd.DrawCells(c);
}
