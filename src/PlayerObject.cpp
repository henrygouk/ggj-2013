#include "Game.h"

PlayerObject::PlayerObject(vec3 pos)
{
	position = pos;
}

void PlayerObject::update()
{
	
}

void PlayerObject::draw()
{
	sf::Shape rect = sf::Shape::Rectangle(0, 0, 100, 100, sf::Color(255, 255, 255, 255));
	window->Draw(rect);
}
