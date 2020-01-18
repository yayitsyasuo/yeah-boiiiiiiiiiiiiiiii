#include "Frame.h"

Frame::Frame(Graphics& gfx, GameSettings& gt, Board& brd)
	:
	gfx(gfx),
	brd(brd),
	BoardSizeX(gt.GetBoardSizeX()),
	BoardSizeY(gt.GetBoardSizeY()),
	DynamicGapRight(Graphics::ScreenWidth - ( gt.GetBoardSizeX() ) * gt.GetTileSize()  ),
	DynamicGapBottom(Graphics::ScreenHeight - (gt.GetBoardSizeY() + 1) * gt.GetTileSize())
{
	// fucking -1 beacuse the whole shit starts from 0 !!!
	for (int y = 0; y <= BoardSizeY - 1; y++) // left /right side             ///// USED TO BE 28
	{
		brd.SpawnContent(Location(0, y), Board::Content::Wall);
		brd.SpawnContent(Location(BoardSizeX - 1, y), Board::Content::Wall);  ////// USED TO BE 37
	}
	for (int x = 1; x < BoardSizeX - 1; x++) // left /right side           ////// USED TO BE 37
	{
		brd.SpawnContent(Location(x, 0), Board::Content::Wall);
		brd.SpawnContent(Location(x, BoardSizeY - 1), Board::Content::Wall); ///// USED TO BE 28
	}
}

void Frame::DrawAlles()
{
	Color cc = Colors::Red;
	//left top left tri
	TriLTL(GetLoc(Gap,Gap), GetColor(leftFactor));
	// left bottom left tri
	TriLDL(GetLoc(Gap, gfx.ScreenHeight+ 1 - DynamicGapBottom - TriWidth), GetColor(leftFactor));
	//left left RECT
	Rect(Gap, Gap + TriWidth, Gap + TriWidth, gfx.ScreenHeight+ 1 - DynamicGapBottom - TriWidth, GetColor(leftFactor));
	//left top right tri
	TriLTL(GetLoc(Gap + TriWidth, Gap+TriWidth), GetColor(rightFactor));
	//left bottom right
	TriLDL(GetLoc(Gap + TriWidth, gfx.ScreenHeight+ 1 - DynamicGapBottom - TriWidth - TriWidth), GetColor(rightFactor));
	Rect(Gap + TriWidth, Gap + 2*TriWidth, Gap + 2*TriWidth, gfx.ScreenHeight+ 1 - DynamicGapBottom - 2*TriWidth, GetColor(rightFactor));


	//left top left top tri
	TriLTL2(GetLoc(Gap, Gap), GetColor(topFactor));
	//left top left bottom tri
	TriLTL2(GetLoc(Gap + TriWidth, Gap + TriWidth), GetColor(bottomFactor));
	//top top rect
	Rect(Gap+TriWidth, Gap, gfx.ScreenWidth + 1-TriWidth-DynamicGapRight, Gap + TriWidth, GetColor(topFactor));
	//top bottom rect
	Rect(Gap + 2*TriWidth, Gap + TriWidth, gfx.ScreenWidth + 1 - 2*TriWidth - DynamicGapRight, Gap + 2*TriWidth, GetColor(bottomFactor));
	//right top left tri
	TriLDL(GetLoc(gfx.ScreenWidth + 1- DynamicGapRight -TriWidth, Gap), GetColor(topFactor));
	//right top left left tri
	TriLDL(GetLoc(gfx.ScreenWidth + 1 - DynamicGapRight - 2*TriWidth, Gap+TriWidth), GetColor(bottomFactor));
	//right top right right
	//right top right right bottom
	TriLDL2(GetLoc(gfx.ScreenWidth + 1 - DynamicGapRight, Gap), GetColor(rightFactor));
	TriLDL2(GetLoc(gfx.ScreenWidth + 1 - DynamicGapRight - TriWidth, Gap + TriWidth), GetColor(leftFactor));
	//right right rect
	Rect(gfx.ScreenWidth + 1 - DynamicGapRight - 2 * TriWidth, Gap + 2 * TriWidth, gfx.ScreenWidth + 1 - DynamicGapRight - TriWidth, gfx.ScreenHeight+ 1 - DynamicGapBottom - 2 * TriWidth, GetColor(leftFactor));
	//right left reect
	Rect(gfx.ScreenWidth + 1 - DynamicGapRight - TriWidth, Gap + TriWidth, gfx.ScreenWidth + 1 - DynamicGapRight, gfx.ScreenHeight+ 1 - DynamicGapBottom -  TriWidth, GetColor(rightFactor));

	//left bottom left left
	TriLDL2(GetLoc(Gap+TriWidth, gfx.ScreenHeight+ 1 - DynamicGapBottom- TriWidth), GetColor(bottomFactor));
	TriLDL2(GetLoc(Gap+ 2*TriWidth, gfx.ScreenHeight+ 1 - DynamicGapBottom - 2*TriWidth), GetColor(topFactor));

	//right bottom right right
	TriLTL2(GetLoc(gfx.ScreenWidth + 1 - DynamicGapRight - TriWidth, gfx.ScreenHeight+ 1 - DynamicGapBottom - TriWidth), GetColor(rightFactor));
	TriLTL2(GetLoc(gfx.ScreenWidth + 1 - DynamicGapRight - 2 * TriWidth, gfx.ScreenHeight+ 1 - DynamicGapBottom - 2 * TriWidth), GetColor(leftFactor));
	//right bottom left
	TriLTL(GetLoc(gfx.ScreenWidth + 1 - DynamicGapRight - TriWidth, gfx.ScreenHeight+ 1 - DynamicGapBottom - TriWidth), GetColor(bottomFactor));
	TriLTL(GetLoc(gfx.ScreenWidth + 1 - DynamicGapRight - 2*TriWidth, gfx.ScreenHeight+ 1 - DynamicGapBottom - 2*TriWidth), GetColor(topFactor));

	//bottom top rect
	Rect(Gap + 2 * TriWidth, gfx.ScreenHeight+ 1 - DynamicGapBottom - 2 * TriWidth, gfx.ScreenWidth + 1 - DynamicGapRight - 2 * TriWidth, gfx.ScreenHeight+ 1 - TriWidth - DynamicGapBottom, GetColor(topFactor));
	//bottom bottom rect
	Rect(Gap+TriWidth, gfx.ScreenHeight+ 1- DynamicGapBottom -TriWidth, gfx.ScreenWidth + 1- DynamicGapRight -TriWidth, gfx.ScreenHeight+ 1 - DynamicGapBottom, GetColor(bottomFactor));
}

