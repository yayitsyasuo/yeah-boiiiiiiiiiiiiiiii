#pragma once
class Location
{
public:
	Location(int x_in, int y_in)
			:
		x(x_in),
		y(y_in)
	{
	}
	Location() = default; // why is it necessary here?
	Location operator+(const Location& rhs) const
	{
		return Location ( x + rhs.x , y + rhs.y );
	}
	Location& operator+=(const Location& rhs)
	{
		return *this = *this + rhs;
	}
public:
	int x;
	int y;
};

