#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Game.h"

class Background : public GameObject
{
	public:
		Background(GameScreen *gs, sf::Vector2f pos, std::string image);
		void update();
		void draw();
};

#endif
