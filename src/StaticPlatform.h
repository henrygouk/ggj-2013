#ifndef STATICPLATFORM_H
#define STATICPLATFORM_H

#include "Game.h"

class StaticPlatform : public Platform
{
	public:
		StaticPlatform(GameScreen* gs, sf::Vector2f pos, sf::Vector2f dimens, std::string filename);
		void update();
		void draw();
		
		bool loaded;
};

#endif
