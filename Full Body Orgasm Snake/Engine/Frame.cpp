#include "Frame.h"

Frame::Frame(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Frame::DrawAlles()
{
	//left top left tri
	TriLTL(GetLoc(Gap,Gap), leftFactor);
	// left bottom left tri
	TriLDL(GetLoc(Gap, gfx.ScreenHeight - Gap - TriWidth), LL);
	//left left RECT
	Rect(Gap, Gap + TriWidth, Gap + TriWidth, gfx.ScreenHeight - Gap - TriWidth, LL);
	//left top right tri
	TriLTL(GetLoc(Gap + TriWidth, Gap+TriWidth), LR);
	//left bottom right
	TriLDL(GetLoc(Gap + TriWidth, gfx.ScreenHeight - Gap - TriWidth - TriWidth), LR);
	Rect(Gap + TriWidth, Gap + 2*TriWidth, Gap + 2*TriWidth, gfx.ScreenHeight - Gap - 2*TriWidth, LR);


	//left top left top tri
	Color ccusa = Colors::Red;
	TriLTL2(GetLoc(Gap, Gap), ccusa);
	//left top left bottom tri
	TriLTL2(GetLoc(Gap + TriWidth, Gap + TriWidth), ccusa);
	//top top rect
	Rect(Gap+TriWidth, Gap, gfx.ScreenWidth-TriWidth-Gap, Gap+TriWidth, LL);
	//top bottom rect
	Rect(Gap + 2*TriWidth, Gap + TriWidth, gfx.ScreenWidth - 2*TriWidth - Gap, Gap + 2*TriWidth, LL);
	//right top left tri
	TriLDL(GetLoc(gfx.ScreenWidth-Gap-TriWidth, Gap), LR);
	//right top left left tri
	TriLDL(GetLoc(gfx.ScreenWidth - Gap - 2*TriWidth, Gap+TriWidth), LR);

}

void Frame::TriLTL(Location& loc, Color& c)
{
	int SelfControl=0;
	for (int y=loc.y; y <= loc.y + TriWidth; y++)
	{
		SelfControl++;
		for (int x=loc.x; x < loc.x + SelfControl; x++)
		{
			gfx.PutPixel(x, y, c);
			// gfx.PutPixel(int(Y), int(X), Colors::Blue); MAKES THE OTHER HALF OF THE TRIANGLE c:
		}

	}
}

void Frame::TriLTL2(Location& loc, Color& c)
{
	int SelfControl = 0;
	for (int y = loc.y; y < loc.y + TriWidth; y++)
	{
		SelfControl++;
		for (int x = loc.x; x < loc.x + SelfControl; x++)
		{
			gfx.PutPixel(y, x, c);
		}
	}
}

void Frame::TriLDL(Location & loc, Color& c)
{
	int SelfControl = TriWidth +1;
	for (int y = loc.y; y <= loc.y + TriWidth; y++)
	{
		SelfControl--;
		for (int x = loc.x; x <= loc.x + SelfControl; x++)
		{
			gfx.PutPixel(x, y, c);
			// gfx.PutPixel(int(Y), int(X), Colors::Blue); MAKES THE OTHER HALF OF THE TRIANGLE c:
		}

	}
}

void Frame::TriLDL2(Location & loc, Color& c)
{
	int SelfControl = TriWidth + 1;
	for (int y = loc.y; y < loc.y + TriWidth; y++)
	{
		SelfControl--;
		for (int x = loc.x; x < loc.x + SelfControl; x++)
		{
			gfx.PutPixel(y, x, c);
			// gfx.PutPixel(int(Y), int(X), Colors::Blue); MAKES THE OTHER HALF OF THE TRIANGLE c:
		}

	}
}

void Frame::Rect(int x, int y, int x1, int y1, Color & c)
{
	gfx.DrawRect(x, y, x1 , y1 , c);
}

Location & Frame::GetLoc(int x, int y)
{
	Location loc(x, y);
	return loc;
}
