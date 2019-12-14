#pragma once
//#include "Location.h" wtf bri
#include "Board.h"
class Snake
{
public:
	Snake(const Location& in);
	void Draw(Board& brd) const;
public:
	Location loc;
	Color c = Colors::Yellow;
	 // Board brd; NO! it'd be different object than the relevant one
};

