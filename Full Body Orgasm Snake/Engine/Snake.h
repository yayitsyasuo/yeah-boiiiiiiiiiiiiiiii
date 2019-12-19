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
			void Draw(Board& brd, Color c, Board::Content content);
			void LastContentUpdate( Board& brd, const Location& dl);
		//	void SpawnSeg(Board& brd);
		//	void Follow(Board& brd, const Location& l);
			Board::Content ControltheHead(Board& brd, const Location & dl);
			void ContentUpdate(Board& brd, const Location & dl,const Board::Content content);
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
	bool GetGameOver();
	bool GetDrugged();
	bool Drugged = false;
//	void SpawnSegment(Board& brd);
//	void Follow(Board& brd);
private:
	std::mt19937 rnd;
	Board& brd;
	static constexpr int segMax=100;
	int nSegments=1;
	int GoalsEaten = 1;
	Segment seg[segMax];
	Color c[14]{
		{255,255,255},{224,224,224},{192,192,192},{160,160,160},{128,128,128},
		{96,96,96},{64,64,64},{32,32,32},{64,64,64},{96,96,96},{128,128,128},
		{160,160,160},{192,192,192},{224,224,224}
	};
	int nColour=0;
	static constexpr int nColourMax = 13; // last element in the array
	Color HeadC = Colors::White;
	Color ObstacleC = Colors::LightGray;
	bool GameOver = false;
	bool justonce = true;
	 // Board brd; NO! it'd be different object than the relevant one
	// Board brd; don't fucking use it 
};

