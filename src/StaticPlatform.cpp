#include "Game.h"

using namespace sf;

StaticPlatform::StaticPlatform(GameScreen* gs, Vector2f pos, Vector2f dimens)
{
 	parent = gs;
	position = pos;
	dimensions = dimens;
}

void StaticPlatform::update()
{
	//Static it up in here
}

float StaticPlatform::top() 
{
	return position.y;
}

float StaticPlatform::left()
{
	return position.x;
}

float StaticPlatform::right() 
{
	return position.x + dimensions.x;
}

void StaticPlatform::draw()
{
	Shape rect = Shape::Rectangle((position.x - parent->cameraPosition.x), position.y,
								  (position.x - parent->cameraPosition.x) + dimensions.x,
								  position.y + dimensions.y,
								  Color(255, 255, 255, 255));

	window->Draw(rect);
}
