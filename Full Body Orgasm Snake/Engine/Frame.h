#pragma once
#include "Graphics.h"
#include "Location.h"
#include "GameSettings.h"
#include "Board.h"
class Frame
{
public:
	Frame(Graphics& gfx, GameSettings& gt, Board& brd);
	void DrawAlles();
	void TriLTL(Location& loc, Color& c); // top left side triangle Left (touching the left side)
	void TriLTL2(Location& loc, Color& c);
	void TriLDL(Location& loc, Color& c);
	void TriLDL2(Location& loc, Color& c);
	void Rect(int x, int y, int x1, int y1, Color& c);
	Location GetLoc(int x, int y);
	Color GetColor(float factor);
private:
	int Gap; // lit.: space from left screen to right of the border 
	int DynamicGapBottom;
	int DynamicGapRight;
	int BoardSizeX;
	int BoardSizeY;
	static constexpr int Width = 14;
	static constexpr int TriWidth = Width /2;
	static constexpr float leftFactor = 1.10f; //1,10
	static constexpr float topFactor = 0.93f;
	static constexpr float bottomFactor = 0.80f;
	static constexpr float rightFactor = 0.65f;
	Color BaseC = { 96,96,96 };
	Graphics&gfx;
	Board& brd;

};

