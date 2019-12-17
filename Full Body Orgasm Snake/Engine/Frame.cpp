#include "Frame.h"

// Frame::Frame()
// 	:
// 	gfx(gfx)
// {
// }


void Frame::TriLTL(Graphics& gfx)
{
	float SelfControl=0.0f;
	for (float Y = Gap; Y < Gap + TriWidth; Y++)
	{
		SelfControl++;
		for (float X = Gap; X <= Gap + SelfControl; X++)
		{
			gfx.PutPixel(int(X), int(Y), Colors::Blue);
			// gfx.PutPixel(int(Y), int(X), Colors::Blue); MAKES THE OTHER HALF OF THE TRIANGLE c:
		}

	}
}
