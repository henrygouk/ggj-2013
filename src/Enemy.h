#ifndef ENEMY_H
#define ENEMY_H

#include "Game.h"

class Enemy : public GameObject
{
	public:
		Enemy(GameScreen *gs, sf::Vector2f pos);
		void update();
		void draw();
};

#endif
