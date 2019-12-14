#pragma once
#include "Location.h"
#include "Board.h"
class Snake
{
public:
	Snake(const Location& in);
	void Draw(Board& brd) const;
public:
	Location loc;
	 // Board brd; NO! it'd be different object than the relevant one
};

