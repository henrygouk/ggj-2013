#include "Game.h"

using namespace std;
using namespace sf;

#include <sstream>
#include <stdlib.h>
#include <time.h>

#define ASSETS_BASE "BloodEnd"
#define ASSETS_EXT ".png"
#define ANIMATION_IMAGE_COUNT 4
#define ANIMATION_SPEED 2


BloodSquirt::BloodSquirt(GameScreen *gs, Vector2f pos, float time, bool flip)
{
	parent = gs;
	position = pos;
	
	Image img;
	
	imageCount = ANIMATION_IMAGE_COUNT;
	imageIndex = 0;
	imageAnimationSwitch = 0.05;
	imageAnimationPos = 0.0;
	imageAnimationSpeed = ANIMATION_SPEED;
	
	for(int i = 1; i <= imageCount; i++) 
	{
		stringstream ss (stringstream::in | stringstream::out);
		ss << ASSETS_FOLDER << ASSETS_BASE << i << ASSETS_EXT;

		img.LoadFromFile(ss.str());
		images.push_back(img);
	}
	
	sprite.SetImage(images[imageIndex]);
	sprite.SetCenter(images[imageIndex].GetWidth() / 2, images[imageIndex].GetHeight());
	
	sprite.SetScale(1.0f, 0.4f);
	sprite.FlipX(!flip);
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
	
		parent->gameObjects.push_back(new DeathAnimation(parent, obj->position));

		
		/*for (int i = 0; i < 14; i++) 
		{
			parent->gameObjects.push_back(new BloodFart(parent, NULL, position, 1, i*24, 2.0f));
			parent->gameObjects.push_back(new BloodContact(parent, NULL, Vector2f(obj->position.x+rand()%50-rand()%50, obj->bottom()), rand()%5));
		}*/


		delete obj;
		delete this;
		return;
	}

	imageAnimationPos += imageAnimationSpeed * DELTA_TIME;

	if (imageAnimationPos > imageAnimationSwitch) 
	{
		imageAnimationPos = 0;
		if (imageIndex++ >= imageCount-1) imageIndex = 0;
	}
	
	position.x += velocity.x * DELTA_TIME;
}

void BloodSquirt::draw()
{
	if(drawMe)
	{
		Vector2f pos2 = position;
		pos2.y += 9;

		sprite.SetImage(images[imageIndex]);
		sprite.SetPosition(parent->normaliseCoords(pos2));
		window->Draw(sprite);
	}
}
