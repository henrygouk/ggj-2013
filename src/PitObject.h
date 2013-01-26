#ifndef PITOBJECT_H
#define PITOBJECT_H

#include "Game.h"

class PitObject : public GameObject
{
	public:
		PitObject(GameScreen *gs, sf::Vector2f pos, sf::Vector2f dim);
		void update();
		void draw();
		
		sf::Vector2f dimensions;
};

#endif
