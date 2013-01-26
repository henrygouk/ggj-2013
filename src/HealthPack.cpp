#include "Game.h"

using namespace sf;

Image HealthPack::healthPack;
bool HealthPack::loaded = false;

HealthPack::HealthPack(GameScreen *gs, Vector2f pos)
{
	position = pos;
	parent = gs;
	
	if(!loaded)
	{
		healthPack.LoadFromFile("assets/BloodEnd.png");
		loaded = true;
	}
	
	sprite.SetImage(healthPack);
}

void HealthPack::update()
{
	
}

void HealthPack::draw()
{
	sprite.SetPosition(parent->normaliseCoords(position));
	window->Draw(sprite);
}
