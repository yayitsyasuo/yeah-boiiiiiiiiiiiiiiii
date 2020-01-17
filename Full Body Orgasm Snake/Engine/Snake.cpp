#include "Snake.h"
#include "Location.h"
#include <assert.h>

Snake::Snake(const Location & in, Board& brd)
	:
	rnd(std::random_device()()),
	brd(brd)
{
	seg[0].Init(in); // gives it location
	seg[1].Init(in);
	// Location l=(in + Location(0, brd.dimension));
	// seg[1].Init(l);
}

void Snake::Draw()
{

	// for(Segment&s : seg)

	// OPTIMALIZE THIS PLS
	seg[0].Draw(brd, c[nColour], Board::Content::Snake);
	seg[0].Draw(brd, HeadC, Board::Content::Head); // head has got some exclusive shit yeah
	seg[0].Draw(brd, ObstacleC ,Board::Content::Obstacle);
	seg[0].Draw(brd, Colors::Green, Board::Content::Mixture);
}

void Snake::Update(const Location & dl) // the guy that calls everything since he's being called in Game.cpp
{
	
	if (!justonce) { // Graphics aren't yet initialized to Draw shit in initializer

		for (int i = nSegments; i > 0; --i)
		{
			if (i == nSegments) 
			{
				const Location previousLoc = seg[i - 1].GetLoc();
				seg[i].LastContentUpdate(brd, previousLoc);
			}
			else {
				const Location previousLoc = seg[i - 1].GetLoc();
				seg[i].ContentUpdate(brd, previousLoc, Board::Content::Snake);
			}
		}

	}
	justonce = false;

	// big guy obsticle update here
	
	if (GoalsEaten % 7 == 0 )
	{
		brd.SpawnFeature(rnd, Board::Content::Mixture);
		GoalsEaten = 1;
	}

	switch(seg[0].ControltheHead(brd, dl)) // this guy gets some exlusive shit
	{
	case Board::Content::Poison:
		SpeedMeUp = true;
		break;
	case Board::Content::Fruit:
		GoalsEaten++;
		nSegments++;
		if (nColour == nColourMax) // controling the color array
			nColour = 0;
		else
		nColour++;
		seg[nSegments].Init(seg[nSegments - 1].GetLoc());
		SpeedMeUp = true; // cringe method
	// New Food init here
		brd.SpawnFeature(rnd, Board::Content::Fruit);
		brd.SpawnFeature(rnd, Board::Content::Obstacle); // obstacles spawned here
		break;
	//what happens when you run on an obstacle / Snake
		case Board::Content::Obstacle:
		case Board::Content::Snake:// this guy gets some exlusive shit
		case Board::Content::Wall:
		GameOver = true;
		break;
	// when you run on a mixture
		case Board::Content::Mixture:
		Drugged = true;
		break;
	}
}

bool Snake::GetGameOver()
{
	return GameOver;
}

void Snake::Segment::LastContentUpdate(Board& brd, const Location & previous_loc)
{
	brd.EmptyContent(loc); // this shit right here is dangerous
	brd.SpawnContent(previous_loc, Board::Content::Snake);
	loc = previous_loc;
}

Board::Content Snake::Segment::ControltheHead(Board & brd, const Location & dl) // exclusively for the head
{
	Location newLoc = loc + dl;

	switch (brd.ContentCheck(newLoc)) {
	case Board::Content::Poison:
		ContentUpdate(brd, newLoc, Board::Content::Head);
		return Board::Content::Poison;
		break;
	case Board::Content::Fruit:
		ContentUpdate(brd, newLoc, Board::Content::Head);
		return Board::Content::Fruit;
		break; //fukin break man
	case Board::Content::Obstacle:
		ContentUpdate(brd, newLoc, Board::Content::Head);
		return Board::Content::Obstacle;
		break;
	case Board::Content::Snake:
		ContentUpdate(brd, newLoc, Board::Content::Head);
		return Board::Content::Snake;
		break;
	case Board::Content::Mixture:
		ContentUpdate(brd, newLoc, Board::Content::Head);
		return Board::Content::Mixture;
		break;
	case Board::Content::Wall:
		ContentUpdate(brd, newLoc, Board::Content::Head);
		return Board::Content::Wall;
		break;
	default:
		ContentUpdate(brd, newLoc, Board::Content::Head);
		return Board::Content::Nothing;
		break;
	
	}
}

void Snake::Segment::ContentUpdate(Board & brd, const Location & previous_loc,const Board::Content content)
{
	brd.SpawnContent(previous_loc, content);
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

void Snake::Segment::Draw(Board & brd, Color c, Board::Content content)
{
	brd.DrawCells(c, content);
}
