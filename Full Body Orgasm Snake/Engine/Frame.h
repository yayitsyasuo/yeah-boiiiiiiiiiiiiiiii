#pragma once
#include "Graphics.h"
#include "Location.h"
class Frame
{
public:
	Frame(Graphics& gfx);
	void DrawAlles();
	void TriLTL(Location& loc, Color& c); // top left side triangle Left (touching the left side)
	void TriLTL2(Location& loc, Color& c);
	void TriLDL(Location& loc, Color& c);
	void TriLDL2(Location& loc, Color& c);
	void Rect(int x, int y, int x1, int y1, Color& c);
	Location GetLoc(int x, int y);
	Color GetColor(float factor);
private:
	static constexpr int Gap = 40; // lit.: space from left screen to right of the border 
	static constexpr int Width = 14;
	static constexpr int TriWidth = Width /2;

	static constexpr float leftFactor = 1.10f;
	static constexpr float topFactor = 0.93f;
	static constexpr float bottomFactor = 0.80f;
	static constexpr float rightFactor = 0.65f;
	Color BaseC = { 160, 160, 160 };
	Graphics&gfx;

};

