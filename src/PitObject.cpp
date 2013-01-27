#include "Game.h"

using namespace sf;

PitObject::PitObject(GameScreen *gs, Vector2f pos, Vector2f dim)
{
	position = pos;
	dimensions = dim;
	parent = gs;
	
	Image img;

	img.LoadFromFile("assets/PitBackground.png");
	images.push_back(img);

	img.LoadFromFile("assets/PitEdgeLeft.png");
	images.push_back(img);
	
	img.LoadFromFile("assets/PitEdgeRight.png");
	images.push_back(img);
}

void PitObject::update()
{
	
}

void PitObject::draw()
{
	sprite.SetImage(images[0]);
	sprite.SetPosition(parent->normaliseCoords(position));
	
	float x = dimensions.x;
	
	while(x > 0.0)
	{
		sprite.SetSubRect(IntRect(0, 0, min(300.0f, x), dimensions.y));
		window->Draw(sprite);
		
		x -= 300.0f;
		sprite.Move(Vector2f(300.0f, 0.0f));
	}
	
	sprite.SetPosition(parent->normaliseCoords(position));
	
	sprite.SetImage(images[1]);
	sprite.Move(Vector2f(-1.0f, 0.0f));
	sprite.SetSubRect(IntRect(0, 0, 100, 100));
	window->Draw(sprite);
	
	sprite.SetImage(images[2]);
	sprite.SetPosition(parent->normaliseCoords(position + dimensions - Vector2f(100.0f, 100.0f)));
	window->Draw(sprite);
}
