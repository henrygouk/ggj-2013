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
	Shape rect = Shape::Rectangle((position.x - parent->cameraPosition.x), position.y,
								  (position.x - parent->cameraPosition.x) + dimensions.x,
								  position.y + dimensions.y,
								  Color(255, 255, 255, 255));

	window->Draw(rect);
}
