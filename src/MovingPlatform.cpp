#include "Game.h"
#define DELTA_TIME (float)window->GetFrameTime()

using namespace sf;

MovingPlatform::MovingPlatform(GameScreen* gs, Vector2f pos, Vector2f dimens, Vector2f velo)
{
 	parent = gs;
	position = pos;
	dimensions = dimens;
	velocity = velo;
}

void MovingPlatform::update()
{
	position += velocity * DELTA_TIME;
	//Static it up in here
}


void MovingPlatform::draw()
{
	Vector2f topLeft = parent->normaliseCoords(position);
	Vector2f bottomRight = parent->normaliseCoords(position + dimensions);

	Shape rect = Shape::Rectangle(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y,
								  Color(255, 255, 255, 255));

	window->Draw(rect);
}
