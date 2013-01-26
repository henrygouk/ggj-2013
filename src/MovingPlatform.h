#ifndef MOVINGPLATFORM_H
#define MOVINGPLATFORM_H

#include "Game.h"

class MovingPlatform : public Platform
{
	public:
		MovingPlatform(GameScreen* gs, sf::Vector2f pos, sf::Vector2f dimens, sf::Vector2f velo);
		void update();
		void draw();

		float top();
		float left();
		float right();
	
		sf::Vector2f dimensions;
};

#endif
