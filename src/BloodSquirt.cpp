#include "Game.h"

using namespace std;
using namespace sf;

#include <stdlib.h>
#include <time.h>

BloodSquirt::BloodSquirt(GameScreen *gs, Vector2f pos, float time, bool flip)
{
	parent = gs;
	position = pos;
	
	Image img;
	
	img.LoadFromFile("assets/BloodMain.png");
	images.push_back(img);
	
	img.LoadFromFile("assets/BloodEnd.png");
	images.push_back(img);
	
	sprite.SetImage(images[1]);
	sprite.SetScale(1.0f, 0.4f);
	sprite.FlipX(flip);
	timer.Reset();
	
	drawMe = true;
	
	velocity.x = SPEED * (time * 4.0f + 1.0f) * (flip ? 1.0 : -1.0);
}

void BloodSquirt::update()
{
	if(timer.GetElapsedTime() > 0.5f)
	{
		for (auto it = parent->gameObjects.begin(); it!=parent->gameObjects.end(); it++) 
		{
			if (*it == this) 
			{
				parent->gameObjects.erase(it);
				break;
			}
		}

		delete this;
		return;
	}
	
	for (auto it = parent->gameObjects.begin(); it!=parent->gameObjects.end(); it++) 
	{
		Enemy* obj = dynamic_cast<Enemy*>(*it);

		if (!obj) continue;

		if (position.x + 5 < obj->left()) continue;
		if (position.x - 5 > obj->right()) continue;
		if (position.y + 5 < obj->top()) continue;
		if (position.y - 5 > obj->bottom()) continue;

		for (auto it = parent->gameObjects.begin(); it!=parent->gameObjects.end(); it++) 
		{
			if (*it == obj) 
			{
				parent->gameObjects.erase(it);
				break;
			}
		}
		
		for (auto it = parent->gameObjects.begin(); it!=parent->gameObjects.end(); it++) 
		{
			if (*it == this) 
			{
				parent->gameObjects.erase(it);
				break;
			}
		}
	
		for (int i = 0; i < 14; i++) 
		{
			parent->gameObjects.push_back(new BloodFart(parent, NULL, position, 1, i*24, 2.0f));
			parent->gameObjects.push_back(new BloodContact(parent, NULL, Vector2f(obj->position.x+rand()%50-rand()%50, obj->bottom()), rand()%5));
		}

		delete obj;
		delete this;
		return;
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
