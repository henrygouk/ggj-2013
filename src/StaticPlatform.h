#ifndef STATICPLATFORM_H
#define STATICPLATFORM_H

#include "Game.h"

class StaticPlatform : public GameObject
{
	public:
		StaticPlatform(GameScreen* gs, sf::Vector2f pos, sf::Vector2f dimens);
		void update();
		void draw();

		sf::Vector2f dimensions;
};

#endif
