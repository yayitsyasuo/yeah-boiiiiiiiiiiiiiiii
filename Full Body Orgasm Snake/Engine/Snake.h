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
	int GetScore() const;
	void Draw();
	void Update(const Location& dl);
	bool GetGameOver();
	bool Drugged = false;
	bool SpeedMeUp = false;
private:
	std::mt19937 rnd;
	Board& brd;
	int GoalsEaten = 0;
	static constexpr int nColourMax = 4;
	std::vector <Segment> seg;
	Color c[nColourMax+1]{
		{0,0,0},
		{38, 38, 38},
		{115, 115, 115},
		{153, 153, 153}
	};
	int nColour=0;
	Color HeadC = Colors::MakeRGB(79, 198, 255);
	Color ObstacleC = Colors::MakeRGB(128, 128, 128);
	bool GameOver = false;
	bool justonce = true;
	bool inhibit = false;
};

