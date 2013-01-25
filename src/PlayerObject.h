#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "Game.h"

class PlayerObject : public GameObject
{
	public:
		PlayerObject(GameScreen* gs, sf::Vector2f pos);
		void update();
		void draw();
		
};

#endif
