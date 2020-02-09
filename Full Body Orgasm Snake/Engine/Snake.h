#pragma once
#include "Board.h"
#include <random>
#include <vector>
class Snake
{
public:
	class Segment {
		public:	
			Segment(const Location& locc)
				:
				loc(locc)
			{
			}
			void Draw(Board& brd, Color c, const Board::Content content);
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
	int GoalsEaten = 1;
	static constexpr int nColourMax = 12;
	std::vector <Segment> seg;
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
};

