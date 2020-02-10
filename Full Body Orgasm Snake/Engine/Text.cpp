#include "Text.h"
#include <assert.h>

Text::Text(const std::string& file, Color chroma)
	:
	text(file),
	FontWidth(text.GetWidth() / nColumns),
	FontHeight(text.GetHeight() / nRows),
	chroma(chroma)
{
	// making sure that the bit map has proper width/height values - could be some off space at the ends
	assert (nColumns * FontWidth == text.GetWidth());
	assert (nRows * FontHeight == text.GetHeight());
	//Fixedsys16x28

	for (int y = 0; y < nRows; y++)
	{
		for (int x = 0; x < nColumns; x++)
		{
			letter.emplace_back(x * FontWidth, (x + 1) * FontWidth, y * FontHeight, (y+1) * FontHeight);
		}
	}
}

void Text::Draw(const std::string& display_text, Graphics & gfx, Vei2 pos)
{
	const int posX_copy = pos.x;
	for (int i = 0; i < display_text.size(); i++)
	{	
		assert(display_text[i] >= ' ' && display_text[i] <= '~' || display_text[i] == '\n');
		
		const int index = display_text[i] - ' ';
		
		if (display_text[i] == '\n')
			{
				pos.y += FontHeight;
				pos.x = posX_copy;
			}
		else
		{
			pos.x += FontWidth;
			gfx.DrawSpriteColorSwap(pos.x, pos.y, letter[index], text, Colors::White, chroma);
		}
	}
}
