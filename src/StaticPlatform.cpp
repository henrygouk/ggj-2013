#include "Game.h"

using namespace sf;

StaticPlatform::StaticPlatform(GameScreen* gs, Vector2f pos, Vector2f dimens)
{
 	parent = gs;
	position = pos;
	dimensions = dimens;
	velocity.x = 0;
	velocity.y = 0;
}

void StaticPlatform::update()
{
	//Static it up in here
}


void StaticPlatform::draw()
{
	Vector2f topLeft = parent->normaliseCoords(position);
	Vector2f bottomRight = parent->normaliseCoords(position + dimensions);

	Shape rect = Shape::Rectangle(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y,
								  Color(255, 255, 255, 255));

	window->Draw(rect);
}
