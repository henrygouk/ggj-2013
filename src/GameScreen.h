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
		
		GameScreen();
		virtual ~GameScreen();
		virtual void update() = 0;
		virtual void draw() = 0;
};

#endif
