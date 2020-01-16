#pragma once
#include <string>
class GameSettings
{
public:
	GameSettings(const std::string& File);
	int GetTileSize() const;
private:
	std::string str;
	int TileSize;
	int BoardSizeX;
	int BoardSizeY;
};

