#pragma once
#include "Location.h"
#include "Board.h"
class Snake
{
public:
	Snake(const Location& in);
public:
	Location loc;
	Board brd;
};

