#pragma once
// #include "Location.h" wtf
#include "Board.h"
#include <random>
class Snake
{
public:
	class Segment {
		public: // can't initialize constructor when the object is a fucking array
			void Init(const Location& loc);
			void Draw(Board& brd, Color c);
			void LastContentUpdate( Board& brd, const Location& dl);
		//	void SpawnSeg(Board& brd);
		//	void Follow(Board& brd, const Location& l);
			Board::Content ControltheHead(Board& brd, const Location & dl);
			void ContentUpdate(Board& brd, const Location & dl);
			const Location& GetLoc() const;
		private:
			Location loc; // used to have its own constructor hence the error- Segment would always have to do?
						//alright it needs to have my normal fucking constructor
						  // default constructor changed it all cool

	};
public:
	Snake(const Location& in, Board& brd);
	void Draw(); // Board brd; NO! it'd be different object than the relevant one
	void Update(const Location& dl);
//	void SpawnSegment(Board& brd);
//	void Follow(Board& brd);
private:
	std::mt19937 rnd;
	Board& brd;
	static constexpr int segMax=100;
	int nSegments=1;
	Segment seg[segMax];
	Color c = Colors::Yellow;
	bool justonce = true;
	 // Board brd; NO! it'd be different object than the relevant one
	// Board brd; don't fucking use it 
};

