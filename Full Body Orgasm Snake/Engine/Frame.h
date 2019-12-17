#pragma once
#include "Graphics.h"
#include "Location.h"
class Frame
{
public:
	Frame(Graphics& gfx);
	void DrawAlles();
	void TriLTL(Location& loc, Color c); // top left side triangle Left (touching the left side)
	void TriLTL2(Location& loc, Color c);
	void TriLDL(Location& loc, Color c);
private:
	static constexpr int Gap = 40; // lit.: space from left screen to right of the border 
	static constexpr int Width = 20;
	static constexpr int TriWidth = 10;
	Color c = {211,211,211};
	Color LL = { 160, 160, 160 }; //left left
	Color LR = { 96 ,96 ,96 }; //left right
	Graphics&gfx;

};

