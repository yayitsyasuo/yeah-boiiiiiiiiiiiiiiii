#pragma once
// #include "Location.h" wtf
#include "Board.h"
class Snake
{
public:
	class Segment {
		public: // can't initialize constructor when the object is a fucking array
			void Init(const Location& loc);
			void Draw(Board& brd, Color c);
			void Update( Board& brd, const Location& dl);
			void SpawnSeg(Board& brd);
			const Location& GetLoc() const;
		private:
			Location loc; // used to have its own constructor hence the error- Segment would always have to do?
						//alright it needs to have my normal fucking constructor
						  // default constructor changed it all cool

	};
public:
	Snake(const Location& in, Board& brd);
	void Draw(Board& brd); // Board brd; NO! it'd be different object than the relevant one
	void Update( Board& brd, const Location& dl);
	void SpawnSegment(Board& brd);
	Location Follow();
private:
	static constexpr int segMax=100;
	int nSegments=1;
	Segment seg[segMax];
	Color c = Colors::Yellow;
	 // Board brd; NO! it'd be different object than the relevant one
	// Board brd; don't fucking use it 
};

