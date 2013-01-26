#ifndef BLOODSQUIRT_H
#define BLOODSQUIRT_H

#include "Game.h"

class BloodSquirt : public GameObject
{
	public:
		BloodSquirt(GameScreen *gs, sf::Vector2f pos, float time, bool flip);
		void update();
		void draw();
		
		float power;
		bool drawMe;
		sf::Clock timer;
};

#endif
