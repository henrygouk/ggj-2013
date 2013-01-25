#include "Game.h"

GameScreen::GameScreen()
{
	enableUpdate = false;
	enableDraw = false;
}

GameScreen::~GameScreen()
{
	//Free all the game objects
	for(size_t i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}
}
