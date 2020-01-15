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
			Board::Content ControltheHead(Board& brd, const Location & dl);
			void ContentUpdate(Board& brd, const Location & dl,const Board::Content content);
			const Location& GetLoc() const;
		private:
			Location loc;

	};
public:
	Snake(const Location& in, Board& brd);
	void Draw();
	void Update(const Location& dl);
	bool GetGameOver();
	bool Drugged = false;
	bool SpeedMeUp = false;
private:
	std::mt19937 rnd;
	Board& brd;
	static constexpr int segMax=100;
	int nSegments=1;
	int GoalsEaten = 1;
	static constexpr int nColourMax = 12;
	Segment seg[segMax];
	Color c[nColourMax+1]{
		{204,255,229},{153,255,204},{102,255,178},
		{51,255,153},{0,255,128},{0,204,102},	
		{0,153,76},{0,204,102},{0,255,128},
		{51,255,153},{102,255,178},{153,255,204},
		{204,255,229}
	};
	int nColour=0;
	Color HeadC = Colors::MakeRGB(255, 255, 0);
	Color ObstacleC = Colors::MakeRGB(128, 128, 128);
	bool GameOver = false;
	bool justonce = true;
	 // Board brd; NO! it'd be different object than the relevant one
	// Board brd; don't fucking use it 
};

