#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"

class GameObject
{
	public:
		virtual ~GameObject() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
		
		sf::Vector2f position;
		sf::Sprite sprite;
		std::vector<sf::Image> images;
};

#endif
