#include "Frame.h"

Frame::Frame(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Frame::DrawAlles()
{
	Location LTL = Location ( Gap, Gap ); // left top left
	TriLTL(LTL, LL);
	LTL =  Location (Gap+ TriWidth, Gap+TriWidth); // left top right
	TriLTL(LTL, LR);
	LTL = Location(Gap, gfx.ScreenHeight - Gap - TriWidth); // left bottom left
	TriLDL(LTL, LL);
	LTL = Location(Gap+TriWidth, gfx.ScreenHeight - Gap - TriWidth- TriWidth); //left bottom right
	TriLDL(LTL, LL);

}

void Frame::TriLTL(Location& loc, Color c)
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

void Frame::TriLTL2(Location& loc, Color c)
{
	int SelfControl = 0;
	for (int y = loc.y; y <= loc.y + TriWidth; y++)
	{
		SelfControl++;
		for (int x = loc.x; x <= loc.x + SelfControl; x++)
		{
			gfx.PutPixel(y, x, Colors::Blue);
		}

	}
}

void Frame::TriLDL(Location & loc, Color c)
{
	int SelfControl = 11;
	for (int y = loc.y; y <= loc.y + TriWidth; y++)
	{
		SelfControl--;
		for (int x = loc.x; x <= loc.x + SelfControl; x++)
		{
			gfx.PutPixel(x, y, Colors::Red);
			// gfx.PutPixel(int(Y), int(X), Colors::Blue); MAKES THE OTHER HALF OF THE TRIANGLE c:
		}

	}
}
