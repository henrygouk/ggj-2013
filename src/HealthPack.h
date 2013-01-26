#ifndef HELATHPACK_H
#define HELATHPACK_H

#include "Game.h"

class HealthPack : public GameObject
{
	public:
		HealthPack(GameScreen *gs, sf::Vector2f pos);
		void update();
		void draw();
		
		static sf::Image healthPack;
		static bool loaded;
};

#endif
