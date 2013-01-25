#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "GameObject.h"

class PlayerObject : public GameObject
{
	public:
		void update();
		void draw();
};

#endif
