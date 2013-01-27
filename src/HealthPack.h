#ifndef HELATHPACK_H
#define HELATHPACK_H

#include "Game.h"

class HealthPack : public GameObject
{
	public:
		HealthPack(GameScreen *gs, sf::Vector2f pos, bool h);
		void update();
		void draw();
		
		static sf::Image healthPack;
		static sf::Image uberPack;
		static sf::PostFX effect;
		static bool loaded;
		bool health;
		float remaining;
};

#endif
