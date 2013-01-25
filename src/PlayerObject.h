#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "GameObject.h"

class PlayerObject : public GameObject
{
	public:
		PlayerObject(vec3 pos);
		void update();
		void draw();
};

#endif
