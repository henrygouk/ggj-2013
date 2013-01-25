#include "Game.h"

using namespace glm;

GameScreen::GameScreen()
{
	enableUpdate = true;
	enableDraw = true;
	
	gameObjects.push_back(new PlayerObject(vec2(0.0, 0.0)));
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
