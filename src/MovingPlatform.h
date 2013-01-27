#ifndef MOVINGPLATFORM_H
#define MOVINGPLATFORM_H

#include "Game.h"

class MovingPlatform : public Platform
{
	public:
		sf::Vector2f start, end;
	
		MovingPlatform(GameScreen* gs, sf::Vector2f pos, sf::Vector2f dimens, sf::Vector2f dst, float speed, std::string filename);
		void update();
		void draw();
};

#endif
