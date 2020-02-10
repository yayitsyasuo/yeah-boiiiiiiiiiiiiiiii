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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx, gt),
	snake({ 5, 3 }, brd),
	rnd(std::random_device()()),
	f(gfx, gt, brd),
	dtSumLimit(gt.GetSpeed()),
	score("Images\\Fixedsys16x28.bmp", 32, 3, Colors::White)
{
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
	if (!snake.GetGameOver())
	{
		const float dt = ft.MarkT();

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

		if (snake.Drugged)
		{
			dtSumLimit += 0.05f;
			snake.Drugged = false;
		}
		dtSum += dt;
		if (dtSum > dtSumLimit) // dtSum controls the speed
		{
			dtSum = 0;
			snake.Update(dloc);
			if (snake.SpeedMeUp) // cringe method but w/e
			{
				dtSumLimit -= 0.0003f;
				snake.SpeedMeUp = false;
			}
			dtSumLimit = dtSumLimit - 0.0001f; // speeding up
		}
	}
}

void Game::SpeedUp()
{
	//fucked up speed up
	dtSumLimit -= 0.0003f;
}

void Game::ComposeFrame()
{
	for (int x = 0; x < 799; x++)
	{
		for (int y = 0; y < 599; y++)
		{
			gfx.PutPixel(x,y,Colors::White);
		}
	}
	score.Draw(" Score: " + std::to_string(snake.GetScore()), gfx, Vei2 (500,300));
	brd.DrawCells(c, Board::Content::Fruit);
	//brd.DrawCells(cPoison, Board::Content::Poison);
	//f.DrawAlles();
	snake.Draw();
	if (snake.GetGameOver())
	{
		sprite.DrawGameOver(350, 100, gfx);
	}
}
