#pragma once
//#include "Location.h" wtf bri
#include "Board.h"
class Snake
{
public:
	class Segment {
		public:
			void Init(const Location& loc);
			Location loc;


	};
public:
	void SnakeHeadInit(const Location& in);
	void Draw(Board& brd) const;
	void Update(Location& dl);
public:
	Segment seg[100];
	Color c = Colors::Yellow;
	 // Board brd; NO! it'd be different object than the relevant one
};

