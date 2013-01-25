#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "Game.h"

class PlayerObject : public GameObject
{
	public:
		PlayerObject(glm::vec2 pos);
		void update();
		void draw();
};

#endif
