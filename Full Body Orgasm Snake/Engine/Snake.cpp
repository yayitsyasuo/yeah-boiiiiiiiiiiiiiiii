#include "Snake.h"
#include "Location.h"

Snake::Snake(const Location & in, Board& brd)
{
	// brd.SpawnContent(in); //gives it place in the grid based on that loc
	seg[0].Init(in); // gives it location
	seg[1].Init(in);
	// Location l=(in + Location(0, brd.dimension));
	// seg[1].Init(l);
}

void Snake::Draw(Board & brd)
{
	// for(Segment&s : seg)
	for(int i=0; i<=nSegments; i++)
	seg[i].Draw(brd, c);
}

void Snake::Update(Board& brd, const Location & dl) // the guy that calls everything since he's being called in Game.cpp
{

	const Location previousLoc = seg[0].GetLoc();
	//head
		seg[0].ControltheHead(brd, dl);
	if (!justonce) { // Graphics aren't yet initialized to Draw shit in initializer 
		//segments      so I had to do it the old way
		for (int i = 1; i <= nSegments; i++)
		{
			seg[i].ContentUpdate(brd, previousLoc); //GetLoc b4 the update
		}

	}
	justonce = false;
	
}

void Snake::Segment::ContentUpdate(Board& brd, const Location & newLoc)
{
	brd.EmptyContent(loc);
	brd.SpawnContent(newLoc, Board::Content::Snake);
	loc = newLoc;
}

void Snake::Segment::ControltheHead(Board & brd, const Location & dl)
{
	Location newLoc = loc + dl;
	ContentUpdate(brd, newLoc);
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
	brd.DrawCells(c, Board::Content::Snake);
}
