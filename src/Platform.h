#ifndef PLATFORM_H
#define PLATFORM_H

#include "Game.h"

class Platform : public GameObject
{
	public:
		virtual void update() = 0;
		virtual void draw() = 0;
		
		float top();
		float left();
		float right();
	
		sf::Vector2f dimensions;
};

#endif
