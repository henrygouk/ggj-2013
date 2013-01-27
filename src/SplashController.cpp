#include "Game.h"

#include <iostream>

using namespace std;
using namespace sf;

SplashController::SplashController(int end)
{
	countDownDoStuff = false;
	doStuffDelay = 0;
	isFinallyEnd = end;
}

void SplashController::update() 
{
	if(!countDownDoStuff && window->GetInput().IsKeyDown(Key::Space))
	{
		countDownDoStuff = true;
		doStuffDelay = 1;
	}

	doStuffDelay -= 2 * DELTA_TIME;
	if (countDownDoStuff && doStuffDelay <= 0)
	{
		if (!isFinallyEnd)
		{
			gameScreens[0]->enableDraw = false;
			gameScreens[0]->enableUpdate = false;
			gameScreens[1]->enableDraw = true;
			gameScreens[1]->enableUpdate = true;
			gameScreens[2]->enableDraw = true;
			gameScreens[2]->enableUpdate = true;
		}
			else
		{
			running = false;
		}
	}
}

void SplashController::draw()
{
}
