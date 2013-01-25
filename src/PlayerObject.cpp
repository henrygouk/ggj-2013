#include "Game.h"

using namespace glm;

PlayerObject::PlayerObject(vec2 pos)
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