void Frame::TriLTL(Location& loc, Color& c)
{
	int SelfControl=0;
	for (int y=loc.y ; y < loc.y + TriWidth; y++)
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
	int SelfControl = -1;
	for (int y = loc.y; y < loc.y + TriWidth; y++)
	{
		SelfControl++;
		for (int x = loc.x+SelfControl; x < loc.x+TriWidth; x++)
		{
			gfx.PutPixel(x, y, c);
		}
	}
}

void Frame::TriLDL(Location & loc, Color& c)
{
	int SelfControl = TriWidth +1;
	for (int y = loc.y; y <= loc.y + TriWidth; y++)
	{
		SelfControl--;
		for (int x = loc.x; x < loc.x + SelfControl; x++)
		{
			gfx.PutPixel(x, y, c);
			// gfx.PutPixel(int(Y), int(X), Colors::Blue); MAKES THE OTHER HALF OF THE TRIANGLE c:
		}

	}
}

void Frame::TriLDL2(Location & loc, Color& c)
{
	int SelfControl = 0;
	for (int y = loc.y; y < loc.y + TriWidth; y++)
	{
		SelfControl++;
		for (int x = loc.x - 1; x > loc.x - SelfControl; x--)
		{
			gfx.PutPixel(x, y, c);
			// gfx.PutPixel(int(Y), int(X), Colors::Blue); MAKES THE OTHER HALF OF THE TRIANGLE c:
		}

	}
}

void Frame::Rect(int x, int y, int x1, int y1, Color & c)
{
	gfx.DrawRect(x, y, x1 , y1 , c);
}

Location Frame::GetLoc(int x, int y)
{
	Location loc(x, y);
	return loc;
}

Color Frame::GetColor(float factor)
{
	float R =float (BaseC.GetR()) * factor;
	float G =float (BaseC.GetB()) * factor;
	float B =float (BaseC.GetG()) * factor;
	Color c2= Color( (int) R, (int) G,(int) B );
	return c2;
}
