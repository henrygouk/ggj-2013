#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <vector>

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
		void update();
		void draw();
};

#endif
