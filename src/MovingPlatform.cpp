#include "Game.h"
#define DELTA_TIME (float)window->GetFrameTime()

using namespace sf;

MovingPlatform::MovingPlatform(GameScreen* gs, Vector2f pos, Vector2f dimens, Vector2f dst, float speed)
{
 	parent = gs;
	position = pos;
	start = pos;
	end = dst;
	dimensions = dimens;
	velocity = unit(end - start) * speed;
}

void MovingPlatform::update()
{
	if(dot(velocity, end - position) < 0)
	{
		velocity *= -1.0f;
		swap(start, end);
	}

	position += velocity * DELTA_TIME;
}


void MovingPlatform::draw()
{
	Vector2f topLeft = parent->normaliseCoords(position);
	Vector2f bottomRight = parent->normaliseCoords(position + dimensions);

	Shape rect = Shape::Rectangle(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y,
								  Color(255, 255, 255, 255));

	window->Draw(rect);
}
