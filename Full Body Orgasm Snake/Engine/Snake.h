#pragma once
// #include "Location.h" wtf
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
			Location loc; // used to have its own constructor hence the error- Segment would always have to do?
						//alright it needs to have my normal fucking constructor
						  // default constructor changed it all cool

	};
public:
	Snake(const Location& in, Board& brd);
	void Draw(Board& brd); // Board brd; NO! it'd be different object than the relevant one
	void Update(const Location& dl);
public:
	Segment seg[100];
	Color c = Colors::Yellow;
	 // Board brd; NO! it'd be different object than the relevant one
	// Board brd; don't fucking use it 
};

