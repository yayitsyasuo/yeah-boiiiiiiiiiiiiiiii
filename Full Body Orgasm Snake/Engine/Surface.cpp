#include "Surface.h"
#include <assert.h>

Surface::Surface(const std::string& file)
{
	std::ifstream f(file, std::ios::binary);
	assert(f);
	BITMAPFILEHEADER bit_map;
	f.read( reinterpret_cast<char*> ( & bit_map ) , sizeof(bit_map)); //reint_cast because 
	// f.read wants a pointer to a char and were're giving him some bit_map bs
	//i mean (char *) bit_map is also find but we want swag

	BITMAPINFOHEADER bit_map_info;
	f.read(reinterpret_cast<char*>(&bit_map_info), sizeof(bit_map_info));

	width = bit_map_info.biWidth;
	int yBeginn;
	int yEnde;
	int dy;
	if (bit_map_info.biHeight < 0)
	{
		height = -bit_map_info.biHeight;
		yBeginn = 0;
		yEnde = height;
		dy = 1;
	}
	else
	{
		height = bit_map_info.biHeight;
		yEnde = -1;
		yBeginn = height - 1;
		dy = -1;
	}
	pPixColor = new Color[width*height];
	f.seekg(bit_map.bfOffBits);
	
	assert(bit_map_info.biBitCount == 24 || bit_map_info.biBitCount == 32);
	
	const int padding = (4 - width*3 %4 ) %4 ;
	const bool is32b = bit_map_info.biBitCount == 32;

	for (int y = yBeginn; y != yEnde; y += dy)
	{
		for (int x = 0; x < width; x++)
		{
			PutPixel(x, y, Color(f.get(), f.get(), f.get()));
			if (is32b)
			{
				f.seekg(1, std::ios::cur);
			}
		}
		if(!is32b)
		f.seekg(padding, std::ios::cur);
	}
}

Surface::Surface(const Surface & sur)
	:
	Surface(sur.width, sur.height)
{
	for (int i = 0 ; i < height * width ; i++)
	{
		pPixColor[i] = sur.pPixColor[i];
	}
}

Surface::Surface(int width, int height)
	:
	width(width),
	height(height),
	pPixColor(new Color[width*height])
{
}



Surface::~Surface()
{
	delete[] pPixColor;
	pPixColor = nullptr;
}

Surface & Surface::operator=(const Surface & sur)
{
	width = sur.width;
	height = sur.height;
	delete[] pPixColor;
	pPixColor = new Color[width*height];

	for (int i = 0; i < height * width; i++)
	{
		pPixColor[i] = sur.pPixColor[i];
	}

	return *this;
}

void Surface::PutPixel(const int x, const int y, const Color c) // that's the boi controling colors
{
	assert(x >= 0);
	assert(y >= 0);
	assert(x < width);
	assert(y < height);
	pPixColor[y*width + x] = c;
}

Color Surface::GetPixelC(const int x, const int y) const
{
	assert(x >= 0);
	assert(y >= 0);
	assert(x < width);
	assert(y < height);
	return pPixColor[y*width + x];
}

Color Surface::GetPixelC_swapped(const int x, const int y, Color chroma, Color swap_to) const
{
	assert(x >= 0);
	assert(y >= 0);
	assert(x < width);
	assert(y < height);
	if (pPixColor[y*width + x] != chroma)
		return swap_to;
	else
		return pPixColor[y*width + x];
}

RectI Surface::GetRect() const
{
	return RectI( 0 , width, 0, height );
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}
