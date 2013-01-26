#include "Game.h"

using namespace sf;
GameScreen::GameScreen()
{
	enableUpdate = true;
	enableDraw = true;
}

GameScreen::~GameScreen()
{
	//Free all the game objects
	for(size_t i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}
}

void GameScreen::update()
{
	if(enableUpdate)
	{
		for(size_t i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->update();
		}
	}
	
	cameraPosition.x = max(cameraPosition.x, 0.0f);
}

void GameScreen::draw()
{
	if(enableDraw)
	{
		for(size_t i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->draw();
		}
	}
}
