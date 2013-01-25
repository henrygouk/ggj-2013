#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"

class GameObject
{
	public:
		virtual ~GameObject() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
		
		glm::vec2 position;
		sf::Sprite sprite;
};

#endif
