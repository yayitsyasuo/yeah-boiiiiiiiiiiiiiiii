#pragma once
#include <chrono>

class FrameTimer
{
public:
	FrameTimer() 
		:
		last(std::chrono::steady_clock::now())
	{
	}

	float MarkT()
	{
		using std::chrono::steady_clock;

		auto old = last;
		last = steady_clock::now();

		const std::chrono::duration<float> FrameTime = last - old;
		return FrameTime.count();
	}

public:
	std::chrono::steady_clock::time_point last;
};

