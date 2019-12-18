#include "Frame.h"

Frame::Frame(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Frame::DrawAlles()
{
	//left top-bottom tri
	Location LTL = Location ( Gap, Gap ); // left top left
	TriLTL(LTL, LL);
	Location LBL = Location(Gap, gfx.ScreenHeight - Gap - TriWidth); // left bottom left
	TriLDL(LBL, LL);

	//left top-bottom rect
	Location RectTopLeft = LTL + Location(0, TriWidth);
	Location RectBottomLeft = LBL + Location(TriWidth, 0);
	Rect(RectTopLeft, RectBottomLeft, LL); //WRONG DIMENSION :>

	LTL =  Location (Gap+TriWidth, Gap + TriWidth); // left top right
	TriLTL(LTL, LR);
	LBL = Location(Gap+TriWidth, gfx.ScreenHeight - Gap - TriWidth- TriWidth); //left bottom right

	TriLDL(LBL, LR);
	RectTopLeft = LTL + Location(0, TriWidth);
	RectBottomLeft = LBL + Location(TriWidth, 0);
	Rect(RectTopLeft, RectBottomLeft, LR);

}

void Frame::TriLTL(Location& loc, Color& c)
{
	int SelfControl=0;
	for (int y=loc.y; y <= loc.y + TriWidth; y++)
	{
		SelfControl++;
		for (int x=loc.x; x <= loc.x + SelfControl; x++)
		{
			gfx.PutPixel(x, y, c);
			// gfx.PutPixel(int(Y), int(X), Colors::Blue); MAKES THE OTHER HALF OF THE TRIANGLE c:
		}

	}
}

void Frame::TriLTL2(Location& loc, Color& c)
{
	int SelfControl = 0;
	for (int y = loc.y; y <= loc.y + TriWidth; y++)
	{
		SelfControl++;
		for (int x = loc.x; x <= loc.x + SelfControl; x++)
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

void Frame::Rect(Location & loc0, Location & loc1, Color & c)
{
	gfx.DrawRect(loc0.x, loc0.y, loc1.x , loc1.y , c);
}
