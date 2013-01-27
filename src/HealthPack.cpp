#include "Game.h"

using namespace sf;

PostFX HealthPack::effect;
Image HealthPack::healthPack;
Image HealthPack::uberPack;
bool HealthPack::loaded = false;

HealthPack::HealthPack(GameScreen *gs, Vector2f pos, bool h = true)
{
	position = pos;
	parent = gs;
	health = h;
	remaining = FLT_MAX;
	
	if(!loaded)
	{
		healthPack.LoadFromFile("assets/Health.png");
		uberPack.LoadFromFile("assets/Uber.png");
		effect.LoadFromFile("assets/effect.glsl");
		loaded = true;
	}
	
	sprite.SetImage(h ? healthPack : uberPack);
	sprite.SetCenter(healthPack.GetWidth() / 2, healthPack.GetHeight() / 2);
}

void HealthPack::update()
{
	if(!health)
	{
		remaining -= DELTA_TIME;
		
		if(remaining < 0.0)
		{
			HealthBar::getHealthBar()->changeHealth = true;
			
			for (auto it = parent->gameObjects.begin(); it!=parent->gameObjects.end(); it++) 
			{
				if (*it == this) 
				{
					parent->gameObjects.erase(it);
					delete this;
					return;
				}
			}
		}
	}
}

void HealthPack::draw()
{
	if(remaining > 12.0)
	{
		sprite.SetPosition(parent->normaliseCoords(position));
		window->Draw(sprite);
	}
	else
	{
		effect.SetTexture("framebuffer", NULL);
		window->Draw(effect);
	}
}

