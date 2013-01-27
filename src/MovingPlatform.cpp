#include "Game.h"
#define DELTA_TIME (float)window->GetFrameTime()

using namespace sf;

MovingPlatform::MovingPlatform(GameScreen* gs, Vector2f pos, Vector2f dimens, Vector2f dst, float speed, string filename)
{
 	parent = gs;
	position = pos;
	start = pos;
	end = dst;
	velocity = unit(end - start) * speed;
	
	Image img;
	img.LoadFromFile(filename);
	images.push_back(img);
	
	sprite.SetImage(images[0]);
	sprite.SetCenter(dimens);
	dimensions = Vector2f(img.GetWidth(), img.GetHeight());
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
	sprite.SetPosition(topLeft);
	window->Draw(sprite);
}
