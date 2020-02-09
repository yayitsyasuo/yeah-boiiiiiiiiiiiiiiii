#pragma once
#include <string>
class GameSettings
{
public:
	GameSettings(const std::string& File);
	int GetTileSize() const;
	int GetBoardSizeX() const;
	int GetBoardSizeY() const;
	int GetnPoison() const;
	int GetnFruits() const;
	float GetSpeed() const;

private:
	std::string str;
	int TileSize;
	int BoardSizeX;
	int BoardSizeY;
	int PoisonAmount;
	int nFruits;
	float Speed;
};

