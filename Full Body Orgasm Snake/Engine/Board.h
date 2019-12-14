#pragma once
class Board
{
public:
	enum class Content
	{
		Nothing,
		Snake
	};
public:
public:
	static int constexpr Columns = 760 / 20;
	static int constexpr Rows = 560 / 20;
	static int constexpr dimension = 20;
	Content Board1D[Columns*Rows] = {Content::Nothing};

};

