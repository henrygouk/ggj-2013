#include "Game.h"

using namespace sf;

StaticPlatform::StaticPlatform(Vector2f pos, Vector2f dimens)
{
	position = pos;
	dimensions = dimens;
}

void StaticPlatform::update()
{
	//Static it up in here
}

void StaticPlatform::draw()
{
	Shape rect = Shape::Rectangle(position.x, position.y,
								  position.x + dimensions.x,
								  position.y + dimensions.y,
								  Color(255, 255, 255, 255));

	window->Draw(rect);
}
