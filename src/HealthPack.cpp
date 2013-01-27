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
		healthPack.LoadFromFile("assets/Health.png");
		loaded = true;
	}
	
	sprite.SetImage(healthPack);
	sprite.SetCenter(healthPack.GetWidth() / 2, healthPack.GetHeight() / 2);
}

void HealthPack::update()
{
	
}

void HealthPack::draw()
{
	sprite.SetPosition(parent->normaliseCoords(position));
	window->Draw(sprite);
}
