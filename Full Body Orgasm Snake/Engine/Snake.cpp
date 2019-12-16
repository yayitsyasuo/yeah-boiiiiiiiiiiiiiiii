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
	if (!justonce) { // Graphics aren't yet initialized to Draw shit in initializer 
		for (int i = 1; i <= nSegments; i++)
		{
			const Location previousLoc = seg[i-1].GetLoc();
			seg[i].ContentUpdate(brd, previousLoc); //GetLoc b4 the update
		}

	}
	justonce = false;

	seg[0].ControltheHead(brd, dl); // this guy gets some exlusive shit
}

void Snake::Segment::ContentUpdate(Board& brd, const Location & previous_loc)
{
	brd.EmptyContent(loc); // this shit right here is dangerous
	brd.SpawnContent(previous_loc, Board::Content::Snake);
	loc = previous_loc;
}

void Snake::Segment::ControltheHead(Board & brd, const Location & dl) // exclusively for the head
{
	Location newLoc = loc + dl;
	HeadContentUpdate(brd, newLoc);

//	Board::Content content = brd.ContentCheck(newLoc.x, newLoc.y);
//	switch (content) {
//	case Board::Content::Fruit:
//	}
}

void Snake::Segment::HeadContentUpdate(Board & brd, const Location & previous_loc)
{
	brd.SpawnContent(previous_loc, Board::Content::Snake);
	loc = previous_loc;
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
