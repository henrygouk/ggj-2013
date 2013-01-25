#include "Game.h"

using namespace sf;

GameScreen::GameScreen()
{
	enableUpdate = true;
	enableDraw = true;
	
	gameObjects.push_back(new PlayerObject(Vector2f(100.0, 100.0)));
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
