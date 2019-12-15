#pragma once
//#include "Location.h" wtf bri
#include "Board.h"
class Snake
{
public:
	class Segment {
		public:
			void Init(const Location& loc);
			void Draw(Board& brd, Color c);
			void Update(const Location& dl);
		private:
			Location loc;


	};
public:
	Snake(const Location& in);
	void Draw(Board& brd);
	void Update(const Location& dl);
public:
	Segment seg[100];
	Color c = Colors::Yellow;
	 // Board brd; NO! it'd be different object than the relevant one
};

