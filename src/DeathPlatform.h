#ifndef DEATHZONE_H 
#define DEATHZONE_H

#include "Game.h"

class DeathPlatform : public Platform 
{
	public:
		DeathPlatform(GameScreen* gs, sf::Vector2f pos, sf::Vector2f dimens, float _damage, std::string background, float _scale);
		void update();
		void draw();

		float scale;
		float damage;
};

#endif
