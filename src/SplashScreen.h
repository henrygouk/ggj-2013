#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "Game.h"

class GameObject;

class GameScreen
{
	public:
		bool enableUpdate;
		bool enableDraw;
		std::vector<GameObject *> gameObjects;
		sf::Vector2f cameraPosition;
		
		GameScreen();
		~GameScreen();
		virtual void update();
		virtual void draw();

		sf::Vector2f normaliseCoords(sf::Vector2f pos);
};

#endif
