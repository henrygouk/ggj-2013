#include "Game.h"

using namespace std;
using namespace sf;

BloodSquirt::BloodSquirt(GameScreen *gs, Vector2f pos, float time, bool flip)
{
	parent = gs;
	position = pos;
	
	Image img;
	
	img.LoadFromFile("assets/BloodMain.png");
	images.push_back(img);
	
	img.LoadFromFile("assets/BloodEnd.png");
	images.push_back(img);
	
	sprite.SetImage(images[0]);
	sprite.FlipX(flip);
	timer.Reset();
	
	drawMe = true;
	
	velocity.x = SPEED * (time * 2.0f + 0.5f) * (flip ? 1.0 : -1.0);
}

void BloodSquirt::update()
{
	if(timer.GetElapsedTime() > 0.25f)
	{
		drawMe = false;
	}
	
	position.x += velocity.x * DELTA_TIME;
}

void BloodSquirt::draw()
{
	if(drawMe)
	{
		sprite.SetPosition(parent->normaliseCoords(position));
		window->Draw(sprite);
	}
}
