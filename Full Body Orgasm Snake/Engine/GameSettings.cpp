#include "GameSettings.h"
#include <fstream>
#include <string>

GameSettings::GameSettings(const std::string& File)
{
	std::ifstream in(File);
	
	for ( str ; !in.eof() ; std::getline( in, str ) )
	{
		if (str.find("-TILE SIZE") != std::string::npos)
		{
			in >> TileSize;
		}
		else if (str.find("-BOARD DIMENSIONS") != std::string::npos)
		{
			in >> BoardSizeX >> BoardSizeY;
		}
	}
}


int GameSettings::GetTileSize() const
{
	return TileSize;
}
