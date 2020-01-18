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
		else if (str.find("-POISON AMOUNT") != std::string::npos)
		{
			in >> PoisonAmount;
		}
		else if (str.find("-FOOD AMOUNT") != std::string::npos)
		{
			in >> nFruits;
		}
		else
		{
			std::runtime_error("Bad fucking input man");
		}
	}
}

int GameSettings::GetnFruits() const
{
	return nFruits;
}

int GameSettings::GetnPoison() const
{
	return PoisonAmount;
}

int GameSettings::GetTileSize() const
{
	return TileSize;
}

int GameSettings::GetBoardSizeX() const
{
	return BoardSizeX;
}

int GameSettings::GetBoardSizeY() const
{
	return BoardSizeY;
}
