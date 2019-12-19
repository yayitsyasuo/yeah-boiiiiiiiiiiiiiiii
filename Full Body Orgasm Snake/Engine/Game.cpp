/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	snake({15, 10}, brd),
	brd(gfx),
	rnd(std::random_device ()()),
	f(gfx)
{
	for(int i=0; i<nFruits; i++)
	brd.SpawnFeature(rnd, Board::Content::Fruit);
	// snake.SpawnSegment(brd);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt= ft.MarkT();

	if (wnd.kbd.KeyIsPressed(0x41)) // A
	{
		if (r == Richtung::right)
		{
		}
		else {
			dloc = { -1,0 };
			r = Richtung::left;
		}
	}
	if (wnd.kbd.KeyIsPressed(0x44)) // D
		if (r == Richtung::left)
		{
		}
		else {
			dloc = { 1,0 };
			r = Richtung::right;
		}
	if (wnd.kbd.KeyIsPressed(0x57)) // W
		if (r == Richtung::down)
		{
		}
		else {
			dloc = { 0,-1 };
			r = Richtung::up;
		}
	if (wnd.kbd.KeyIsPressed(0x53)) // S
	{
		if (r == Richtung::up)
		{
		}
		else {
			dloc = { 0, 1 };
			r = Richtung::down;
		}
	}

	dtSum += dt;
	if (dtSum > dtSumLimit)
	{
		dtSum -= dtSum;
		snake.Update(dloc);
	}
}

void Game::ComposeFrame()
{
	snake.Draw();
	brd.DrawCells(c, Board::Content::Fruit);
	f.DrawAlles();
}
