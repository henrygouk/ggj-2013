#ifndef ENEMY_H
#define ENEMY_H

#include "Game.h"

class Enemy : public GameObject
{
	public:
		sf::Vector2f start, end;
	
		Enemy(GameScreen *gs, sf::Vector2f pos, sf::Vector2f v);
		void update();
		void draw();
};

#endif
